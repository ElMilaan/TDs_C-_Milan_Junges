#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "global.hpp"

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

ostream &operator<<(ostream &os, const unordered_map<string, vector<float>> robots)
{
    for (pair p : robots)
    {
        os << "( " << p.first << " , " << p.second << " )" << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, Card c)
{
    os << card_name(c) << " : " << c.hash();
    return os;
}

ostream &operator<<(ostream &os, unordered_map<Card, int> card_map)
{
    for (pair p : card_map)
    {
        os << p.first << " : " << p.second << endl;
    }
    return os;
}
