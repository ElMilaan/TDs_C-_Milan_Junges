#include <iostream>
#include <vector>

using namespace std;

/* *********** TRI BULLE ************* */

void bubble_sort(vector<int> &vec)
{
    int nbIt = vec.size() - 1;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < nbIt; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
        nbIt--;
    }
}

/* *********** TRI SELECTION ************* */

void selection_sort(vector<int> &vec)
{
    int max{};
    int index{};
    int nbIt = vec.size();
    for (int i = 0; i < vec.size(); i++)
    {
        max = vec[0];
        index = 0;
        for (int j = 0; j < nbIt; j++)
        {
            if (vec[j] > max)
            {
                max = vec[j];
                index = j;
            }
            if (j == nbIt - 1)
            {
                vec[index] = vec[j];
                vec[j] = max;
            }
        }
        nbIt--;
    }
}