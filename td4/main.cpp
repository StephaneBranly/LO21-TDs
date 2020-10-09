#include "computer.h"
#include <iostream>
using namespace std;
using namespace COMPUTER;

int main()
{
    cout << "Hello world";

    ExpressionManager manager;
    Expression &e1 = manager.addExpression(2);
    Expression &e2 = manager.addExpression(2);
    Expression &e3 = manager.addExpression(5);
    Expression &e4 = manager.addExpression(2);

    manager.removeExpression(e2);

    // On ne peut pas définir des tableaux d'objects d'Expression sans fournir d'initialisateur
    Expression *tabpt[5];

    return 0;
};