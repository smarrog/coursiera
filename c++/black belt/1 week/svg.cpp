#include <string>
#include <vector>
#include <ostream>
#include <memory>

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

    class Color {
    public:
        Color(const Rgb& rgb)
                : Color(std::string("rgb(") + std::to_string(rgb.red) + ',' + std::to_string(rgb.green) + ',' + std::to_string(rgb.blue) + ')') { };

        Color(std::string s = "none")
                : _value(std::move(s)) { }

        Color(const char* s)
                : Color(std::string(s)) {}

        const std::string& toString() const {
            return _value;
        }
    private:
        std::string _value;
    };

    const Color NoneColor = Color(std::string("none"));

    std::ostream& operator << (std::ostream& os, const Point& p) {
        return os << p.x << ',' << p.y;
    }

    std::ostream& operator << (std::ostream& os, const Color& c) {
        return os << c.toString();
    }

    // FIGURES

    template <typename Owner>
    class CommonProperties {
    public:
        virtual Owner& SetFillColor(const Color& color) {
            _fillColor = color;
            return AsOwner();
        }

        virtual Owner& SetStrokeColor(const Color& color) {
            _strokeColor = color;
            return AsOwner();
        }

        virtual Owner& SetStrokeWidth(double value) {
            _strokeWidth = value;
            return AsOwner();
        }

        virtual Owner& SetStrokeLineCap(const std::string& value) {
            _strokeLineCap = value;
            return AsOwner();
        }

        virtual Owner& SetStrokeLineJoin(const std::string& value) {
            _strokeLineJoin = value;
            return AsOwner();
        }

        void RenderCommon(std::ostream& os) const {
            RenderField(os, "fill", _fillColor);
            RenderField(os, "stroke", _strokeColor);
            RenderField(os, "stroke-width", _strokeWidth);
            if (!_strokeLineCap.empty()) {
                RenderField(os, "stroke-linecap", _strokeLineCap);
            }
            if (!_strokeLineJoin.empty()) {
                RenderField(os, "stroke-linejoin", _strokeLineJoin);
            }
        }

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

        Owner& AsOwner() {
            return static_cast<Owner&>(*this);
        }
    };

    class Figure {
    public:
        virtual ~Figure() = default;
        virtual void Render(std::ostream& os) const = 0;
    };

    class Circle : public Figure, public CommonProperties<Circle> {
    public:
        Circle& SetCenter(Point point) {
            _center = std::move(point);
            return *this;
        }

        Circle& SetRadius(double value) {
            _r = value;
            return *this;
        }

        void Render(std::ostream& os) const override {
            os << "<circle";
            RenderCommon(os);
            RenderField(os, "cx", _center.x);
            RenderField(os, "cy", _center.y);
            RenderField(os, "r", _r);
            os << " />";
        }

    private:
        Point _center;
        double _r = 1.0;
    };


    class Polyline : public Figure, public CommonProperties<Polyline> {
    public:
        Polyline& AddPoint(Point point) {
            _points.emplace_back(point.x, point.y);
            return *this;
        }

        void Render(std::ostream& os) const override {
            os << "<polyline";
            RenderCommon(os);
            os << " points=\"";
            auto isFirst = true;
            for (const auto& point : _points) {
                if (!isFirst) {
                    os << ' ';
                }
                isFirst = false;
                os << point;
            }
            os << "\" />";
        }

    private:
        std::vector<Point> _points;
    };


    class Text : public Figure, public CommonProperties<Text> {
    public:
        Text& SetPoint(Point point) {
            _coords = point;
            return *this;
        }

        Text& SetOffset(Point point) {
            _offset = point;
            return *this;
        }

        Text& SetFontSize(uint32_t value) {
            _size = value;
            return *this;
        }

        Text& SetFontFamily(const std::string& value) {
            _family = value;
            return *this;
        }

        Text& SetData(const std::string& value) {
            _data = value;
            return *this;
        }

        void Render(std::ostream& os) const override {
            os << "<text";
            RenderCommon(os);
            RenderField(os, "x", _coords.x);
            RenderField(os, "y", _coords.y);
            RenderField(os, "dx", _offset.x);
            RenderField(os, "dy", _offset.y);
            RenderField(os, "font-size", _size);
            if (!_family.empty()) {
                RenderField(os, "font-family", _family);
            }
            os << " >";
            os << _data;
            os << "</text>";
        }

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
        template <typename T>
        Document& Add(T figure) {
            _data.push_back(std::make_unique<T>(std::move(figure)));
            return *this;
        }

        void Render(std::ostream& os) {
            os << R"(<?xml version="1.0" encoding="UTF-8" ?><svg xmlns="http://www.w3.org/2000/svg" version="1.1">)";
            for (const auto& elem : _data) {
                os << '\n';
                elem->Render(os);
            }
            os << '\n';
            os << "</svg>";
        }

    private:
        std::vector<std::unique_ptr<Figure>> _data;
    };
}