#include <iostream>
#include <vector>
#include <algorithm>

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

ostream &operator<<(ostream &os, const vector<string> &vec)
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

vector<int> generate_random_vector(size_t const size, int const max)
{
    vector<int> vec(size);
    generate(vec.begin(), vec.end(), [&max]()
             { return rand() % max; });
    return vec;
}