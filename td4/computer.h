#pragma once
#include <iostream>
#include <string>

namespace COMPUTER
{
class Expression
{
    int value;

public:
    Expression(int v) : value(v){};
    const int getValue() { return value; };
    const std::string toString() { return to_string(value); }
};

class ExpressionManager
{
    Expression **exps;
    size_t nb;
    size_t nbMax;
    void agrandissementCapacite();

public:
    ExpressionManager();
    Expression &addExpression(int v);
    void removeExpression(Expression &e);
};

} // namespace COMPUTER