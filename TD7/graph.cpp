#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include "graph.hpp"

using namespace Graph;

void WeightedGraph::add_vertex(int const id){
    //find
    auto A = adjacency_list.find(id);
    if ( A != adjacency_list.end()) {
        //Ajout du sommet, créer la liste de edges
        // adjacency_list.insert(std::make_pair<int, std::vector<WeightedGraphEdge>>(id,{}));
        adjacency_list[id] = {};
    }
}

void WeightedGraph::add_directed_edge(int const from, int const to, float const weight = 1.0f){
    //ajout arête et vertex s'il existe pas
    auto A = adjacency_list.find(from);
    auto B = adjacency_list.find(to);
    if ( A == adjacency_list.end()) { add_vertex(from);}
    if ( B == adjacency_list.end()) { add_vertex(to);}
    adjacency_list[2][to].weight = weight;

}