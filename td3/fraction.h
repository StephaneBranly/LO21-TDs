#pragma once
#include <iostream>

/*
+_________________________+
    Fraction
    ___________
    - numerateur : int
    - denominateur : int
    ___________
    ___________
    + Fraction(in n, int d)
    + setFraction(int n, int d)
    + getNumerateur() : int
    + getDenomintaeur() : int
    - simplification()
    + somme()

+_________________________+
 */

namespace MATH
{
struct Fraction
{

private:
    int numerateur;
    int denominateur;
    void simplification();

public:
    Fraction(int n = 0, int d = 1);

    void setFraction(int n, int d);
    int getNumerateur() const { return numerateur; }
    int getDenominateur() const { return denominateur; }
    Fraction somme(const Fraction &f);
    // Fraction operator+(const Fraction &f);

    ~Fraction()
    {
        std::cout << "destruction " << this << "\n";
    }
};

Fraction somme(const Fraction &f1, const Fraction &f2);
Fraction operator+(Fraction const &a, Fraction const &b);

} // namespace MATH