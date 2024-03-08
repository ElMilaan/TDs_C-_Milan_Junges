#include <iostream>
#include <vector>

using namespace std;

struct Paire
{
    int searchValue;
    vector<int> vec;
};

int search(vector<int> &vec, int &value, int const &left, int const &right);