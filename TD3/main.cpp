#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s)
{
    int i{0};
    while (i<std::string.size)
    {

    }
    //std::isdigit
}

int main()
{
    std::vector<std::string> vec;
    std::string entree;
    std::cout<<"Entrée utilisateur : ";
    std::getline(std::cin, entree);
    //std::cin>> entree;
    vec=split_string(entree); 

    return 0;
}