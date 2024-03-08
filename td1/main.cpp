#include <iostream>
#include "utils.hpp"
#include "fraction.hpp"

int main()
{
    fraction f1{};
    fraction f2{};
    std::cout<<"Saisissez un numérateur puis un dénominateur:";
    std::cin>>f1.numerator;
    std::cin>>f1.denominator;

    std::cout<<"Saisissez encore un numérateur puis un dénominateur:";
    std::cin>>f2.numerator;
    std::cin>>f2.denominator;
    
    // display(f1);
    // display(f2);
    std::cout << f1;
    std::cout << f2;

    // display(add(f1,f2));
    std::cout << f1+f2;
    // display(sub(f1,f2));
    std::cout<< f1-f2;
    // display(mul(f1,f2));
    std::cout<< f1*f2;
    // display(div(f1,f2));
    std::cout<< f1/f2;


    std::cout<<"Fractions simplifiées:"<<std::endl;

    std::cout << simplify(f1);
    std::cout << simplify(f2);
    std::cout << simplify(f1+f2);
    std::cout<< simplify(f1-f2);
    std::cout<< simplify(f1*f2);
    std::cout<< simplify(f1/f2);

    std::cout << to_float(f1);

    // display(simplify(f1));
    // display(simplify(f2));

    // display(simplify(add(f1,f2)));
    // display(simplify(sub(f1,f2)));
    // display(simplify(mul(f1,f2)));
    // display(simplify(div(f1,f2)));

    return 0;
}