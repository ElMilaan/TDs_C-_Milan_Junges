#include <iostream>
#include <vector>
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
        result = (result + s[i] * (i + 1)) % max;
    }
    return result;
}