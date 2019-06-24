#include "stdexcept"

// Исключение этого типа должно генерироваться при обращении к "пустому" Optional в функции Value
struct BadOptionalAccess : std::exception {
};

template<typename T>
class Optional {
public:
    Optional() = default;

    Optional(const T& elem) {
        SetValue(elem);
    }

    Optional(T&& elem) {
        SetValue(std::move(elem));
    }

    Optional(const Optional& other) {
        if (other.HasValue()) {
            SetValue(*other);
        }
    }

    Optional(Optional&& other) noexcept {
        if (other.HasValue()) {
            SetValue(std::move(*other));
        }
    }

    Optional& operator = (const T& elem) {
        SetValue(elem);
        return *this;
    }

    Optional& operator = (T&& elem) {
        SetValue(std::move(elem));
        return *this;
    }

    Optional& operator = (const Optional& other) {
        if (other.HasValue()) {
            SetValue(*other);
        } else {
            Reset();
        }
        return *this;
    }

    Optional& operator = (Optional&& other) noexcept {
        if (other.HasValue()) {
            SetValue(std::move(*other));
        } else {
            Reset();
        }
        return *this;
    }

    bool HasValue() const {
        return _defined;
    }

    // Эти операторы не должны делать никаких проверок на пустоту.
    // Проверки остаются на совести программиста.
    T& operator * () { return *getValue(); }
    const T& operator * () const { return *getValue(); }
    T* operator -> () { return getValue(); }
    const T* operator -> () const { return getValue(); }

    // Генерирует исключение BadOptionalAccess, если объекта нет
    T& Value() {
        if (!HasValue()) {
            throw BadOptionalAccess{};
        }
        return *getValue();
    }

    const T& Value() const {
        if (!HasValue()) {
            throw BadOptionalAccess{};
        }
        return *getValue();
    }

    void Reset() {
        if (HasValue()) {
            getValue()->~T();
            _defined = false;
        }
    }

    ~Optional() {
        Reset();
    }

private:
    // alignas нужен для правильного выравнивания блока памяти
    alignas(T) unsigned char _data[sizeof(T)];
    bool _defined = false;

    inline void SetValue(const T& elem) {
        if (HasValue()) {
            Value() = elem;
        } else {
            _defined = true;
            new (_data) T(elem);
        }
    }

    inline void SetValue(T&& elem) {
        if (HasValue()) {
            Value() = elem;
        } else {
            _defined = true;
            new (_data) T(std::move(elem));
        }
    }

    T* getValue() { return reinterpret_cast<T*>(_data); }
    const T* getValue() const { return reinterpret_cast<const T*>(_data); }
};
