#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// EXERCICE 1
vector<string> split_string(string const &s);

bool is_floating(string const &s);

void operation(stack<float> &stk, char const &op);

float npi_evaluate(vector<string> const &tokens);

// EXERCICE 2
enum class Operator
{
    ADD,
    SUB,
    MUL,
    DIV,
    POW,
    OPEN_PAREN,
    CLOSE_PAREN
};
enum class TokenType
{
    OPERATOR,
    OPERAND
};
struct Token
{
    TokenType type;
    float value;
    Operator op;
};

Token make_token(float value);
Token make_token(Operator op);

vector<Token> tokenize(vector<string> const &words);

void operation(stack<float> &stk, Operator &op);
float npi_evaluate(vector<Token> const &tokens);

// EXERCICE 3
size_t operator_precedence(Operator const op);
vector<Token> infix_to_npi_tokens(string const &expression);
void display_expression(vector<Token> &vec);