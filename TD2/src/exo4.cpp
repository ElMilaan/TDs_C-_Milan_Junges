#include <iostream>
#include <vector>
#include "global.hpp"

using namespace std;

size_t search(vector<int> &vec, int &value, size_t const &left, size_t const &right)
{
    if (left > right)
    {
        return -1;
    }

    size_t middle = (left + right) / 2;

    if (vec[middle] == value)
    {
        return middle;
    }
    else if (value < vec[middle])
    {
        return search(vec, value, left, middle - 1);
    }
    else
    {
        return search(vec, value, middle + 1, right);
    }
}