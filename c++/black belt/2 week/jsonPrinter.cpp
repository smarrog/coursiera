#include "test_runner.h"

#include <cassert>
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <stack>
#include <string>

std::string escape(const std::string& s) {
    std::istringstream iss(s);
    std::ostringstream oss;
    while (iss.peek() != -1) {
        auto next = static_cast<char>(iss.get());
        if (next == '"' || next == '\\') {
            oss << '\\';
        }
        oss << next;
    }
    return oss.str();
}

void PrintJsonString(std::ostream& out, std::string_view str) {
    out << "\"" << escape(std::string(str)) << "\"";
}

class StubPrinter {

};

template <typename T>
class ObjectPrinter;

template <typename T>
class ArrayPrinter {
public:
    ArrayPrinter(std::ostream& os, T& caller) : _os(os), _caller(caller) {
        _os << '[';
    }

    ~ArrayPrinter() {
        EndArray();
    }

    ArrayPrinter& Number(int64_t value)            { addDelimiterIfNeed(); _os << value; return *this; }
    ArrayPrinter& String(std::string_view value)   { addDelimiterIfNeed(); PrintJsonString(_os, value); return *this; }
    ArrayPrinter& Boolean(bool value)              { addDelimiterIfNeed(); _os << (value ? "true" : "false"); return *this; }
    ArrayPrinter& Null()                           { addDelimiterIfNeed(); _os << "null"; return *this; }

    ArrayPrinter<ArrayPrinter> BeginArray() {
        addDelimiterIfNeed();
        ArrayPrinter<ArrayPrinter> arrayPrinter(_os, *this);
        return arrayPrinter;
    }

    ObjectPrinter<ArrayPrinter> BeginObject() {
        addDelimiterIfNeed();
        ObjectPrinter<ArrayPrinter> objectPrinter(_os, *this);
        return objectPrinter;
    }

    T& EndArray() {
        if (!_isEndCalled) {
            _os << ']';
            _isEndCalled = true;
        }
        return _caller;
    }

private:
    T& _caller;
    bool _isFirstValue = true;
    bool _isEndCalled = false;
    std::ostream& _os;

    void addDelimiterIfNeed() {
        if (!_isFirstValue) {
            _os << ",";
        }
        _isFirstValue = false;
    }
};

template <typename T>
class ObjectKeyPrinter {
public:
    ObjectKeyPrinter(std::ostream& os, T& parent) : _os(os), _parent(parent) {}

    ~ObjectKeyPrinter() {
        if (!_isValueSet) {
            _os << "null";
        }
    };

    T& Number(int64_t value)            { _isValueSet = true; _os << value; return _parent; }
    T& String(std::string_view value)   { _isValueSet = true; PrintJsonString(_os, value); return _parent; }
    T& Boolean(bool value)              { _isValueSet = true; _os << (value ? "true" : "false"); return _parent; }
    T& Null()                           { _isValueSet = true; _os << "null"; return _parent; }

    ArrayPrinter<T> BeginArray() {
        _isValueSet = true;
        ArrayPrinter<T> arrayPrinter(_os, _parent);
        return arrayPrinter;
    }

    ObjectPrinter<T> BeginObject() {
        _isValueSet = true;
        ObjectPrinter<T> objectPrinter(_os, _parent);
        return objectPrinter;
    }

private:
    std::ostream& _os;
    T& _parent;
    bool _isValueSet = false;
};

template <typename T>
class ObjectPrinter {
public:
    ObjectPrinter(std::ostream& os, T& caller) : _os(os), _caller(caller) {
        _os << '{';
    }

    ~ObjectPrinter() {
        EndObject();
    }

    ObjectKeyPrinter<ObjectPrinter<T>> Key(std::string_view sv) {
        addDelimiterIfNeed();
        PrintJsonString(_os, sv);
        _os << ':';
        return { _os, *this };
    }

    T& EndObject() {
        if (!_isEndCalled) {
            _os << '}';
            _isEndCalled = true;
        }
        return _caller;
    }

private:
    T& _caller;
    bool _isFirstValue = true;
    bool _isEndCalled = false;
    std::ostream& _os;

    void addDelimiterIfNeed() {
        if (!_isFirstValue) {
            _os << ",";
        }
        _isFirstValue = false;
    }
};


ArrayPrinter<StubPrinter> PrintJsonArray(std::ostream& out) {
    StubPrinter stub;
    return ArrayPrinter(out, stub);
}

ObjectPrinter<StubPrinter> PrintJsonObject(std::ostream& out) {
    StubPrinter stub;
    return ObjectPrinter<StubPrinter>(out, stub);
}

void TestArray() {
    std::ostringstream output;

    {
        auto json = PrintJsonArray(output);
        json
                .Number(5)
                .Number(6)
                .BeginArray()
                .Number(7)
                .EndArray()
                .Number(8)
                .String("bingo!");
    }

    ASSERT_EQUAL(output.str(), R"([5,6,[7],8,"bingo!"])");
}

void TestObject() {
    std::ostringstream output;

    {
        auto json = PrintJsonObject(output);
        json
                .Key("id1").Number(1234)
                .Key("id2").Boolean(false)
                .Key("").Null()
                .Key("\"").String("\\");
    }

    ASSERT_EQUAL(output.str(), R"({"id1":1234,"id2":false,"":null,"\"":"\\"})");
}

void TestAutoClose() {
    std::ostringstream output;

    {
        auto json = PrintJsonArray(output);
        json.BeginArray().BeginObject();
    }

    ASSERT_EQUAL(output.str(), R"([[{}]])");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestArray);
    RUN_TEST(tr, TestObject);
    RUN_TEST(tr, TestAutoClose);

    return 0;
}
