#include "fraction.h"

using namespace MATH;

void Fraction::setFraction(int n, int d)
{
    if (d)
    {
        numerateur = n;
        denominateur = d;
    }
}