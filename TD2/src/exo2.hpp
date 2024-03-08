#include <iostream>
#include <vector>

using namespace std;

int quick_sort_partition(vector<float> &vec, int const &min, int const &max);
void quick_sort(vector<float> &vec, int const &min, int const &max);

void merge_sort(vector<float> &vec, int const &start, int const &end);
void merge_sort_merge(vector<float> &vec, int const &start, int const &end, int const &middle);