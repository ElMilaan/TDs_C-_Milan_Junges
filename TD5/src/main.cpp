#include <iostream>
#include <vector>

#include "utils.hpp"
#include "global.hpp"

using namespace std;
static const size_t MAX = 1024;

int main(int argc, char **argv)
{
    // ---------------------------- EXERCICE 1 -----------------------------
    cout << endl
         << "============= EXERCICE 1 ==============" << endl
         << endl;

    string sentence = "Je suis une phrase";

    cout << "somme ASCII : " << folding_string_hash(sentence, MAX) << endl;
    cout << "somme ASCII ordonnée" << folding_string_ordered_hash(sentence, MAX) << endl;
}