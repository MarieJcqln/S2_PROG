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
        if (left==nullptr){
            left=create_node(newvalue);
        }
        else {
            left->insert(newvalue);
        }
    }
    else{
        if (right==nullptr){
            right=create_node(newvalue);
        }
        else {
            right->insert(newvalue);
        }
    }
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
    right = nullptr;    //peut-être delete
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

bool remove(Node*& node, int value){
    if (value == node->value && node->is_leaf()) {
        // On supprime le nœud courant
        delete node;
        // Comme on a une référence sur le pointeur du nœud courant, on le met à jour avec nullptr
        // Ainsi le parent du nœud courant aura un pointeur vers nullptr
        node = nullptr;
        // on retourne true car la suppression a été effectuée
        return true;
    }

    //Si le noeud a 1 seul fils

    else if (value == node->left->value && node->right==NULL) {
        // On supprime le nœud courant
        delete node;
        node = node->left;
        node->left = nullptr;
        return true;
    }

    else if (value == node->right->value && node->left==NULL) {
        // On supprime le nœud courant
        delete node;
        node = node->right;
        node->right = nullptr;
        return true;
    }

    //Si le noeud a 2 fils

    else{
        node = most_left(node->right);
        delete(node->right);
    }

}

void delete_tree(Node* node){
    if (node->left!= nullptr){
        delete_tree(node->left);
    }
    if (node->right!= nullptr){
        delete_tree(node->right);
    }
    delete node;
}
