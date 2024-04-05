#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <functional>
#include <numeric>

auto const is_space = [](char letter){ return letter == ' '; };

int comptelettres(std::string & phrase){
    int compteur{0};
    auto it =std::find_if(phrase.begin(), phrase.end(), is_space);
    compteur = std::distance(phrase.begin(),it);
    std::cout<<compteur;
    return compteur;
}

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> vec {};
    auto it{str.begin()};
    auto previous{str.begin()};
    while(it!=str.end()){    
        it = std::find_if(it, str.end(), is_space);
        std::string mot{previous,it};
        vec.push_back(mot);
        previous =it;
    }
    return vec;
}


bool palindrome(std::string const& str){
    auto deb{str.begin()};
    auto fin{str.end()};
    auto rdeb{str.rbegin()};
    auto rfin{str.rend()};
    bool pal{true};
    while(deb!=str.end()){    
        if (std::equal(deb,fin,rdeb)){
            deb++;
            rdeb++;
        }
        else{
            pal=false;
            break;
        }
    }
    if(pal){
        std::cout<<"C'est un palindrome.";
    }
    else{std::cout<<"Ce n'est pas un palindrome.";}
    return pal;
}

int main()
{
    //Exercice 1//

    std::vector<int> vec1 {};
    int saisie{0};
    for (int i=0; i<10;i++){
        vec1.push_back(rand()%100);
    }
    for (std::vector<int>::iterator j{vec1.begin()}; j < vec1.end();j++){
        std::cout << *j << std::endl;
    }
    std::cout << "Saisissez un entier : " << std::endl;
    std::cin >> saisie;
    auto it {std::find(vec1.begin(), vec1.end(), saisie)};
    if (it != vec1.end()){
        std::cout << saisie << " est dans le vecteur." << std::endl;
    }
    else{
        std::cout << "Le vecteur de contient pas " << saisie << std::endl;
    }
    int const a{44};
    int countsaisie = std::count(vec1.begin(), vec1.end(), a);
    std::cout << a <<" apparait " << countsaisie << " fois." << std::endl;

    std::sort(vec1.begin(), vec1.end());

    int somme = std::accumulate(vec1.begin(), vec1.end(), 0);
    std::cout << "Somme des éléments : "<<somme << std::endl;

    // Exercice 2//

    std::string phrase {"Bonjour toi"};
    // comptelettres(phrase);
    // split_string(phrase);

    // Exercice 3//
    //std::string phrase2 {"kayak"};
    std::string phrase2 {"marie"};
    palindrome(phrase2);

    return 0;
}