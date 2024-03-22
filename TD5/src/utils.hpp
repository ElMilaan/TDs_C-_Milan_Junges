#include <iostream>
#include <vector>

using namespace std;

vector<int> generate_random_vector(size_t const size, int const max);
ostream &operator<<(ostream &os, const vector<int> &vec);
ostream &operator<<(ostream &os, const vector<string> &vec);