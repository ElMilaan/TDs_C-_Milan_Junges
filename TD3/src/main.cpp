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

     float resultString = npi_evaluate(vecString);
     float resultToken = npi_evaluate(vecToken);

     cout << "Resultat du calcul (vecteur de Strings) : " << resultString << endl;
     cout << "Resultat du calcul (vecteur de Tokens) : " << resultToken << endl;

     // Aller plus loin
     string normalExpression{"3 + 4 ^ 2 / ( 1 - 5 ) ^ 6"};
     cout << endl
          << "Expression de depart : " << normalExpression << endl;
     cout << endl
          << "Ecrivez une expression de calcul classique : " << endl
          << "> ";

     vector<Token> shutingYard{infix_to_npi_tokens(normalExpression)};

     cout << "Expression convertie en NPI : ";
     display_expression(shutingYard);
     float resultShutingYard = npi_evaluate(shutingYard);

     cout << endl
          << "Resultat de l'operation : " << resultShutingYard << endl;

     return 0;
}