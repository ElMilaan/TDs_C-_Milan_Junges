#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

#include "utils.hpp"
#include "global.hpp"

using namespace std;

int main(int argc, char **argv)
{
     /* ------------------------------------ EXERCICE 1 ------------------------------------ */

     cout << endl
          << "=========================== EXO 1 =============================" << endl
          << endl;

     vector<int> vec{generate_random_vector(5, 100)};

     cout << "Le vecteur affiche par iterateur : ";
     display_vec_with_iterator(vec);

     int value{50};
     find_value(vec, value);

     cout << "Il y a " << count(vec.begin(), vec.end(), value) << " fois " << value << " dans le vecteur" << endl;

     sort(vec.begin(), vec.end());

     cout << "La somme des elements du vecteur est : " << accumulate(vec.begin(), vec.end(), 0) << endl;

     /* ------------------------------------ EXERCICE 2 ------------------------------------ */

     cout << endl
          << "=========================== EXO 2 =============================" << endl
          << endl;

     string str{};

     cout << "Ecris une phrase : " << endl
          << "> ";
     // getline(cin, str);

     str = "je suis joie";

     __int64 nbLettersFstWord = nb_letters_fst_word(str);
     cout << "Le premier mot de la phrase est un mot de " << nbLettersFstWord << " lettres !" << endl;

     vector<string> vec_string = split_string(str);
     cout << "Le vecteur obtenu a partir de la phrase : " << vec_string << endl;

     /* ------------------------------------ EXERCICE 3 ------------------------------------ */

     cout << endl
          << "=========================== EXO 3 =============================" << endl
          << endl;

     string tab[]{"kayak", "pourquoi", "sympathique", "ete", "elle"};
     for (string str : tab)
     {
          is_palindrome(str) ? cout << "- " << str << " est un palindrome" << endl : cout << "- " << str << " n'est pas un palindrome" << endl;
     }
}