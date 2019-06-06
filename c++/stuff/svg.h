#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <memory>
#include <variant>

namespace Svg {
    // HELPERS

    struct Point {
        double x = 0;
        double y = 0;

        Point(double x = 0, double y = 0) : x(x), y(y) {}
    };

    struct Rgb {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    };

    struct Rgba {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        double alpha;
    };

    class Color {
    public:
        Color() : _v(std::monostate()) {}
        Color(const Rgb& rgb) : _v(rgb) {}
        Color(const Rgba& rgba) : _v(rgba) {}
        Color(std::string s) : _v(std::move(s)) {}
        Color(const char* s) : Color(std::string(s)) {}

        const std::string toString() const;
    private:
        std::variant<std::monostate, Rgb, Rgba, std::string> _v;
    };

    const Color NoneColor = Color();

    std::ostream& operator << (std::ostream&, const Point&);
    std::ostream& operator << (std::ostream&, const Color&);

    // FIGURES

    template <typename Owner>
    class CommonProperties {
    public:
        virtual Owner& SetFillColor(const Color& color);
        virtual Owner& SetStrokeColor(const Color& color);
        virtual Owner& SetStrokeWidth(double value);
        virtual Owner& SetStrokeLineCap(const std::string& value);
        virtual Owner& SetStrokeLineJoin(const std::string& value);

        void RenderCommon(std::ostream& os) const;
    protected:
        template <typename Q>
        void RenderField(std::ostream& os, const std::string& prop, const Q& value) const {
            os << ' ' << prop << "=\"" << value << '"';
        }

    private:
        Color _fillColor;
        Color _strokeColor;
        double _strokeWidth = 1.0;
        std::string _strokeLineCap;
        std::string _strokeLineJoin;

        Owner& AsOwner();
    };

    class Figure {
    public:
        virtual ~Figure() = default;
        virtual void Render(std::ostream& os) const = 0;
    };

    class Circle : public Figure, public CommonProperties<Circle> {
    public:
        Circle& SetCenter(Point point);
        Circle& SetRadius(double value);

        void Render(std::ostream& os) const override;

    private:
        Point _center;
        double _r = 1.0;
    };

    class Polyline : public Figure, public CommonProperties<Polyline> {
    public:
        Polyline& AddPoint(Point point);

        void Render(std::ostream& os) const override;

    private:
        std::vector<Point> _points;
    };

    class Text : public Figure, public CommonProperties<Text> {
    public:
        Text& SetPoint(Point point);
        Text& SetOffset(Point point);
        Text& SetFontSize(uint32_t value);
        Text& SetFontFamily(const std::string& value);
        Text& SetData(const std::string& value);

        void Render(std::ostream& os) const override;

    private:
        Point _coords;
        Point _offset;
        uint32_t _size = 1;
        std::string _family;
        std::string _data;
    };

    // DOCUMENT

    class Document {
    public:
        template<typename T>
        Document& Add(T figure) {
            _data.push_back(std::make_unique<T>(std::move(figure)));
            return *this;
        }

        void Render(std::ostream& os);

    private:
        std::vector<std::unique_ptr<Figure>> _data;
    };
}