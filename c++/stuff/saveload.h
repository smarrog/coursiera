#include <map>
#include <iostream>
#include <string>
#include <vector>

// Serialization

template <typename T>
void Serialize(T pod, std::ostream& out);

void SerializeSize(size_t pod, std::ostream& out);

void Serialize(const std::string& str, std::ostream& out);

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out);

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out);

// Deserialization

template <typename T>
void Deserialize(std::istream& in, T& pod);

void DeserializeSize(std::istream& in, size_t& pod);

void Deserialize(std::istream& in, std::string& str);

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data);

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data);

// Implementation

template <typename T>
void Serialize(T pod, std::ostream& out) {
    out.write(reinterpret_cast<char*>(&pod), sizeof(pod));
}

void SerializeSize(size_t pod, std::ostream& out) {
    Serialize(static_cast<unsigned long long>(pod), out);
}

void Serialize(const std::string& str, std::ostream& out) {
    SerializeSize(str.size(), out);
    out.write(str.c_str(), str.size());
}

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out) {
    SerializeSize(data.size(), out);
    for (const auto& elem : data) {
        Serialize(elem, out);
    }
}

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out) {
    SerializeSize(data.size(), out);
    for (const auto& [ key, value ] : data) {
        Serialize(key, out);
        Serialize(value, out);
    }
}

template <typename T>
void Deserialize(std::istream& in, T& pod) {
    in.read(reinterpret_cast<char*>(&pod), sizeof(pod));
}

void DeserializeSize(std::istream& in, size_t& pod) {
    auto value = 0ull;
    Deserialize(in, value);
    pod = static_cast<size_t>(value);
}

void Deserialize(std::istream& in, std::string& str) {
    size_t size;
    DeserializeSize(in, size);
    str.resize(size, ' ');
    in.read(str.data(), size);
}



template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data) {
    size_t size;
    DeserializeSize(in, size);
    data.resize(size);
    for (auto i = 0; i < size; i++) {
        T elem;
        Deserialize(in, elem);
        data[i] = elem;
    }
}

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data) {
    size_t size;
    DeserializeSize(in, size);
    for (auto i = 0; i < size; i++) {
        T1 key;
        T2 value;
        Deserialize(in, key);
        Deserialize(in, value);
        data[key] = value;
    }
}

