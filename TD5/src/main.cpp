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

     vector<pair<string, float>> robots{get_robots_fix(50)};

     unordered_map<string, vector<float>> robots_map{robots_fixes_map(robots)};

     cout << robots_map << endl;

     cout << "Liste des robots avec la sommes de leurs reparations : " << endl
          << endl;
     get_robots_fix(robots_map);

     // ---------------------------- EXERCICE 3 -----------------------------

     cout << endl
          << "============= EXERCICE 3 ==============" << endl
          << endl;

     vector<Card> cards = get_cards(100);

     unordered_map<Card, int> cards_map{get_card_map(cards)};

     cout << cards_map;
}