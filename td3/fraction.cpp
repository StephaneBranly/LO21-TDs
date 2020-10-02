#include "fraction.h"

namespace MATH
{
void Fraction::setFraction(int n, int d)
{
    numerateur = n;
    if (!d)
        throw "Erreur, denominateur null";
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

Fraction &Fraction::somme(Fraction f1, Fraction f2)
{
    Fraction *f = new Fraction();
    int sumNum = f1.numerateur * f2.denominateur + f1.denominateur * f2.numerateur;
    int prodDen = f1.denominateur * f2.denominateur;
    (*f).setFraction(sumNum, prodDen);

    return (*f);
}

} // namespace MATH
