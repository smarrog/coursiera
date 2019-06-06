#include "test_runner.h"

#include <cstddef>  // нужно для nullptr_t

using namespace std;

// Реализуйте шаблон класса UniquePtr
template <typename T>
class UniquePtr {
public:
    UniquePtr()
        : _ptr(nullptr) { }

    explicit UniquePtr(T* ptr)
        : _ptr(ptr) { }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other) noexcept : _ptr(other._ptr) {
        other._ptr = nullptr;
    }

    UniquePtr& operator = (nullptr_t) {
        Reset(nullptr);
        return *this;
    }

    UniquePtr& operator = (const UniquePtr&) = delete;
    UniquePtr& operator = (UniquePtr&& other) noexcept {
        if (&other != this) {
            Reset(other._ptr);
            other._ptr = nullptr;
        }
        return *this;
    }

    ~UniquePtr() {
        delete _ptr;
    }

    T& operator * () const {
        return *_ptr;
    }

    T* operator -> () const {
        return _ptr;
    }

    T* Release() {
        auto copy = _ptr;
        _ptr = nullptr;
        return copy;
    }

    void Reset(T* ptr) {
        if (ptr != _ptr) {
            delete _ptr;
            _ptr = ptr;
        }
    }

    void Swap(UniquePtr& other) {
        if (&other != this) {
            std::swap(_ptr, other._ptr);
        }
    }

    T* Get() const {
        return _ptr;
    }
private:
    T* _ptr;
};


struct Item {
    static int counter;
    int value;
    explicit Item(int v = 0): value(v) {
        ++counter;
    }
    Item(const Item& other): value(other.value) {
        ++counter;
    }
    ~Item() {
        --counter;
    }
};

int Item::counter = 0;


void TestLifetime() {
    Item::counter = 0;
    {
        UniquePtr<Item> ptr(new Item);
        ASSERT_EQUAL(Item::counter, 1);

        ptr.Reset(new Item);
        ASSERT_EQUAL(Item::counter, 1);
    }
    ASSERT_EQUAL(Item::counter, 0);

    {
        UniquePtr<Item> ptr(new Item);
        ASSERT_EQUAL(Item::counter, 1);

        auto rawPtr = ptr.Release();
        ASSERT_EQUAL(Item::counter, 1);

        delete rawPtr;
        ASSERT_EQUAL(Item::counter, 0);
    }
    ASSERT_EQUAL(Item::counter, 0);
}

void TestGetters() {
    UniquePtr<Item> ptr(new Item(42));
    ASSERT_EQUAL(ptr.Get()->value, 42);
    ASSERT_EQUAL((*ptr).value, 42);
    ASSERT_EQUAL(ptr->value, 42);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestLifetime);
    RUN_TEST(tr, TestGetters);
}
