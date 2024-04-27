#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>

    //Exercice 3//

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    int hash() const{
        int result{0};
        result = static_cast<int>(kind)*13+static_cast<int>(value);
        return result;
    }
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

bool operator==(Card const& card1,  Card const& card2){
    if (card1.kind==card2.kind && card1.value==card2.value){
        return true;
    }
    else{return false;}
}


std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}



    //Exercice 2//

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes){
    std::unordered_map<std::string, std::vector<float>> tableau {};
    for (auto it{robots_fixes.begin()}; it != robots_fixes.end(); it++){
        auto robotName = (*it).first;
        auto robotNumber = (*it).second;
        auto Number = tableau.find(robotName);
        if ( Number != tableau.end()) {
            //tableau[robotName].push_back(robotNumber);
            (*Number).second.push_back(robotNumber);
        }
        else{
            tableau.insert({robotName, {robotNumber}});
        }
    }
    return tableau;
}

float somme_reparations(std::vector<float> cost){
    int somme{0};
    for (auto it{cost.begin()}; it != cost.end(); it++){
        auto prix = (*it);
        somme+=prix;
    }
    std::cout<<somme<<std::endl; //pour tester
    return somme;
}

    //Exercice 1//

size_t folding_string_hash(std::string const& s, size_t max){
    size_t result{0};
    for (int i{0}; i<s.size();i++){
        result = result + s[i];
    }
    //std::cout<<result%max; //pour tester
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
    size_t power{1};
    for (int i{0}; i<s.size();i++){
        result = (result + s[i]*power)%m;
        power*=p;
    }
    return result;
}



int main()
{
    //folding_string_hash("Marie", 128);
    auto map = robots_fixes_map(get_robots_fix(10));
    for (auto it{map.begin()}; it != map.end(); it++){
    somme_reparations((*it).second);
    }


        //Exercice 3//
    auto cards = get_cards(100);

    std::unordered_map<std::string, int> compteur {};

    for (int i; i < cards.size(); i++){
        auto carte = compteur.find(card_name(cards[i]));
        if (carte != compteur.end()) {
            *carte ++; 
        }
        else{
            std::pair<std::string,int> insertion (card_name(cards[i]),1);
            compteur.insert(insertion);
        }

    }

    return 0;
}