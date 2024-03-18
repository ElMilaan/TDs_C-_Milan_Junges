#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1{3, 4};
    Fraction f2{5, 3};

    std::cout << "f1 : " << f1 << std::endl;
    std::cout << "f2 : " << f2 << std::endl;

    std::cout << "f1 + f2 = " << f1 + f2 << std::endl;
    std::cout << "f1 - f2 = " << f1 - f2 << std::endl;
    std::cout << "f1 * f2 = " << f1 * f2 << std::endl;
    std::cout << "f1 / f2 = " << f1 / f2 << std::endl;

    std::cout << "f1 != f2 : " << (f1 != f2) << std::endl;
    std::cout << "f1 == f2 : " << (f1 == f2) << std::endl;

    std::cout << "f1 < f2 : " << (f1 < f2) << std::endl;
    std::cout << "f1 <= f2 : " << (f1 <= f2) << std::endl;
    std::cout << "f1 > f2 : " << (f1 > f2) << std::endl;
    std::cout << "f1 >= f2 : " << (f1 >= f2) << std::endl;

    std::cout << "f1 toFloat (method) : " << f1.to_float() << std::endl;

    std::cout << "f2 toFloat (operator) : " << (float)f2 << std::endl;

    std::cout << "f1 + 2 : " << f1 + 2 << std::endl;
    std::cout << "2 + f1 : " << 2 + f1 << std::endl;

    std::cout << "Valeur absolue de " << f2 << " : " << abs(f2) << std::endl;
    std::cout << "Arrondi de " << f2 << " : " << round(f2) << std::endl;
    std::cout << "Arrondi superieur de " << f2 << " : " << ceil(f2) << std::endl;
    std::cout << "Arrondi inferieur de " << f2 << " : " << floor(f2) << std::endl;

    return 0;
}