#pragma once

namespace MATH
{
struct Fraction
{
private:
    int numerateur;
    int denominateur;

public:
    void setFraction(int n, int d);
    int getNumerateur() { return numerateur; }
    int getDenominateur() { return denominateur; }
};
} // namespace MATH