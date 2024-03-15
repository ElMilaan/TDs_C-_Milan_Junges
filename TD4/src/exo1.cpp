#include <iostream>
#include <vector>

#include "global.hpp"
#include "utils.hpp"

using namespace std;

void display_vec_with_iterator(vector<int> &vec)
{
    vector<int>::iterator iterator;
    for (iterator = vec.begin(); iterator < vec.end(); iterator++)
    {
        cout << "|" << *iterator;
        if (iterator == vec.end() - 1)
        {
            cout << "|" << endl;
        }
    }
}

void find_value(vector<int> &vec, int const &value)
{
    if (find(vec.begin(), vec.end(), value) < vec.end())
    {
        cout << value << " est present dans le vecteur !" << endl;
    }
    else
    {
        cout << value << " n'est pas present dans le vecteur..." << endl;
    }
}