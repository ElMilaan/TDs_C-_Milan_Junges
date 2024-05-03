#include <iostream>
#include "graph.hpp"
#include "utils.hpp"
#include <stack>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

namespace Graph
{
    bool WeightedGraphEdge::operator==(WeightedGraphEdge const &other) const
    {
        return to == other.to && weight == other.weight;
    }
    bool WeightedGraphEdge::operator!=(WeightedGraphEdge const &other) const
    {
        return !(*this == other);
    }

    bool WeightedGraph::operator==(WeightedGraph const &other) const
    {
        return adjacency_list == other.adjacency_list;
    }

    bool WeightedGraph::operator!=(WeightedGraph const &other) const
    {
        return !(*this == other);
    }

    bool WeightedGraph::exists(char const id)
    {
        return adjacency_list.find(id) != adjacency_list.end();
    }

    void WeightedGraph::add_vertex(char const id)
    {
        if (!exists(id))
        {
            adjacency_list.insert({id, {}});
        }
    }

    void WeightedGraph::add_directed_edge(char const from, char const to, float const weight)
    {
        if (!exists(to))
        {
            add_vertex(to);
        }
        adjacency_list.at(from).push_back({to, weight});
    }

    void WeightedGraph::add_undirected_edge(char const from, char const to, float const weight)
    {
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight);
    }

    WeightedGraph build_from_adjacency_matrix(vector<vector<float>> const &adjacency_matrix)
    {
        WeightedGraph graph{};
        for (int i{0}; i < adjacency_matrix.size(); i++)
        {
            graph.add_vertex(i + 1);
            for (int j{0}; j < adjacency_matrix[i].size(); j++)
            {
                if (adjacency_matrix[i][j] != 0)
                {
                    graph.add_directed_edge(i + 1, j + 1, adjacency_matrix[i][j]);
                }
            }
        }
        return graph;
    }

    void WeightedGraph::print_DFS(char const start) const
    {
        stack<char> stk{};
        vector<char> vertexAlreadyPrint{start};
        stk.push(start);
        int sum{0};
        while (!stk.empty())
        {
            int current{stk.top()};
            cout << current << " ";
            stk.pop();
            if (adjacency_list.find(current) != adjacency_list.end())
            {
                for (WeightedGraphEdge adjVertex : adjacency_list.at(current))
                {
                    // On vérifie que le sommet à ajouter à la pile n'a pas déjà été affiché
                    if (!isIn(vertexAlreadyPrint, adjVertex.to))
                    {
                        stk.push(adjVertex.to);
                        vertexAlreadyPrint.push_back(adjVertex.to);
                    }
                }
            }
        }
    }

    void WeightedGraph::print_BFS(char const start) const
    {
        queue<char> q{};
        vector<char> vertexAlreadyPrint{start};
        q.push(start);
        while (!q.empty())
        {
            char current{q.front()};
            cout << current << " ";
            q.pop();
            if (adjacency_list.find(current) != adjacency_list.end())
            {
                for (WeightedGraphEdge adjVertex : adjacency_list.at(current))
                {
                    // On vérifie que le sommet à ajouter à la pile n'a pas déjà été affiché
                    if (!isIn(vertexAlreadyPrint, adjVertex.to))
                    {
                        q.push(adjVertex.to);
                        vertexAlreadyPrint.push_back(adjVertex.to);
                    }
                }
            }
        }
    }

    void WeightedGraph::BFS(char const start, function<void(char const)> callback) const
    {
        queue<char> q{};
        vector<char> vertexAlreadyPrint{start};
        q.push(start);
        while (!q.empty())
        {
            char current{q.front()};
            callback(current);
            q.pop();
            if (adjacency_list.find(current) != adjacency_list.end())
            {
                for (WeightedGraphEdge adjVertex : adjacency_list.at(current))
                {
                    // On vérifie que le sommet à ajouter à la pile n'a pas déjà été affiché
                    if (!isIn(vertexAlreadyPrint, adjVertex.to))
                    {
                        q.push(adjVertex.to);
                        vertexAlreadyPrint.push_back(adjVertex.to);
                    }
                }
            }
        }
    }

    unordered_map<char, pair<float, char>> WeightedGraph::dijkstra(char const &start, char const &end)
    {
        unordered_map<char, pair<float, char>> tab{};
        tab.insert({start, {0, 1}});
        // On définit la priorité comme décroissante pour avoir le plus petit élément retourné par .top()
        priority_queue<char, std::vector<char>, std::greater<char>> toVisit{};
        toVisit.push(start);
        char current{-1};
        while (!toVisit.empty() && current != end)
        {
            current = toVisit.top();
            toVisit.pop();
            // On parcourt tous les sommets adjacents du sommet courant
            for (WeightedGraphEdge edge : adjacency_list.at(current))
            {
                // On calcul la distance depuis le sommet initial jusqu'à celui-ci
                float newWeight{edge.weight + tab.at(current).first};
                // On vérifie que le sommet n'a pas encore été ajouté ou que la nouvelle distance est plus courte que celle calculée pour ce même sommet précédemment
                if (tab.find(edge.to) == tab.end() || newWeight < tab.at(edge.to).first)
                {
                    // S'il existe déjà (donc que sa distance au sommet initiale est plus coure que celle calculée plus tôt), on supprime le sommet du tableau.
                    if (tab.find(edge.to) != tab.end())
                    {
                        tab.erase(edge.to);
                    }
                    // On insère le nouveau sommet dans le tableau (ou on le réinsert s'il vient d'être supprimé)
                    tab.insert({edge.to, {newWeight, current}});
                    toVisit.push(edge.to);
                }
            }
        }

        return tab;
    }

}