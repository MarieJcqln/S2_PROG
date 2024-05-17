#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include "graph.hpp"

int main(){
    std::vector<std::vector<float>> const& matrice{{0,1},{3,0}};
    Graph::build_from_adjacency_matrix(matrice);
    //avec add vertex et undirected_edges
    //comparer
    
}