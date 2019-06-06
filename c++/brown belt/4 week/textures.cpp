#include "Common.h"

using namespace std;

class Geometry : public IShape {
public:
    explicit Geometry(ShapeType shapeType)
        : _shapeType(shapeType)
        , _position({0, 0})
        , _size({0, 0}) {}

    std::unique_ptr<IShape> Clone() const override {
        auto ptr = MakeShape(_shapeType);
        ptr->SetPosition(_position);
        ptr->SetSize(_size);
        ptr->SetTexture(_texturePt);
        return std::move(ptr);
    }

    void SetPosition(Point value) override {
        _position = value;
    }

    Point GetPosition() const override {
        return _position;
    }

    void SetSize(Size value) override {
        _size = value;
    }

    Size GetSize() const override {
        return _size;
    }

    void SetTexture(std::shared_ptr<ITexture> texturePt) override {
        _texturePt = std::move(texturePt);
    }

    ITexture* GetTexture() const override {
        return _texturePt != nullptr ? _texturePt.get() : nullptr;
    }

    void Draw(Image& image) const override {
        for (auto y = 0; y < _size.height && y + _position.y < image.size(); y++) {
            for (auto x = 0; x < _size.width && x + _position.x < image[y].size(); x++) {
                if (isInFigure(x, y)) {
                    image[y + _position.y][x + _position.x] = getPixel(x, y);
                }
            }
        }
    }
protected:
    virtual bool isInFigure(int x, int y) const = 0;

private:
    ShapeType _shapeType;
    Point _position;
    Size _size;
    std::shared_ptr<ITexture> _texturePt;

    char getPixel(int x, int y) const {
        if (_texturePt == nullptr || x >= _texturePt->GetSize().width || y >= _texturePt->GetSize().height) {
            return '.';
        }
        return _texturePt->GetImage()[y][x];
    }
};

class Ellipse : public Geometry {
public:
    Ellipse()
        : Geometry(ShapeType::Ellipse) {};

protected:
    bool isInFigure(int x, int y) const override {
        return IsPointInEllipse({x, y}, GetSize());
    }
};

class Rectangle : public Geometry {
public:
    Rectangle()
        : Geometry(ShapeType::Rectangle) {};

protected:
    bool isInFigure(int x, int y) const override {
        return true;
    }
};

std::unique_ptr<IShape> MakeShape(ShapeType shapeType) {
    switch (shapeType) {
        case ShapeType::Ellipse:
            return std::make_unique<Ellipse>();
        case ShapeType::Rectangle:
            return std::make_unique<Rectangle>();
        default:
            throw std::runtime_error("Unknown shape type");
    }
}