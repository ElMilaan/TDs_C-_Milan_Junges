#include <iostream>
#include "node.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Node a{3};
    Node b{5};
    b.insert(2);
    b.insert(3);
    b.insert(10);
    b.left->insert(20);

    cout << "Noeud a : " << endl;
    pretty_print_left_right(a);

    cout << endl
         << "Noeud b : " << endl;
    pretty_print_left_right(b);

    cout << endl
         << "a est une feuille ? ";
    a.is_leaf() ? cout << "OUI" : cout << "NON";

    cout << endl
         << "b est une feuille ? ";
    b.is_leaf() ? cout << "OUI" : cout << "NON" << endl;

    cout << endl
         << "Hauteur de b : " << b.height() << endl;

    b.delete_childs();

    cout << endl
         << "Noeud b apres suppression de ses enfants : " << endl;
    pretty_print_left_right(b);
}