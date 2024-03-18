#include <iostream>
#include <global.hpp>

using namespace std;

void counting_sort(vector<int> &vec, int const max)
{
    vector<pair<int, int>> pairs{}; // first -> la valeur, second -> le nombre d'occurences de cette valeur
    // je rempli mon tableau de paires en incrémentant le nombre d'occurence à chaque fois que la valeur correspondante est trouvée dans le tableau à trier.
    for (int i{0}; i <= max; i++)
    {
        pairs.push_back(pair{i, 0});
        for (int j : vec)
        {
            if (j == i)
            {
                pairs[i].second++;
            }
        }
    }

    int n{0};
    int index{0};
    // Je rempli le tableau de départ grâce au nombre d'occurences trouvé pour chaque valeur
    // (en bouclant sur ce nombre pour ajouter le bon nombre de fois la valeur)
    while (n < pairs.size())
    {
        if (pairs[n].second > 0)
        {
            for (int i{0}; i < pairs[n].second; i++)
            {
                vec[index] = pairs[n].first;
                index++;
            }
        }
        n++;
    }
}