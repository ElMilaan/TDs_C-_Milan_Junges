#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<string> split_string(string const &s);

bool is_floating(string const &s);

void operation(stack<float> &stk, char const &op);

float npi_evaluate(vector<string> const &tokens);
