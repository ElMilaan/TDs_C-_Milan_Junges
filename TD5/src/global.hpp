#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// EXERCICE 1
size_t folding_string_hash(string const &s, size_t max);
size_t folding_string_ordered_hash(string const &s, size_t max);
size_t polynomial_rolling_hash(const string &s, size_t p, size_t m);

// EXERCICE 2
vector<pair<string, float>> get_robots_fix(size_t size);
unordered_map<string, vector<float>> fixList(vector<pair<string, float>> &vec);