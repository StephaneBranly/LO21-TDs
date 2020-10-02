#pragma once
#include <iostream>

namespace MATH
{
struct Fraction
{

private:
    int numerateur = 0;
    int denominateur = 1;
    void simplification();

public:
    Fraction(int n, int d)
    {
        setFraction(n, d);
        std::cout << "\nYouhou, fraction creee !";
    };
    Fraction(int n) : numerateur(n) { std::cout << "\nYouhou, fraction creee !"; }
    Fraction() = default;

    void setFraction(int n, int d);
    int getNumerateur() const { return numerateur; }
    int getDenominateur() const { return denominateur; }
    Fraction somme(const Fraction &f);

    ~Fraction()
    {
        std::cout << "\nYouhou, fraction detruite !";
    }
};

Fraction somme(const Fraction &f1, const Fraction &f2);
} // namespace MATH