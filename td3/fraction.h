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
class FractionException
{
    std::string info;

public:
    FractionException(const std::string &s) : info(s) {}
    std::string getInfo() const
    {
        return info;
    }
};
class Fraction
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

    Fraction &operator++()
    {
        numerateur += denominateur;
        return *this;
    };                       // préfixe, renvoie une lvalue sur x (après incrémentation) // ++x
    Fraction operator++(int) // argument int fictif pour indiquer que c'est en post fixe // x++
    {
        Fraction old = *this;
        numerateur += denominateur;
        return old;
    }
}; // postfixe, renvoie l'ancienne valeur de x

Fraction somme(const Fraction &f1, const Fraction &f2);
Fraction operator+(Fraction const &a, Fraction const &b);
Fraction operator-(Fraction const &a, Fraction const &b);

inline Fraction &operator--(Fraction &f)
{
    f = f - 1;
    return f;
}
inline Fraction operator--(Fraction &f, int)
{
    Fraction old = f;
    f = f - 1;
    return old;
}

} // namespace MATH

std::ostream &
operator<<(std::ostream &out, const MATH::Fraction &obj);
