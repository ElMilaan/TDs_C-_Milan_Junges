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
            os << "|" << p.first << "| -- " << wge.weight << " -> |" << wge.to << "|" << endl;
        }
    }
    return os;
}

ostream &operator<<(ostream &os, const unordered_map<int, pair<float, int>> map)
{
    for (pair p : map)
    {
        os << "|" << p.first << "| (" << p.second.first << ", |" << p.second.second << "|)" << endl;
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

bool isIn(const std::vector<int> &vec, int val)
{
    for (int e : vec)
    {
        if (e == val)
        {
            return true;
        }
    }
    return false;
}