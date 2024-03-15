#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &vec)
{
    if (!vec.empty())
    {
        for (size_t i = 0; i < vec.size(); ++i)
        {
            os << "|" << vec[i];
        }
        os << "|";
    }
    return os;
}

ostream &operator<<(ostream &os, const vector<float> &vec)
{
    if (!vec.empty())
    {
        for (size_t i = 0; i < vec.size(); ++i)
        {
            os << "|" << vec[i];
        }
        os << "|";
    }
    return os;
}

bool is_sorted(vector<int> const &vec)
{
    return is_sorted(vec.begin(), vec.end());
}

bool is_sorted(vector<float> const &vec)
{
    return is_sorted(vec.begin(), vec.end());
}

void display_exo(int exNumber)
{
    cout << endl
         << endl
         << "========== EXO " << exNumber << " ==========" << endl
         << endl;
}

vector<int> generate_random_vectorInt(size_t const size, int const max)
{
    vector<int> vec(size);
    generate(vec.begin(), vec.end(), [&max]()
             { return rand() % max; });
    return vec;
}

vector<float> generate_random_vectorFloat(size_t const size, int const max)
{
    vector<float> vec(size);
    generate(vec.begin(), vec.end(), [&max]()
             { return rand() % max; });
    return vec;
}