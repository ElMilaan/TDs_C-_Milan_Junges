#include <iostream>
#include <vector>

using namespace std;

// EXERCICE 1
void bubble_sort(vector<int> &vec);
void selection_sort(vector<int> &vec);

// EXERCICE 2
size_t quick_sort_partition(vector<float> &vec, size_t const &min, size_t const &max);
void quick_sort(vector<float> &vec);
void quick_sort(vector<float> &vec, size_t const &min, size_t const &max);

void merge_sort_merge(vector<float> &vec, size_t const left, size_t const right, size_t const middle);
void merge_sort(vector<float> &vec);
void merge_sort(vector<float> &vec, size_t const left, size_t const right);

// EXERCICE 4
struct Paire
{
    int searchValue;
    vector<int> vec;
};

size_t search(vector<int> &vec, int &value, size_t const &left, size_t const &right);