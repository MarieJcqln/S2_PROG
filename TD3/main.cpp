#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s)
{
    int i{0};
    while (i<s.size())
    {
        if (std::isdigit(s[i])){
            i++;
        }
        else if(s[i]== '.'){
            i++;
        }
        else{
            return false;
        }
    }
    return true;
}

float npi_evaluate(std::vector<std::string> const& tokens){
    //pile nombre
    std::stack<int> stack;
    int i{0};
    int val {0};
    while (i<tokens.size()){
        if (is_floating(tokens[i])){
            val = std::stof(tokens[i]);
            stack.push(val);
        }
        else if (tokens[i]=="+"){
            float rightOperand { stack.top() };
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();
            float result {leftOperand + rightOperand};
            stack.push(result);
        }
        else if (tokens[i]=="-"){
            float rightOperand { stack.top() };
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();
            float result {leftOperand - rightOperand};
            stack.push(result);
        }
        else if (tokens[i]=="*"){
            float rightOperand { stack.top() };
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();
            float result {leftOperand * rightOperand};
            stack.push(result);
        }
        else if (tokens[i]=="/"){
            float rightOperand { stack.top() };
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();
            float result {leftOperand / rightOperand};
            stack.push(result);
        }
    }
    return stack.top();
}
//std::stack

int main()
{
    std::vector<std::string> vec;
    std::string entree;
    std::cout<<"Entrée utilisateur : ";
    std::getline(std::cin, entree);
    //std::cin>> entree;
    vec=split_string(entree); 
    npi_evaluate(vec);

    return 0;
}