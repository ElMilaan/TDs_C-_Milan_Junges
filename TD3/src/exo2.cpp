#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>

#include "global.hpp"

using namespace std;

Token make_token(float value)
{
    Token tkn{TokenType::OPERAND, value};
    return tkn;
}

Token make_token(Operator op)
{
    Token tkn{TokenType::OPERATOR, 0, op};
    return tkn;
}

vector<Token> tokenize(vector<string> const &words)
{
    vector<Token> vec{};
    for (string str : words)
    {
        if (is_floating(str))
        {
            vec.push_back(make_token(stof(str)));
        }
        else
        {
            switch (str[0])
            {
            case '+':
                vec.push_back(make_token(Operator::ADD));
                break;
            case '-':
                vec.push_back(make_token(Operator::SUB));
                break;
            case '*':
                vec.push_back(make_token(Operator::MUL));
                break;
            case '/':
                vec.push_back(make_token(Operator::DIV));
                break;
            case '^':
                vec.push_back(make_token(Operator::POW));
                break;
            case '(':
                vec.push_back(make_token(Operator::OPEN_PAREN));
                break;
            case ')':
                vec.push_back(make_token(Operator::CLOSE_PAREN));
                break;
            }
        }
    }
    return vec;
}

void operation(stack<float> &stk, Operator &op)
{
    float res{};
    float f1 = stk.top();
    stk.pop();
    float f2 = stk.top();
    stk.pop();

    switch (op)
    {
    case Operator::ADD:
        res = f2 + f1;
        break;
    case Operator::SUB:
        res = f2 - f1;
        break;
    case Operator::MUL:
        res = f2 * f1;
        break;
    case Operator::DIV:
        res = f2 / f1;
        break;
    case Operator::POW:
        res = pow(f2, f1);
        break;
    }
    stk.push(res);
}

float npi_evaluate(vector<Token> const &tokens)
{
    stack<float> stk{};
    for (Token tkn : tokens)
    {
        if (tkn.type == TokenType::OPERAND)
        {
            stk.push(tkn.value);
        }
        else
        {
            if (stk.size() <= 1)
            {
                cout << "Expression impossible : pas assez d'opérandes" << endl;
                return 0;
            }
            operation(stk, tkn.op);
        }
    }
    return stk.top();
}