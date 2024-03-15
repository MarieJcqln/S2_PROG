#include <iostream>
#include "fraction.hpp"

// - `add` : prend deux fractions en paramètre et retourne la **somme** des deux fractions.
// - `sub` : prend deux fractions en paramètre et retourne la **différence** des deux fractions.
// - `mul` : prend deux fractions en paramètre et retourne le **produit** des deux fractions.
// - `div` : prend deux fractions en paramètre et retourne le **quotient** des deux fractions.
// - `display` : prend une fraction en paramètre et affiche la fraction sous la forme `numerator/denominator`.

std::ostream& operator<< (std::ostream& os, fraction fraction1){
    return os << fraction1.numerator << "/" << fraction1.denominator<<std::endl;
}

fraction operator+(fraction const& fraction1,fraction const& fraction2){
    return {fraction1.numerator*fraction2.denominator + fraction2.numerator*fraction1.denominator,fraction1.denominator * fraction2.denominator};
}

fraction operator-(fraction const& fraction1,fraction const& fraction2){
    return {fraction1.numerator*fraction2.denominator - fraction2.numerator*fraction1.denominator,fraction1.denominator * fraction2.denominator};
}

fraction operator*(fraction const& fraction1,fraction const& fraction2){
    return {fraction1.numerator * fraction2.numerator,fraction1.denominator * fraction2.denominator};
}

fraction operator/(fraction const& fraction1,fraction const& fraction2){
    return {fraction1.numerator * fraction2.denominator,fraction1.denominator * fraction2.numerator};
}

fraction operator<<(fraction const& fraction1,fraction const& fraction2){
    return {fraction1.numerator * fraction2.denominator,fraction1.denominator * fraction2.numerator};
}

bool operator==(fraction const& fraction1,fraction const& fraction2){
    if (fraction1.numerator==fraction2.numerator && fraction1.denominator==fraction2.denominator){
        return true;
    }
    else{ return false;}
}

bool operator!=(fraction const& fraction1,fraction const& fraction2){
    if (fraction1 ==fraction2){
        return false;
    }
    else{return true;}
}

bool operator<(fraction const& fraction1,fraction const& fraction2){
    if (fraction1.numerator*fraction2.denominator < fraction2.numerator*fraction1.denominator){
        return true;
    }
    else{return false;}
}

bool operator<=(fraction const& fraction1,fraction const& fraction2){
    if (fraction1<fraction2 or fraction1==fraction2){
        return true;
    }
    else{return false;}
}

bool operator>(fraction const& fraction1,fraction const& fraction2){
    if (fraction1<fraction2 or fraction1==fraction2){
        return false;
    }
    else{return true;}
}

bool operator>=(fraction const& fraction1,fraction const& fraction2){
    if (fraction1>fraction2 or fraction1==fraction2){
        return true;
    }
    else{return false;}
}

fraction operator+=(fraction fraction1,fraction const& fraction2){
    fraction1.numerator = fraction1.numerator*fraction2.denominator+fraction2.numerator*fraction1.denominator;
    fraction1.denominator = fraction1.denominator*fraction2.denominator;
    return {fraction1.numerator,fraction1.denominator};
}

fraction operator-=(fraction fraction1,fraction const& fraction2){
    fraction1.numerator = fraction1.numerator*fraction2.denominator-fraction2.numerator*fraction1.denominator;
    fraction1.denominator = fraction1.denominator*fraction2.denominator;
    return {fraction1.numerator,fraction1.denominator};
}

fraction operator*=(fraction fraction1,fraction const& fraction2){
    fraction1.numerator = fraction1.numerator*fraction2.numerator;
    fraction1.denominator = fraction1.denominator*fraction2.denominator;
    return {fraction1.numerator,fraction1.denominator};
}

fraction operator/=(fraction fraction1,fraction const& fraction2){
    fraction1.numerator = fraction1.numerator*fraction2.denominator;
    fraction1.denominator = fraction1.denominator*fraction2.numerator;
    return {fraction1.numerator,fraction1.denominator};
}

float to_float(fraction const& fraction1){
    return(static_cast<float>(fraction1.numerator)/static_cast<float>(fraction1.denominator));
}



// fraction add(fraction fraction1, fraction fraction2)
// {
//     fraction result{};
//     if (fraction1.denominator == fraction2.denominator)
//     {
//         result.numerator = fraction1.numerator + fraction2.numerator;
//         result.denominator = fraction1.denominator;
//     }
//     else
//     {
//         result.numerator = fraction1.numerator*fraction2.denominator + fraction2.numerator*fraction1.denominator;
//         result.denominator = fraction1.denominator+fraction2.denominator;
//     }
//     return result;
// }

// fraction sub(fraction fraction1, fraction fraction2)
// {
//     fraction result{};
//     if (fraction1.denominator == fraction2.denominator)
//     {
//         result.numerator = fraction1.numerator - fraction2.numerator;
//         result.denominator = fraction1.denominator;
//     }
//     else
//     {
//         if (fraction1.numerator*fraction2.denominator>fraction2.numerator*fraction1.denominator)
//         {
//             result.numerator = fraction1.numerator*fraction2.denominator - fraction2.numerator*fraction1.denominator;
//         }
//         else
//         {
//             result.numerator = fraction2.numerator*fraction1.denominator - fraction1.numerator*fraction2.denominator;
//         }
//         result.denominator = fraction1.denominator+fraction2.denominator;
//     }
//     return result;
// }

// fraction mul(fraction fraction1, fraction fraction2)
// {
//     fraction result{};
//     result.numerator = fraction1.numerator*fraction2.numerator;
//     result.denominator=fraction1.denominator*fraction2.denominator;
//     return result;
// }

// fraction div(fraction fraction1, fraction fraction2)
// {
//     fraction result{};
//     result.numerator = fraction1.numerator*fraction2.denominator;
//     result.denominator=fraction1.denominator*fraction2.numerator;
//     return result;
// }

void display(fraction f)
{
    std::cout<<f.numerator<<"/"<<f.denominator<<std::endl;
}