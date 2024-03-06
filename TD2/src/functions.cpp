#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.hpp"

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &vec)
{
    if (!vec.empty())
    {
        os << vec[0];
        for (size_t i = 1; i < vec.size(); ++i)
        {
            os << " - " << vec[i];
        }
    }
    os << endl;
    return os;
}

bool is_sorted(vector<int> const &vec)
{
    return is_sorted(vec.begin(), vec.end());
}

void bubble_sort(vector<int> &vec)
{
    int nbIt = vec.size() - 1;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < nbIt; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
        nbIt--;
    }
}

void selection_sort(vector<int> &vec) {}
