#pragma once

#include <vector>
#include <unordered_map>
#include <utility>
#include <functional>

namespace Graph
{
    struct WeightedGraphEdge
    {
        int to{};
        float weight{1.0f};

        // default ici permet de définit les opérateurs de comparaison membres à membres automatiquement
        // Cela ne fonction qu'en C++20, si vous n'avez pas accès à cette version je vous donne les implémentations des opérateurs plus bas
        bool operator==(WeightedGraphEdge const &other) const;
        bool operator!=(WeightedGraphEdge const &other) const;
    };

    struct WeightedGraph
    {
        // L'utilisation d'un tableau associatif permet d'avoir une complexité en O(1) pour l'ajout et la recherche d'un sommet.
        // Cela permet de stocker les sommets dans un ordre quelconque (et pas avoir la contrainte d'avoir des identifiants (entiers) de sommets consécutifs lors de l'ajout de sommets).
        // Cela permet également de pouvoir utiliser des identifiants de sommets de n'importe quel type (string, char, int, ...) et pas seulement des entiers.
        std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list{};

        bool exists(int const id);

        void add_vertex(int const id);

        void add_directed_edge(int const from, int const to, float const weight = 1.0f);
        void add_undirected_edge(int const from, int const to, float const weight = 1.0f);

        // Même fonctionnement que pour WeightedGraphEdge
        bool operator==(WeightedGraph const &other) const;
        bool operator!=(WeightedGraph const &other) const;

        void print_DFS(int const start) const;
        void print_BFS(int const start) const;
        void BFS(int const start, std::function<void(int const)> callback) const;
        std::unordered_map<int, std::pair<float, int>> dijkstra(int const &start, int const &end);
    };
    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const &adjacency_matrix);
    void display_shortest_path(std::unordered_map<int, std::pair<float, int>> tab, int start, int end);

} // namespace