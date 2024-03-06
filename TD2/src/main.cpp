#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec{10, 3, 6, 9, 112, 293, 1, 8, 32};

    cout << "Vecteur de base : " << vec;

    cout << "Vecteur trie (bulle) : " << bubble_sort(vec);

    cout << "Vecteur trie (selection) : " << selection_sort(vec);

    return 0;
}
