#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <numeric>

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

unordered_map<string, vector<float>> robots_fixes_map(vector<pair<string, float>> const &robots_fixes)
{
    unordered_map<string, vector<float>> result{};
    for (pair p : robots_fixes)
    {
        // si le nom a déjà été rencontré
        if (result.find(p.first) != result.end())
        {
            result[p.first].push_back(p.second);
        }
        else
        {
            result.insert({p.first, {p.second}});
        }
    }
    return result;
}

float float_sum(vector<float> &vec)
{
    return float(accumulate(vec.begin(), vec.end(), 0));
}

void display_sum_fixes(unordered_map<string, vector<float>> &map)
{
    for (pair p : map)
    {
        cout << p.first << " , " << float_sum(p.second) << endl;
    }
}