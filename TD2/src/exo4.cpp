#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &vec, int &value, int const &left, int const &right)
{
    if (left > right)
    {
        return -1;
    }

    int middle = (left + right) / 2;

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