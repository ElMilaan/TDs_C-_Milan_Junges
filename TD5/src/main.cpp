#include <iostream>
#include <vector>
#include <unordered_map>

#include "utils.hpp"
#include "global.hpp"

using namespace std;
static const size_t MAX = 2048;

int main(int argc, char **argv)
{
    // ---------------------------- EXERCICE 1 -----------------------------
    cout << endl
         << "============= EXERCICE 1 ==============" << endl
         << endl;

    string sentence = "Jhd hde hjs";

    cout << "somme ASCII : " << folding_string_hash(sentence, MAX) << endl;
    cout << "somme ASCII ordonnee : " << folding_string_ordered_hash(sentence, MAX) << endl;
    cout << "Polynomial Rolling Hash : " << polynomial_rolling_hash(sentence, 21, MAX) << endl;

    // ---------------------------- EXERCICE 2 -----------------------------
    cout << endl
         << "============= EXERCICE 2 ==============" << endl
         << endl;

    auto robots{get_robots_fix(15)};

    for (pair p : robots)
    {
        cout << "( " << p.first << " , " << p.second << " )" << endl;
    }

    unordered_map<string, vector<float>> robots_map{fixList(robots)};

    cout << robots_map << endl;
}