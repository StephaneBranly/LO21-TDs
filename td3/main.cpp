#include "fraction.h"
#include <iostream>
using namespace MATH;

int main()
{
    Fraction f1(6, 2);
    Fraction f2(6, 2);
    Fraction f3;
    // f.setFraction(3, 4);
    std::cout << "\nnum=" << f1.getNumerateur() << " / den=" << f1.getDenominateur();
    std::cout << "\nnum=" << f2.getNumerateur() << " / den=" << f2.getDenominateur();
    std::cout << "\nnum=" << f3.getNumerateur() << " / den=" << f3.getDenominateur();

    return 0;
}