#include <cstddef>
#include <memory>
#include <utility>

template <typename T>
class RawMemory {
private:
    static T* allocate(size_t n) {
        return static_cast<T*>(operator new (n * sizeof(T)));
    }

    static void deallocate(T* buf) {
        operator delete(buf);
    }
public:
    RawMemory() = default;
    explicit RawMemory(size_t n) : _buf(allocate(n)), _capacity(n) { }
    RawMemory(const RawMemory&) = delete;
    RawMemory(RawMemory&& other) noexcept { swap(other); }

    ~RawMemory() { deallocate(_buf); }

    RawMemory& operator = (const RawMemory&) = delete;
    RawMemory& operator = (RawMemory&& other) noexcept { swap(other); return *this; }

    void swap(RawMemory& other) {
        std::swap(_buf, other._buf);
        std::swap(_capacity, other._capacity);
    }

    size_t getCapacity() const { return _capacity; }

    T* operator + (size_t i) { return _buf + i; }
    const T* operator + (size_t i) const { return _buf + i; }
    T& operator [] (size_t i) { return _buf[i]; }
    const T& operator [] (size_t i) const { return _buf[i]; }
    T* operator * () { return _buf; }
    const T* operator * () const { return _buf; }
private:
    T* _buf = nullptr;
    size_t _capacity = 0;
};

template <typename T>
class Vector {
public:
    using iterator = T*;
    using const_iterator = const T*;

    Vector() = default;

    explicit Vector(size_t n) : _data(n) {
        std::uninitialized_value_construct_n(*_data, n);
        _size = n;
    }

    Vector(const Vector& other) : _data(other._size) {
        std::uninitialized_copy_n(*other._data, other._size, *_data);
        _size = other._size;
    }

    Vector(Vector&& other) noexcept {
        swap(other);
    }

    ~Vector() {
        std::destroy_n(*_data, _size);
    }

    Vector& operator = (const Vector& other) {
        if (other._size > Capacity()) {
            Vector tmp(other);
            swap(tmp);
            return *this;
        }
        for (auto i = 0; i < other._size; i++) {
            _data[i] = other._data[i];
        }
        if (_size < other._size) {
            std::uninitialized_copy_n(*other._data, other._size - _size, _data + _size);
        } else if (_size > other._size) {
            std::destroy_n(_data + other._size, _size - other._size);
        }
        _size = other._size;
        return *this;
    }

    Vector& operator = (Vector&& other) noexcept {
        swap(other);
        return *this;
    }

    void Reserve(size_t n) {
        if (n <= _data.getCapacity()) {
            return;
        }
        RawMemory<T> newData(n);
        std::uninitialized_move_n(*_data, _size, *newData);
        std::destroy_n(*_data, _size);
        _data = std::move(newData);
    }

    void Resize(size_t n) {
        Reserve(n);
        if (n > _size) {
            std::uninitialized_value_construct_n(_data + _size, n - _size);
        } else if (n < _size) {
            std::destroy_n(_data + n, _size - n);
        }
        _size = n;
    }

    void PushBack(const T& elem) {
        expandIfFull();
        new (_data + _size) T(elem);
        _size++;
    }

    void PushBack(T&& elem) {
        expandIfFull();
        new (_data + _size) T(std::move(elem));
        _size++;
    }

    template <typename ... Args>
    T& EmplaceBack(Args&&... args) {
        expandIfFull();
        auto elem = new (_data + _size) T(std::forward<Args>(args)...);
        _size++;
        return *elem;
    }

    void PopBack() {
        std::destroy(_data + _size - 1, _data + _size);
        _size--;
    }


    size_t Size() const noexcept { return _size; }
    size_t Capacity() const noexcept { return _data.getCapacity(); }

    const T& operator[](size_t i) const { return _data[i]; }
    T& operator[](size_t i) { return _data[i]; }


    iterator begin() noexcept { return *_data; }
    iterator end() noexcept { return _data + _size; }
    const_iterator begin() const noexcept { return *_data; }
    const_iterator end() const noexcept { return _data + _size; }
    const_iterator cbegin() const noexcept { return *_data; }
    const_iterator cend() const noexcept { return _data + _size; }

    iterator Insert(const_iterator pos, const T& elem) {
        auto posIndex = pos - *_data;
        expandIfFull();
        for (int i = _size - 1; i >= posIndex; i--) {
            std::uninitialized_move_n(_data + i, 1, _data + i + 1);
        }
        auto it = new (_data + posIndex) T(elem);
        _size++;
        return it;
    }

    iterator Insert(const_iterator pos, T&& elem) {
        auto posIndex = pos - *_data;
        expandIfFull();
        for (int i = _size - 1; i >= posIndex; i--) {
            std::uninitialized_move_n(_data + i, 1, _data + i + 1);
        }
        auto it = new (_data + posIndex) T(std::move(elem));
        _size++;
        return it;
    }

    template <typename ... Args>
    iterator Emplace(const_iterator pos, Args&&... args) {
        auto posIndex = pos - *_data;
        expandIfFull();
        for (int i = _size - 1; i >= posIndex; i--) {
            std::uninitialized_move_n(_data + i, 1, _data + i + 1);
        }
        auto it = new (_data + posIndex) T(std::forward<Args>(args)...);
        _size++;
        return it;
    }

    iterator Erase(const_iterator pos) {
        auto posIndex = pos - *_data;
        for (auto i = posIndex; i < _size - 1; i++) {
            std::uninitialized_move_n(_data + i + 1, 1, _data + i);
        }
        PopBack();
        return _data + posIndex;
    }

private:
    static void construct(void* buf) {
        new (buf) T;
    }

    static void construct(void* buf, const T& elem) {
        new (buf) T(elem);
    }

    static void destroy(T* buf) {
        buf->~T();
    }

    RawMemory<T> _data;
    size_t _size = 0;

    inline void expandIfFull() {
        if (_size == Capacity()) {
            Reserve(_size == 0 ? 1 : _size * 2);
        }
    }

    void swap(Vector& other) {
        std::swap(_data, other._data);
        std::swap(_size, other._size);
    }
};
