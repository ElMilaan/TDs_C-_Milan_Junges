#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include "global.hpp"

using namespace std;

vector<int> generate_random_vector(size_t const size, int const max);
ostream &operator<<(ostream &os, const vector<float> &vec);
ostream &operator<<(ostream &os, const vector<int> &vec);
ostream &operator<<(ostream &os, const vector<string> &vec);
ostream &operator<<(ostream &os, const unordered_map<string, vector<float>> robots);
ostream &operator<<(ostream &os, Card c);
ostream &operator<<(ostream &os, unordered_map<Card, int> card_map);