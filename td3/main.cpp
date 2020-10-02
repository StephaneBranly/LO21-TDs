#include "fraction.h"
#include <iostream>
using namespace MATH;

int main()
{
    std::cout << "Hello world\n";
    Fraction f;
    f.setFraction(3, 4);
    std::cout << "num=" << f.getNumerateur() << " / den=" << f.getDenominateur();
    return 0;
}