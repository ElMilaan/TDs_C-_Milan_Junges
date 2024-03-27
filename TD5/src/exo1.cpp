#include <iostream>
#include <vector>
#include <math.h>
#include "global.hpp"

using namespace std;

size_t folding_string_hash(string const &s, size_t max)
{
    size_t result{};
    for (char c : s)
    {
        result = (result + c) % max;
    }
    return result;
}

size_t folding_string_ordered_hash(std::string const &s, size_t max)
{
    int result{};
    for (int i = 0; i < s.size(); i++)
    {
        result += s[i] * (i + 1);
    }
    return result % max;
}

size_t polynomial_rolling_hash(const string &s, size_t p, size_t m)
{
    int result{0};
    for (size_t i{0}; i < s.size(); i++)
    {
        result += int(s[i] * pow(p, i)) % m;
    }
    return result % m;
}