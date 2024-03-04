#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// STRUCTURES FONCTION

void Fraction::operator+=(Fraction const &f)
{
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;
}

void Fraction::operator-=(Fraction const &f)
{
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator = denominator * f.denominator;
}

void Fraction::operator*=(Fraction const &f)
{
    numerator *= f.numerator;
    denominator *= f.denominator;
}

void Fraction::operator/=(Fraction const &f)
{
    numerator *= f.denominator;
    denominator *= f.numerator;
}

float Fraction::to_float()
{
    return (float)numerator / (float)denominator;
}

Fraction::operator float() const{
    return (float)numerator / (float)denominator;
}

// FUNCTIONS

std::ostream &operator<<(std::ostream &os, Fraction const &f)
{
    os << f.numerator << " / " << f.denominator;
    return os;
}

Fraction operator+(Fraction f1, Fraction const &f2)
{
    f1 += f2;
    return simplify(f1);
}

Fraction operator-(Fraction f1, Fraction const &f2)
{
    f1 -= f2;
    return simplify(f1);
}

Fraction operator*(Fraction f1, Fraction const &f2)
{
    f1 *= f2;
    return simplify(f1);
}

Fraction operator/(Fraction f1, Fraction const &f2)
{
    f1 /= f2;
    return simplify(f1);
}

bool operator==(Fraction const &f1, Fraction const &f2)
{
    return (f1.numerator == f2.numerator && f1.denominator && f2.denominator);
}

bool operator!=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 == f2);
}

bool operator<(Fraction const &f1, Fraction const &f2)
{
    return ((float)(f1.numerator / f1.denominator) < (float)(f2.numerator / f2.denominator));
}

bool operator<=(Fraction const &f1, Fraction const &f2)
{
    return ((f1 < f2) || (f1 == f2));
}

bool operator>(Fraction const &f1, Fraction const &f2)
{
    return (!(f1 <= f2));
}

bool operator>=(Fraction const &f1, Fraction const &f2)
{
    return ((f1 > f2) || (f1 == f2));
}