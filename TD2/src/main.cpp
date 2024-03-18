#include <iostream>
#include <vector>
#include <algorithm>

#include "global.hpp"
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

     quick_sort(vecF);
     cout << "Tri Rapide : " << vecF;
     (is_sorted(vecF)) ? cout << " = Vecteur trie" << endl : cout << " = Vecteur non trie";

     vecF = generate_random_vectorFloat(10, 100);

     cout << endl
          << "Vecteur de base : " << vecF << endl;

     merge_sort(vecF);
     cout << "Tri Fusion : " << vecF;
     (is_sorted(vecF)) ? cout << " = Vecteur trie" << endl : cout << " = Vecteur non trie";

     // ------------ TEST EXERCICE 3 -------------

     display_exo(3);

     vector<int> vecIntTest{generate_random_vectorInt(10, 100)};
     vector<float> vecFloatTest{generate_random_vectorFloat(10, 100)};
     {
          ScopedTimer timer("Sort - Standard Library");
          sort(vecIntTest.begin(), vecIntTest.end());
     }

     vecIntTest = generate_random_vectorInt(10, 100);

     {
          ScopedTimer timer("Sort - Bubble Sort");
          bubble_sort(vecIntTest);
     }

     vecIntTest = generate_random_vectorInt(10, 100);

     {
          ScopedTimer timer("Sort - Selection Sort");
          selection_sort(vecIntTest);
     }

     {
          ScopedTimer timer("Sort - Tri Rapide");
          quick_sort(vecFloatTest);
     }

     vecFloatTest = generate_random_vectorFloat(10, 1000);

     {
          ScopedTimer timer("Sort - Tri Fusion");
          merge_sort(vecFloatTest);
     }

     cout << endl
          << "Que constatez-vous ? - On voit que les differents algorithmes ont un temps d'execution different" << endl
          << "Que pouvez-vous dire ? - Certains algorithmes de tri sont plus efficaces que d'autres" << endl
          << "Cependant, avec un bien plus grand jeu de donnees dans nos vecteurs, les algorithmes de tri recursifs seront plus efficaces";

     // ------------ TEST EXERCICE 4 -------------

     display_exo(4);

     // Liste de tous les tableaux associé à la valeur recherchée
     vector<pair<int, vector<int>>> tab{
         {8, {1, 2, 2, 3, 4, 8, 12}},
         {15, {1, 2, 3, 3, 6, 14, 12, 15}},
         {16, {2, 2, 3, 4, 5, 8, 12, 15, 16}},
         {6, {5, 6, 7, 8, 9, 10, 11, 12, 13}},
         {10, {1, 2, 3, 4, 5, 6, 7, 8, 9}}};

     size_t res{};

     for (int i = 0; i < 5; i++)
     {
          cout << "- Vecteur : " << tab[i].second << " - Valeur recherchee : " << tab[i].first;

          res = search(tab[i].second, tab[i].first, 0, tab[i].second.size() - 1);

          (res != -1) ? cout << endl
                             << "Valeur trouvee ! Son indice est " << res << endl
                             << endl
                      : cout << endl
                             << "La valeur demandee n'est pas dans le tableau" << endl
                             << endl;
     }

     // ------------ TEST COUNTING_SORT -------------

     cout << "--------------- COUNTING SORT -----------------" << endl
          << endl;

     vector<int> vec{9, 7, 3, 4, 3, 6, 9, 1, 7, 9, 9, 3};

     cout << "Le vecteur de base : " << vec << endl;

     counting_sort(vec, 9);

     cout << "Le vecteur trie : " << vec << endl;

     return 0;
}
