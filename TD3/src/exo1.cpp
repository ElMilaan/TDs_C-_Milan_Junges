#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>

#include "global.hpp"
using namespace std;

vector<string> split_string(string const &str)
{
    istringstream in(str);
    return vector<string>(istream_iterator<string>(in), istream_iterator<string>());
}

bool is_floating(string const &str)
{
    for (char c : str)
    {
        if (!(isdigit(c) || c == '.'))
        {
            return false;
        }
    }
    return true;
}

void operation(stack<float> &stk, char const &op)
{
    float res{};
    float f1 = stk.top();
    stk.pop();
    float f2 = stk.top();
    stk.pop();

    switch (op)
    {
    case '+':
        res = f2 + f1;
        break;
    case '-':
        res = f2 - f1;
        break;
    case '*':
        res = f2 * f1;
        break;
    case '/':
        res = f2 / f1;
        break;
    }
    stk.push(res);
}

float npi_evaluate(vector<string> const &tokens)
{
    stack<float> stk{};
    for (int i{0}; i < tokens.size(); i++)
    {
        if (is_floating(tokens[i]))
        {
            stk.push(stof(tokens[i]));
        }
        else
        {
            if (stk.size() <= 1)
            {
                cout << "Expression impossible : pas assez d'opérandes" << endl;
                return 0;
            }
            operation(stk, tokens[i][0]);
        }
    }
    return stk.top();
}
