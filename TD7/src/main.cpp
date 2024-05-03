#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

#include "graph.hpp"
#include "utils.hpp"

using namespace std;

int main(int argc, char **argv)
{
     // CREATION DU GRAPH 1 AVEC LA FONCTION BUILD
     vector<vector<float>> adj_mat{
         {0, 1, 5, 2, 0, 0},
         {0, 0, 4, 5, 0, 0},
         {0, 0, 0, 0, 3, 4},
         {0, 0, 2, 0, 5, 0},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 3}};

     Graph::WeightedGraph graph1{Graph::build_from_adjacency_matrix(adj_mat)};

     // CREATION DU GRAPH 2 AVEC ADD_VERTEX ET UNDIRECTED_EDGE
     Graph::WeightedGraph graph2{};
     graph2.add_vertex(1);
     graph2.add_undirected_edge(1, 2, 1);
     graph2.add_undirected_edge(1, 3, 1);
     graph2.add_undirected_edge(2, 3, 1);

     cout
         << "Matrice d'adjacence : " << endl
         << adj_mat << endl;

     cout << endl
          << endl
          << "Sommets + Ponderation du Graph 1 : " << endl
          << graph1;

     cout << endl
          << endl
          << "Sommets + Ponderation du Graph 2 : " << endl
          << graph2;

     bool b = (graph1 == graph2);

     cout << endl
          << endl
          << "Les deux graph sont egaux ? ";

     (b) ? cout << "OUI" : cout << "NON" << endl;

     cout << endl
          << "Sommets du graph 1 a partir de 1 (DFS) : ";
     graph1.print_DFS(1);

     // cout << endl
     //      << "Sommets du graph 1 a partir de 1 (BFS) : ";
     // graph1.print_BFS(1);

     cout << endl
          << "Sommets du graph 1 a partir de 1 (BFS + callback) : ";
     graph1.BFS(1, [](char const node_id)
                { std::cout << node_id << " "; });

     cout << endl
          << endl
          << "Dijkstra avec le graph 1 : " << endl;
     auto result{graph1.dijkstra(1, 5)};
     cout << result;
}