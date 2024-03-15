#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &vec);
ostream &operator<<(ostream &os, const vector<float> &vec);

bool is_sorted(vector<int> const &vec);
bool is_sorted(vector<float> const &vec);

void display_exo(int exNumber);

vector<int> generate_random_vectorInt(size_t const size, int const max = 100);
vector<float> generate_random_vectorFloat(size_t const size, int const max = 100);