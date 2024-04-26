#include <iostream>
#include "node.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value){
    Node* n {new Node};
    n->value= value;
    return n;
}

bool Node::is_leaf() const
{
    if (right == nullptr && left==nullptr){
        return true;
    }
    else{return false;}
}

void Node::insert(int newvalue){
    if (newvalue<value){
        left=create_node(newvalue);
    }
    else{right=create_node(newvalue);}
}

int Node::height() const{
    int hauteur{0};
    int hauteurleft{0};
    int hauteurright{0};
    if (left != nullptr){
        left->height();
        hauteurleft++;
    }
    if (right != nullptr){
        right->height();
        hauteurright++;
    }
    if (hauteurleft>hauteurright){
        return hauteurleft;
    }
    if (hauteurleft<=hauteurright){
        return hauteurright;
    }
}

void Node::delete_childs(){
    if (left!= nullptr){
        left->delete_childs();
    }
    if (right!= nullptr){
        right->delete_childs();
    }
    left = nullptr;
    right = nullptr;
}

void Node::display_infixe() const{
    if (left!= nullptr){
        left->display_infixe();
    }
    std::cout<<value<<" ";
    if (right!=nullptr){
        right->display_infixe();
    }
}

std::vector<Node const*> Node::prefixe() const{
    std::vector<Node const*> nodes {};
    if (left!= nullptr){
        auto left_nodes {left->prefixe()};
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    nodes.push_back(this);
    if (right!= nullptr){
        auto right_nodes {right->prefixe()};
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}

std::vector<Node const*> Node::postfixe() const{
    std::vector<Node const*> nodes {};
    if (left!= nullptr){
        left->postfixe();
    }
    nodes.push_back(this);
    if (right!= nullptr){
        right->postfixe();
    }
    return nodes;
}

Node*& most_left(Node*& node){
    if (node->left!= nullptr){
        most_left(node->left);
    }
    else{
        return node;
    }
}

bool remove(Node*& node, int value);
