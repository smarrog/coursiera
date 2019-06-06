#include "svg.h"

using namespace Svg;

namespace Svg {
    std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << p.x << ',' << p.y;
    }

    std::ostream& operator<<(std::ostream& os, const Color& c) {
        return os << c.toString();
    }
}

const std::string Color::toString() const {
    if (std::holds_alternative<Rgba>(_v)) {
        auto rgba = std::get<Rgba>(_v);
        return "rgba(" +
               std::to_string(rgba.red) + "," +
               std::to_string(rgba.green) + "," +
               std::to_string(rgba.blue) + "," +
               std::to_string(rgba.alpha) + ")";
    }
    if (std::holds_alternative<Rgb>(_v)) {
        auto rgb = std::get<Rgb>(_v);
        return "rgb(" +
               std::to_string(rgb.red) + "," +
               std::to_string(rgb.green) + "," +
               std::to_string(rgb.blue) + ")";
    }
    if (std::holds_alternative<std::string>(_v)) {
        return std::get<std::string>(_v);
    }
    return "none";
}

// CommonProperties

template<typename Owner>
Owner& CommonProperties<Owner>::SetFillColor(const Color& color) {
    _fillColor = color;
    return AsOwner();
}

template<typename Owner>
Owner& CommonProperties<Owner>::SetStrokeColor(const Color& color) {
    _strokeColor = color;
    return AsOwner();
}

template<typename Owner>
Owner& CommonProperties<Owner>::SetStrokeWidth(double value) {
    _strokeWidth = value;
    return AsOwner();
}

template<typename Owner>
Owner& CommonProperties<Owner>::SetStrokeLineCap(const std::string& value) {
    _strokeLineCap = value;
    return AsOwner();
}

template<typename Owner>
Owner& CommonProperties<Owner>::SetStrokeLineJoin(const std::string& value) {
    _strokeLineJoin = value;
    return AsOwner();
}

template<typename Owner>
void CommonProperties<Owner>::RenderCommon(std::ostream& os) const {
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

template<typename Owner>
Owner& CommonProperties<Owner>::AsOwner() {
    return static_cast<Owner&>(*this);
}

// Circle

Circle& Circle::SetCenter(Point point) {
    _center = std::move(point);
    return *this;
}

Circle& Circle::SetRadius(double value) {
    _r = value;
    return *this;
}

void Circle::Render(std::ostream& os) const {
    os << "<circle";
    RenderCommon(os);
    RenderField(os, "cx", _center.x);
    RenderField(os, "cy", _center.y);
    RenderField(os, "r", _r);
    os << " />";
}

// Polyline

Polyline& Polyline::AddPoint(Point point) {
    _points.emplace_back(point.x, point.y);
    return *this;
}

void Polyline::Render(std::ostream& os) const {
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

// Text

Text& Text::SetPoint(Point point) {
    _coords = point;
    return *this;
}

Text& Text::SetOffset(Point point) {
    _offset = point;
    return *this;
}

Text& Text::SetFontSize(uint32_t value) {
    _size = value;
    return *this;
}

Text& Text::SetFontFamily(const std::string& value) {
    _family = value;
    return *this;
}

Text& Text::SetData(const std::string& value) {
    _data = value;
    return *this;
}

void Text::Render(std::ostream& os) const {
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

// Document

void Document::Render(std::ostream& os) {
    os << R"(<?xml version="1.0" encoding="UTF-8" ?><svg xmlns="http://www.w3.org/2000/svg" version="1.1">)";
    for (const auto& elem : _data) {
        elem->Render(os);
    }
    os << "</svg>";
}

