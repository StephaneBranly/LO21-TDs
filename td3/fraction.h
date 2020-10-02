#pragma once

namespace MATH
{
struct Fraction
{

private:
    int numerateur = 0;
    int denominateur = 1;
    void simplification();

public:
    Fraction(int n, int d) { setFraction(n, d); };
    Fraction(int n) : numerateur(n) {}
    Fraction() = default;

    void setFraction(int n, int d);
    int getNumerateur() const { return numerateur; }
    int getDenominateur() const { return denominateur; }
    Fraction &somme(Fraction f1, Fraction f2);
};
} // namespace MATH