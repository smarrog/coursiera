#include "test_runner.h"

#include <functional>
#include <string>
using namespace std;

template <typename T>
class LazyValue {
public:
    explicit LazyValue(std::function<T()> init)
        : _initFunc(std::move(init))
        , _helperPt(nullptr) { }

    ~LazyValue() {
        if (HasValue()) {
            delete _helperPt;
        }
    }

    bool HasValue() const {
        return _helperPt != nullptr;
    }

    const T& Get() const {
        if (!HasValue()) {
            _helperPt = new Helper(_initFunc());
        }
        return _helperPt->value;
    }

private:
    struct Helper {
        explicit Helper(T value)
            : value(std::move(value)) {};

        T value;
    };

    std::function<T()> _initFunc;
    mutable Helper* _helperPt;
};

void UseExample() {
    const string big_string = "Giant amounts of memory";

    LazyValue<string> lazy_string([&big_string] { return big_string; });

    ASSERT(!lazy_string.HasValue());
    ASSERT_EQUAL(lazy_string.Get(), big_string);
    ASSERT_EQUAL(lazy_string.Get(), big_string);
}

void TestInitializerIsntCalled() {
    bool called = false;

    {
        LazyValue<int> lazy_int([&called] {
            called = true;
            return 0;
        });
    }
    ASSERT(!called);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, UseExample);
    RUN_TEST(tr, TestInitializerIsntCalled);
    return 0;
}
