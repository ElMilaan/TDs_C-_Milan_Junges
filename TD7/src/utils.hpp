#include <iostream>
#include <unordered_map>
#include <vector>

#include "graph.hpp"

using namespace std;

ostream &operator<<(ostream &os, const Graph::WeightedGraph graph);
ostream &operator<<(ostream &os, const vector<vector<float>> adj_mat);
ostream &operator<<(ostream &os, const unordered_map<int, pair<float, int>> map);
ostream &operator<<(ostream &os, const unordered_map<char, pair<float, char>> map);
bool isIn(const std::vector<char> &vec, char val);