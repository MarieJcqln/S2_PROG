#pragma once
struct fraction
{
    unsigned int numerator{0};
    unsigned int denominator{1};
// - `add` : prend deux fractions en paramètre et retourne la **somme** des deux fractions.
// - `sub` : prend deux fractions en paramètre et retourne la **différence** des deux fractions.
// - `mul` : prend deux fractions en paramètre et retourne le **produit** des deux fractions.
// - `div` : prend deux fractions en paramètre et retourne le **quotient** des deux fractions.
// - `display` : prend une fraction en paramètre et affiche la fraction sous la forme `numerator/denominator`.

};
    fraction operator+(fraction const& fraction1,fraction const& fraction2);

    fraction operator-(fraction const& fraction1,fraction const& fraction2);

    fraction operator*(fraction const& fraction1,fraction const& fraction2);

    fraction operator/(fraction const& fraction1,fraction const& fraction2);
    
    std::ostream& operator<<(std::ostream& os, fraction fraction1);

    bool operator==(fraction const& fraction1,fraction const& fraction2);

    bool operator!=(fraction const& fraction1,fraction const& fraction2);

    bool operator<(fraction const& fraction1,fraction const& fraction2);

    bool operator<=(fraction const& fraction1,fraction const& fraction2);

    bool operator>(fraction const& fraction1,fraction const& fraction2);

    bool operator>=(fraction const& fraction1,fraction const& fraction2);

    fraction operator+=(fraction fraction1,fraction const& fraction2);

    fraction operator-=(fraction fraction1,fraction const& fraction2);

    fraction operator*=(fraction fraction1,fraction const& fraction2);

    fraction operator/=(fraction fraction1,fraction const& fraction2);

    float to_float(fraction const& fraction1);



    fraction add(fraction fraction1, fraction fraction2);
    fraction sub(fraction fraction1, fraction fraction2);
    fraction mul(fraction fraction1, fraction fraction2);
    fraction div(fraction fraction1, fraction fraction2);
    void display(fraction f);
