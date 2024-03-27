#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>

#include "global.hpp"
using namespace std;

Operator to_operator(char c)
{
    switch (c)
    {
    case '+':
        return Operator::ADD;
    case '-':
        return Operator::SUB;
    case '*':
        return Operator::MUL;
    case '/':
        return Operator::DIV;
    case '^':
        return Operator::POW;
    case '(':
        return Operator::OPEN_PAREN;
    case ')':
        return Operator::CLOSE_PAREN;
    }
}

char to_char(Operator &op)
{
    switch (op)
    {
    case Operator::ADD:
        return '+';
    case Operator::SUB:
        return '-';
    case Operator::MUL:
        return '*';
    case Operator::DIV:
        return '/';
    case Operator::POW:
        return '^';
    case Operator::OPEN_PAREN:
        return '(';
    case Operator::CLOSE_PAREN:
        return ')';
    }
}

size_t operator_precedence(Operator const op)
{
    switch (op)
    {
    case Operator::ADD:
        return 1;

    case Operator::SUB:
        return 1;

    case Operator::MUL:
        return 2;

    case Operator::DIV:
        return 2;

    case Operator::POW:
        return 3;

    case Operator::OPEN_PAREN:
        return 0;

    case Operator::CLOSE_PAREN:
        return 4;
    }
    return -1;
}

// pas tres util mais maintenant qu'elle est codée...^^
bool priority(Operator inStk, Operator toAdd)
{
    if (operator_precedence(inStk) > operator_precedence(toAdd) && operator_precedence(toAdd) != 0)
    {
        return true;
    }
    return false;
}

void add_operator(vector<Token> &result, stack<Token> &stk, char const &c)
{
    Operator toCheck = to_operator(c);
    size_t prio = operator_precedence(toCheck);
    if (stk.empty())
    {
        stk.push(make_token(toCheck));
    }
    else if (prio < 4)
    {
        if (priority(stk.top().op, toCheck))
        {
            result.push_back(stk.top());
            stk.pop();
        }
        stk.push(make_token(toCheck));
    }
    else
    {
        while (operator_precedence(stk.top().op) != 0)
        {
            result.push_back(stk.top());
            stk.pop();
        }
        stk.pop();
    }
}

vector<Token> infix_to_npi_tokens(string const &expression)
{
    stack<Token> operatorStk{};
    vector<Token> result{};
    for (char c : expression)
    {
        if (isdigit(c))
        {
            result.push_back(make_token(float(c - '0')));
        }
        else if (c != ' ')
        {
            add_operator(result, operatorStk, c);
        }
    }
    while (!operatorStk.empty())
    {
        result.push_back(operatorStk.top());
        operatorStk.pop();
    }
    return result;
}

void display_expression(vector<Token> &vec)
{
    for (Token t : vec)
    {
        if (t.type == TokenType::OPERAND)
        {
            cout << t.value << " ";
        }
        else
        {
            cout << to_char(t.op) << " ";
        }
    }
}