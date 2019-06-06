#include <unordered_set>

struct Address {
    std::string city, street;
    int building;

    bool operator == (const Address& other) const {
        return std::tie(city, street, building) == std::tie(other.city, other.street, other.building);
    }
};

struct Person {
    std::string name;
    int height;
    double weight;
    Address address;

    bool operator == (const Person& other) const {
        return std::tie(name, height, weight, address) == std::tie(other.name, other.height, other.weight, other.address);
    }
};

struct AddressHasher {
    size_t operator () (const Address& address) const {
        auto x = 14;
        return sHasher(address.city) * x * x + sHasher(address.street) * x + iHasher(address.building);
    }

    std::hash<std::string> sHasher;
    std::hash<int> iHasher;
};

struct PersonHasher {
    size_t operator () (const Person& person) const {
        auto x = 18;
        return sHasher(person.name) * x * x * x + iHasher(person.height) * x * x + dHasher(person.weight) * x + aHasher(person.address);
    }

    std::hash<std::string> sHasher;
    std::hash<int> iHasher;
    std::hash<double> dHasher;
    AddressHasher aHasher;
};