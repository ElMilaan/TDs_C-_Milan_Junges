#include <iostream>
#include <vector>
#include <stack>
#include <string>

#include "global.hpp"

using namespace std;

int main(int argc, char **argv)
{
     // string str;

     // cout << "Ecrivez une chaine en notation polonaise" << endl
     //      << "> ";
     // getline(cin, str);
     // cout << endl;

     // vector<string> vecString = split_string(str);
     // vector<Token> vecToken = tokenize(vecString);

     // float resultString = npi_evaluate(vecString);
     // float resultToken = npi_evaluate(vecToken);

     // cout << "Resultat du calcul (vecteur de Strings) : " << resultString << endl;
     // cout << "Resultat du calcul (vecteur de Tokens) : " << resultToken << endl;

     // Aller plus loin
     string normalExpression{"3 + 4 ^ 2 / ( 1 - 5 ) ^ 6"};
     string normalExpression2{"6 * 2 ^ 3 * 4 - ( 1 + 5 - 3 * 5 )"};

     cout << endl
          << "Expression de depart : " << normalExpression << endl;

     vector<Token> shutingYard{infix_to_npi_tokens(normalExpression)};
     vector<Token> shutingYard2{infix_to_npi_tokens(normalExpression2)};

     cout << "Expression num1 convertie en NPI : ";
     display_expression(shutingYard);

     cout << endl
          << "Expression num2 convertie en NPI : ";
     display_expression(shutingYard2);

     float resultShutingYard = npi_evaluate(shutingYard);
     float resultShutingYard2 = npi_evaluate(shutingYard2);

     cout << endl
          << "Resultat de l'operation 1 : " << resultShutingYard << endl;
     cout << "Resultat de l'operation 2 : " << resultShutingYard2 << endl;

     return 0;
}