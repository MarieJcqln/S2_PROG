#include <iostream>
#include <vector>
#include <string>
#include<math.h>


size_t folding_string_hash(std::string const& s, size_t max){
    size_t result{0};
    for (int i{0}; i<s.size();i++){
        result = result + s[i];
    }
    return result%max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t result{0};
    for (int i{0}; i<s.size();i++){
        result = result + s[i]*(i+1);
    }
    return result%max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t result{0};
    for (int i{0}; i<s.size();i++){
        result = result + s[i]*pow(p,i);
    }
    return result%m;
}


int main()
{
    //Exercice 1//


    return 0;
}