#include <iostream>
#include <unordered_map>
#include <vector>

#include "graph.hpp"

using namespace std;

ostream &operator<<(ostream &os, const Graph::WeightedGraph graph);
ostream &operator<<(ostream &os, const vector<vector<float>> adj_mat);