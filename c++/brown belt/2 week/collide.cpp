#include "geo2d.h"
#include "game_object.h"

#include "test_runner.h"

#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct Collider : GameObject {
    bool Collide(const GameObject& that) const final {
        return that.CollideWith(static_cast<const T&>(*this));
    };
};

class Unit : public Collider<Unit> {
public:
    explicit Unit(geo2d::Point position);

    bool CollideWith(const Unit& that) const override;
    bool CollideWith(const Building& that) const override;
    bool CollideWith(const Tower& that) const override;
    bool CollideWith(const Fence& that) const override;

    const geo2d::Point getPosition() const;
private:
    const geo2d::Point _position;
};

class Building : public Collider<Building> {
public:
    explicit Building(geo2d::Rectangle geometry);

    bool CollideWith(const Unit& that) const override;
    bool CollideWith(const Building& that) const override;
    bool CollideWith(const Tower& that) const override;
    bool CollideWith(const Fence& that) const override;

    const geo2d::Rectangle getGeometry() const;
private:
    const geo2d::Rectangle _geometry;
};

class Tower : public Collider<Tower> {
public:
    explicit Tower(geo2d::Circle geometry);

    bool CollideWith(const Unit& that) const override;
    bool CollideWith(const Building& that) const override;
    bool CollideWith(const Tower& that) const override;
    bool CollideWith(const Fence& that) const override;

    const geo2d::Circle getGeometry() const;
private:
    const geo2d::Circle _geometry;
};

class Fence : public Collider<Fence> {
public:
    explicit Fence(geo2d::Segment geometry);

    bool CollideWith(const Unit& that) const override;
    bool CollideWith(const Building& that) const override;
    bool CollideWith(const Tower& that) const override;
    bool CollideWith(const Fence& that) const override;

    const geo2d::Segment getGeometry() const;
private:
    const geo2d::Segment _geometry;
};

Unit::Unit(geo2d::Point position)
        : _position(position) {}

bool Unit::CollideWith(const Unit& that) const {
    return geo2d::Collide(getPosition(), that.getPosition());
}

bool Unit::CollideWith(const Building& that) const {
    return geo2d::Collide(getPosition(), that.getGeometry());
}

bool Unit::CollideWith(const Tower& that) const {
    return geo2d::Collide(getPosition(), that.getGeometry());
}

bool Unit::CollideWith(const Fence& that) const {
    return geo2d::Collide(getPosition(), that.getGeometry());
}

const geo2d::Point Unit::getPosition() const {
    return _position;
}



Building::Building(geo2d::Rectangle geometry)
        : _geometry(geometry) {};

bool Building::CollideWith(const Unit& that) const {
    return geo2d::Collide(getGeometry(), that.getPosition());
}

bool Building::CollideWith(const Building& that) const {
    return geo2d::Collide(getGeometry(), that.getGeometry());
}

bool Building::CollideWith(const Tower& that) const {
    return geo2d::Collide(getGeometry(), that.getGeometry());
}

bool Building::CollideWith(const Fence& that) const {
    return geo2d::Collide(getGeometry(), that.getGeometry());
}

const geo2d::Rectangle Building::getGeometry() const {
    return _geometry;
}



Tower::Tower(geo2d::Circle geometry)
        : _geometry(geometry) {};

bool Tower::CollideWith(const Unit& that) const {
    return geo2d::Collide(getGeometry(), that.getPosition());
}

bool Tower::CollideWith(const Building& that) const {
    return geo2d::Collide(getGeometry(), that.getGeometry());
}

bool Tower::CollideWith(const Tower& that) const {
    return geo2d::Collide(getGeometry(), that.getGeometry());
}

bool Tower::CollideWith(const Fence& that) const {
    return geo2d::Collide(getGeometry(), that.getGeometry());
}

const geo2d::Circle Tower::getGeometry() const {
    return _geometry;
}



Fence::Fence(geo2d::Segment geometry)
        : _geometry(geometry) {};

bool Fence::CollideWith(const Unit& that) const {
    return geo2d::Collide(getGeometry(), that.getPosition());
}

bool Fence::CollideWith(const Building& that) const {
    return geo2d::Collide(getGeometry(), that.getGeometry());
}

bool Fence::CollideWith(const Tower& that) const {
    return geo2d::Collide(getGeometry(), that.getGeometry());
}

bool Fence::CollideWith(const Fence& that) const {
    return geo2d::Collide(getGeometry(), that.getGeometry());
}

const geo2d::Segment Fence::getGeometry() const {
    return _geometry;
}



bool Collide(const GameObject& first, const GameObject& second) {
    return first.Collide(second);
}