#include <iostream>
#include <vector>
#include <stack>
#include <string>

#include "global.hpp"

using namespace std;

int main(int argc, char **argv)
{
    string str;

    cout << "Ecrivez une chaine en notation polonaise" << endl
         << "> ";
    getline(cin, str);
    cout << endl;

    vector<string> vecString = split_string(str);
    vector<Token> vecToken = tokenize(vecString);

    // float result = npi_evaluate(vec);
    float resultString = npi_evaluate(vecString);
    float resultToken = npi_evaluate(vecToken);

    cout << "Resultat du calcul (vecteur de Strings) : " << resultString << endl;
    cout << "Resultat du calcul (vecteur de Tokens) : " << resultToken << endl;

    return 0;
}