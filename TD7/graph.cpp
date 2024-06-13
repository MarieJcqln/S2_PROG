#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <functional>
#include <string_view>
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

void WeightedGraph::add_directed_edge(int const from, int const to, float const weight){
    //ajout arête et vertex s'il existe pas
    auto A = adjacency_list.find(from);
    auto B = adjacency_list.find(to);
    if ( A == adjacency_list.end()) { add_vertex(from);}
    if ( B == adjacency_list.end()) { add_vertex(to);}
    Graph::WeightedGraphEdge edge {to,weight};
    adjacency_list[from].push_back(edge);
}

void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight){
    add_directed_edge(from, to, weight);
    add_directed_edge(to,from,weight);
}

WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix){
    WeightedGraph graphe {};
    int i{0};
    while(i<adjacency_matrix.size()){
        int a{0};
        while (a<adjacency_matrix[i].size()){
            if (adjacency_matrix[i][a]!= 0){
                graphe.add_directed_edge(i,a,adjacency_matrix[i][a]);
            }
            a++;
        }
        i++;
    }
    return graphe;
}

// premier élément -> si enfants , imprimer, passe à ses enfants
void WeightedGraph::print_DFS(int const start) const {
    if (adjacency_list.find(start) != adjacency_list.end()) {
        std::cout<<start<<std::endl;
        for (const auto& edge : adjacency_list.at(start)) {
            print_DFS(edge.to);
        }
    }
}

void WeightedGraph::print_BFS(int const start) const{
    std::queue<int> file;
    // ajouter start à la file  
    file.push(start);
    //file pas vide donc pop premier élément 
    while (!file.empty()){
        std::cout<<file.front()<<' ';
        file.pop();
        //ajout éléments adjacents
        for (const auto& edge : adjacency_list.at(start)) {
            file.push(edge.to);
        }
    }  
}

std::unordered_map<int, std::pair<int,float>> dijkstra(std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list, int depart, int arrive){
    //tableau associatif pour associer à chaque sommet visité la distance la plus courte connue pour aller du sommet de départ à ce sommet et d'où on vient pour atteindre cette distance
    std::unordered_map<int, float> distances;
    std::unordered_map<int, int> predecessors;
    std::unordered_map<int, std::pair<int,float>> chemin{};

    // priority queue pour itérer sur les sommets à visiter en choisissant à chaque fois le sommet le plus proche du sommet de départ
    using Element = std::pair<float, int>;
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> file_a_visiter;

    // initialisation
    file_a_visiter.push({0.0, depart});
    distances[depart] = 0.0;

    while (!file_a_visiter.empty()) {
        int current = file_a_visiter.top().second;
        float current_distance = file_a_visiter.top().first;
        file_a_visiter.pop();

        // Si nous avons atteint le sommet d'arrivée, nous pouvons arrêter la recherche
        if (current == arrive) break;

        // Iteration sur les voisins
        for (const auto& edge : adjacency_list[current]) {
            int neighbor = edge.to;
            float weight = edge.weight;
            float distance_through_current = current_distance + weight;

            // Si un chemin plus court vers le voisin est trouvé
            if (distances.find(neighbor) == distances.end() || distance_through_current < distances[neighbor]) {
                distances[neighbor] = distance_through_current;
                predecessors[neighbor] = current;
                file_a_visiter.push({distance_through_current, neighbor});
            }
        }
    }

    // Construction du chemin
    int current = arrive;
    while (current != depart) {
        chemin[current] = {predecessors[current], distances[current]};
        current = predecessors[current];
    }
    chemin[depart] = {depart, 0};


    return chemin;
}

