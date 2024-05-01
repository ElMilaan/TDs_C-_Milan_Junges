#include <iostream>
#include <unordered_map>
#include <vector>

#include "graph.hpp"

using namespace std;

ostream &operator<<(ostream &os, const Graph::WeightedGraph graph)
{
    for (pair p : graph.adjacency_list)
    {
        for (Graph::WeightedGraphEdge wge : p.second)
        {
            os << p.first << " -> " << wge.to << " ( " << wge.weight << " )" << endl;
        }
    }
    return os;
}

ostream &operator<<(ostream &os, const vector<vector<float>> adj_mat)
{
    for (int i{0}; i < adj_mat.size(); i++)
    {
        os << endl;
        for (int j{0}; j < adj_mat[i].size(); j++)
        {
            os << adj_mat[i][j] << "  ";
        }
    }
    return os;
}