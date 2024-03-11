#include <iostream>
#include <vector>

using namespace std;

// EXERCICE 1
void bubble_sort(vector<int> &vec);
void selection_sort(vector<int> &vec);

// EXERCICE 2
int quick_sort_partition(vector<float> &vec, int const &min, int const &max);
void quick_sort(vector<float> &vec, int const &min, int const &max);

void merge_sort(vector<float> &vec, int const &start, int const &end);
void merge_sort_merge(vector<float> &vec, int const &start, int const &end, int const &middle);

// EXERCICE 4
struct Paire
{
    int searchValue;
    vector<int> vec;
};

int search(vector<int> &vec, int &value, int const &left, int const &right);