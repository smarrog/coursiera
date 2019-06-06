#include <unordered_set>

using namespace std;

using CoordType = int;

struct Point3D {
    CoordType x;
    CoordType y;
    CoordType z;

    bool operator == (const Point3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

struct Hasher {
    size_t operator () (const Point3D& point) const {
        return point.x * 1'0000'0000 + point.y * 1'000 + point.z;
    }
};