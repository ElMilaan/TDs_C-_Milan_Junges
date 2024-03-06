#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec{10, 3, 6, 9, 112, 293, 1, 8, 32};

    cout << "Vecteur de base : " << vec;

    bubble_sort(vec);

    cout << "Vecteur trie (bulle) : " << vec;

    return 0;
}
