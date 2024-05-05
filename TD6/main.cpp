#include <iostream>
#include "node.hpp"

//Exercice 2
int main(){
    Node* arbre {create_node(5)};
    arbre->insert(3);
    arbre->insert(7);
    arbre->insert(2);
    arbre->insert(4);
    arbre->insert(6);
    arbre->insert(8);
    arbre->insert(1);
    arbre->insert(9);
    arbre->insert(0);

    arbre->display_infixe();

    std::vector<Node const*> vect = arbre->postfixe();
    int somme{0};
    for (int i; i<vect.size();i++){
        somme = somme + vect[i]->value;
    }
    std::cout<<somme<<std::endl;

    arbre->height();


    return 0;
}