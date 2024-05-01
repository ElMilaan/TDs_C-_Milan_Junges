#include <iostream>
#include "graph.hpp"

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

    bool WeightedGraph::exists(int const id)
    {
        return adjacency_list.find(id) != adjacency_list.end();
    }

    void WeightedGraph::add_vertex(int const id)
    {
        if (!exists(id))
        {
            adjacency_list.insert({id, {}});
        }
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight)
    {
        if (!exists(to))
        {
            add_vertex(to);
        }
        adjacency_list.at(from).push_back({to, weight});
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
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

}