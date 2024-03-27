#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

using namespace std;

std::string random_name(size_t size)
{
    string name{""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        name.push_back('A' + rand() % 26);
    }
    return name;
}

vector<pair<string, float>> get_robots_fix(size_t size)
{
    vector<pair<string, float>> robots_fix{};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        // random name
        string robotName{random_name(2)};
        // random cost
        float cost{static_cast<float>(rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(make_pair(robotName, cost));
    }
    return robots_fix;
}

unordered_map<string, vector<float>> fixList(vector<pair<string, float>> &vec)
{
    unordered_map<string, vector<float>> result{};
    string name = vec[0].first;
    vector<float> fix{};
    for (pair p : vec)
    {
        if (p.first == name)
        {
            fix.push_back(p.second);
        }
        else
        {
            result.insert({name, fix});
            name = p.first;
            fix = {};
        }
    }
    return result;
}