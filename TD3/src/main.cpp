#include <iostream>
#include <vector>
#include <stack>
#include <string>

#include "exo1.hpp"

using namespace std;

int main(int argc, char **argv)
{
    string str;

    cout << "Ecrivez une chaine en notation polonaise" << endl
         << "> ";
    getline(cin, str);
    cout << endl;

    vector<string> vec = split_string(str);

    float result = npi_evaluate(vec);

    cout << "Resultat du calcul : " << result << endl;

    return 0;
}