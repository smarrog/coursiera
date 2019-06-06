#include "Common.h"
#include "test_runner.h"

#include <sstream>

using namespace std;

class ValueExpression : public Expression {
public:
    ValueExpression(int value)
        : _value(value) { }

    int Evaluate() const override {
        return _value;
    };

    virtual std::string ToString() const override {
        return std::to_string(_value);
    };
private:
    int _value;
};

class BinaryOperationExpression : public Expression {
public:
    BinaryOperationExpression(ExpressionPtr left, ExpressionPtr right, char sign)
        : _left(std::move(left))
        , _right(std::move(right))
        , _sign(sign) { }

    virtual std::string ToString() const override {
        return '(' + _left->ToString() + ')' + _sign + '(' + _right->ToString() + ')';
    };

protected:
    int getLeftValue() const {
        return _left->Evaluate();
    }

    int getRightValue() const {
        return _right->Evaluate();
    }

private:
    ::ExpressionPtr _left;
    ::ExpressionPtr _right;
    char _sign;
};

class SumExpression : public BinaryOperationExpression {
public:
    SumExpression(ExpressionPtr left, ExpressionPtr right)
            : BinaryOperationExpression(std::move(left), std::move(right), '+') { }

    int Evaluate() const override {
        return getLeftValue() + getRightValue();
    };
};

class ProductExpression : public BinaryOperationExpression {
public:
    ProductExpression(ExpressionPtr left, ExpressionPtr right)
            : BinaryOperationExpression(std::move(left), std::move(right), '*') { }

    int Evaluate() const override {
        return getLeftValue() * getRightValue();
    };
};

ExpressionPtr Value(int value) {
    return std::make_unique<ValueExpression>(value);
}

ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right) {
    return std::make_unique<SumExpression>(std::move(left), std::move(right));
}

ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right) {
    return std::make_unique<ProductExpression>(std::move(left), std::move(right));
}

string Print(const Expression* e) {
    if (!e) {
        return "Null expression provided";
    }
    stringstream output;
    output << e->ToString() << " = " << e->Evaluate();
    return output.str();
}

void Test() {
    ExpressionPtr e1 = Product(Value(2), Sum(Value(3), Value(4)));
    ASSERT_EQUAL(Print(e1.get()), "(2)*((3)+(4)) = 14");

    ExpressionPtr e2 = Sum(move(e1), Value(5));
    ASSERT_EQUAL(Print(e2.get()), "((2)*((3)+(4)))+(5) = 19");

    ASSERT_EQUAL(Print(e1.get()), "Null expression provided");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
    return 0;
}