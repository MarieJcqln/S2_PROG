#include <iostream>
#include "fraction.hpp"

int pgcd(int a, int b)
{
    int r { a % b };
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }

    // On peut tout à fait renvoyer la valeur d'un paramètre
    return b;
}

fraction simplify(fraction f)
{
    int p{};
    fraction result{};
    p=pgcd(f.numerator,f.denominator);
    result.numerator = f.numerator/p;
    result.denominator = f.denominator/p;
    return result;
}