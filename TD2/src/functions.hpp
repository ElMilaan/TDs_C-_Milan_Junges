#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &vec);

bool is_sorted(std::vector<int> const &vec);

void bubble_sort(std::vector<int> &vec);
void selection_sort(std::vector<int> &vec);