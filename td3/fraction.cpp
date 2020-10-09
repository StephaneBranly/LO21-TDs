#include "fraction.h"
#include <iostream>

namespace MATH
{
Fraction::Fraction(int n, int d)
{
    std::cout << "construction " << this << "\n";
    setFraction(n, d);
};

void Fraction::setFraction(int n, int d)
{
    numerateur = n;
    if (!d)
        throw FractionException("Erreur, denominateur null"); // déclenchement d'une exception
    denominateur = d;

    simplification();
}

void Fraction::simplification()
{
    if (numerateur == 0)
    {
        denominateur = 1;
        return;
    }
    if (denominateur == 0)
        return;
    int a = numerateur, b = denominateur;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    numerateur /= a;
    denominateur /= a;
    if (denominateur < 0)
    {
        denominateur = -b;
        numerateur = -a;
    }
}

Fraction Fraction::somme(const Fraction &f)
{
    int sumNum = f.numerateur * denominateur + f.denominateur * numerateur;
    int prodDen = f.denominateur * denominateur;
    Fraction res(sumNum, prodDen);
    return res;
}

// Fraction Fraction::operator+(const Fraction &f)
// {
//     int sumNum = f.numerateur * denominateur + f.denominateur * numerateur;
//     int prodDen = f.denominateur * denominateur;
//     Fraction res(sumNum, prodDen);
//     return res;
// }

Fraction somme(const Fraction &f1, const Fraction &f2)
{
    int sumNum = f1.getNumerateur() * f2.getDenominateur() + f1.getDenominateur() * f2.getNumerateur();
    int prodDen = f1.getDenominateur() * f2.getDenominateur();
    Fraction res(sumNum, prodDen);
    return res;
}

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    int sumNum = f1.getNumerateur() * f2.getDenominateur() + f1.getDenominateur() * f2.getNumerateur();
    int prodDen = f1.getDenominateur() * f2.getDenominateur();
    Fraction res(sumNum, prodDen);
    return res;
}
Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    int sumNum = f1.getNumerateur() * f2.getDenominateur() - f1.getDenominateur() * f2.getNumerateur();
    int prodDen = f1.getDenominateur() * f2.getDenominateur();
    Fraction res(sumNum, prodDen);
    return res;
}
Fraction operator++(const Fraction &f1, int)
{
    Fraction res(f1.getNumerateur() + f1.getDenominateur(), f1.getDenominateur());
    return res;
}
} // namespace MATH

std::ostream &operator<<(std::ostream &out, const MATH::Fraction &obj)
{
    out << obj.getNumerateur() << "/" << obj.getDenominateur();
    return out;
}
