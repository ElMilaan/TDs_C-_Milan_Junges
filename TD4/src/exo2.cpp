#include <iostream>
#include <vector>
#include <algorithm>

#include "global.hpp"
#include "utils.hpp"

using namespace std;

auto const is_space = [](char letter)
{ return letter == ' '; };

__int64 nb_letters_fst_word(string const &str)
{
    auto size_word = find_if(str.begin(), str.end(), is_space);
    return distance(str.begin(), size_word);
}

void add_to_iterator(string::const_iterator &it, string::const_iterator &it_end)
{
    for (it; it < it_end; it++)
    {
    }
}

vector<string> split_string(string const &str)
{
    vector<string> vec{};
    string::const_iterator itMin{str.begin()};
    string::const_iterator itMax{find_if(str.begin(), str.end(), is_space)};
    while (itMax < str.end())
    {
        string word{};
        if (itMin != str.begin())
        {
            itMin++;                                                     // on décale itMin sur la lettre de début de mot
            add_to_iterator(itMax, find_if(itMin, str.end(), is_space)); // on incrémente iMax jusqu'au prochain espace
        }
        for (auto it = itMin; it < itMax; it++) // on remplit le mot avec les lettre avant l'espace
        {
            word += *it;
        }
        itMin = itMax; // on décale itMin jusqu'à l'espace de fin du mot
        vec.push_back(word);
    }
    return vec;
}