#include <iostream>
#include <vector>
#include <algorithm>
#include "exo1.hpp"
#include "exo2.hpp"
#include "exo4.hpp"
#include "utils.hpp"
#include "ScopedTimer.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
     vector<int> vecI = generate_random_vectorInt(10);
     vector<float> vecF = generate_random_vectorFloat(10);

     // ------------ TEST EXERCICE 1 -------------

     display_exo(1);

     // Tri Bulle
     cout << endl
          << "Vecteur de base : " << vecI << endl;

     bubble_sort(vecI);
     cout << "Tri bulle : " << vecI;
     (is_sorted(vecI)) ? cout << " = Vecteur trie" << endl : cout << " = Vecteur non trie";

     // Tri Selection
     vecI = generate_random_vectorInt(10);

     cout << endl
          << "Vecteur de base : " << vecI << endl;

     selection_sort(vecI);
     cout << "Tri selection : " << vecI;
     (is_sorted(vecI)) ? cout << " = Vecteur trie" << endl : cout << " = Vecteur non trie";

     // ------------ TEST EXERCICE 2 -------------

     display_exo(2);

     cout << endl
          << "Vecteur de base : " << vecF << endl;

     quick_sort(vecF, 0, vecF.size() - 1);
     cout << "Tri Rapide : " << vecF;
     (is_sorted(vecF)) ? cout << " = Vecteur trie" << endl : cout << " = Vecteur non trie";

     // vecF = generate_random_vectorFloat(10, 100);

     // cout << endl
     //      << "Vecteur de base : " << vecF << endl;

     // merge_sort(vecF, 0, vecF.size() - 1);
     // cout << "Tri Fusion : " << vecF;
     // (is_sorted(vecF)) ? cout << " = Vecteur trie" << endl : cout << " = Vecteur non trie";

     // ------------ TEST EXERCICE 3 -------------

     display_exo(3);

     vector<int> vecIntTest{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
     vector<float> vecFloatTest{10.8, 3.5, 2.9, 2.7, 2.1, 1.4, 1.32, 1.11, 1.01, 0.3};
     {
          ScopedTimer timer("Sort - Standard Library");
          sort(vecIntTest.begin(), vecIntTest.end());
     }

     vecIntTest = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

     {
          ScopedTimer timer("Sort - Bubble Sort");
          bubble_sort(vecIntTest);
     }

     vecIntTest = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

     {
          ScopedTimer timer("Sort - Selection Sort");
          selection_sort(vecI);
     }

     {
          ScopedTimer timer("Sort - Tri Rapide");
          sort(vecFloatTest.begin(), vecFloatTest.end());
     }
     // {
     //      ScopedTimer timer("Sort - Tri Fusion");
     //      sort(vecF.begin(), vecF.end());
     // }

     cout << endl
          << "Que constatez-vous ? - On voit que les differents algorithmes ont un temps d'execution different" << endl
          << "Que pouvez-vous dire ? - Certains algorithmes de tri sont plus efficaces que d'autres (bubble est le plus efficace ici)" << endl
          << "Cependant, avec un bien plus grand jeu de donnees dans nos vecteurs, les algorithmes de tri recursifs seront plus efficaces";

     // ------------ TEST EXERCICE 4 -------------

     display_exo(4);

     // Liste de tous les tableaux avec comme dernière valeur la valeur recherchée
     Paire tab[]{
         {8, {1, 2, 2, 3, 4, 8, 12}},
         {15, {1, 2, 3, 3, 6, 14, 12, 15}},
         {16, {2, 2, 3, 4, 5, 8, 12, 15, 16}},
         {6, {5, 6, 7, 8, 9, 10, 11, 12, 13}},
         {10, {1, 2, 3, 4, 5, 6, 7, 8, 9}}};

     int res{};

     for (int i = 0; i < 5; i++)
     {
          cout << "- Vecteur : " << tab[i].vec << " - Valeur recherchee : " << tab[i].searchValue;

          res = search(tab[i].vec, tab[i].searchValue, 0, tab[i].vec.size() - 1);

          (res != -1) ? cout << endl
                             << "Valeur trouvee ! Son indice est " << res << endl
                             << endl
                      : cout << endl
                             << "La valeur demandee n'est pas dans le tableau" << endl
                             << endl;
     }

     return 0;
}
