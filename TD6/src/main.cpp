#include <iostream>
#include < vector>

#include "node.hpp"
#include "utils.hpp"

using namespace std;

int main(int argc, char **argv)
{
     int choice{};

     cout << "CHOISISSEZ L'ACTION A EFFECTUER : " << endl
          << endl
          << "0 - Quitter le programme" << endl
          << "1 - Afficher les arbres" << endl
          << "2 - Afficher les feuilles des arbres" << endl
          << "3 - Calculer la hauteur de l'arbre" << endl
          << "4 - Supprimer un enfant à l'arbre" << endl
          << "5 - Parcourir l'arbre dans l'ordre infixe" << endl
          << "6 - Parcourir l'arbre dans l'ordre prefixe" << endl
          << "7 - Parcourir l'arbre dans l'ordre postfixe" << endl
          << "8 - Retourner une reference vers le pointeur du noeud le plus a gauche de l'arbre" << endl
          << "9 - Supprimer un noeud dont on choisit la valeur" << endl
          << "10 - Supprimer un arbre entier" << endl
          << "11 - Affichage du minimum et du maximum de l'arbre" << endl
          << endl
          << "> ";

     cin >> choice;
     cout << endl;

     /* ====================== CONSTRUCTION DE DEUX ARBRES ===================== */

     Node a{20};
     a.insert(40);
     a.insert(10);
     a.left->insert(15);
     a.left->insert(5);
     a.right->insert(50);
     a.right->insert(30);
     a.right->right->insert(36);

     Node b{5};
     b.insert(2);
     b.insert(10);
     b.left->insert(20);

     /* ======================================================================== */

     switch (choice)
     {
     case 1:
          cout << "Arbre 1 : " << endl;
          pretty_print_left_right(a);

          cout << endl
               << "Arbre 2 : " << endl;
          pretty_print_left_right(b);
          break;

     case 2:
          cout << "Feuilles de l'arbre 1 : ";
          a.leaves();
          cout << endl;
          cout << "Feuilles de l'arbre 2 : ";
          b.leaves();
          cout << endl;
          break;

     case 3:
          cout << "Hauteur de l'arbre 1 : " << a.height() << endl;
          cout << "Hauteur de l'arbre 2 : " << b.height() << endl;
          break;

     case 4:
          cout << "Arbre 2 avant suppression : " << endl
               << endl;
          pretty_print_left_right(b);
          b.delete_childs();
          cout << endl
               << "Arbre 2 apres suppression : " << endl
               << endl;
          pretty_print_left_right(b);
          break;

     case 5:
          cout << "Arbre 1 : " << endl;
          pretty_print_left_right(a);
          cout << endl
               << "Parcours infixe de l'arbre 1 : ";
          a.display_infixe();
          break;

     case 6:
          cout << "Arbre 1 : " << endl;
          pretty_print_left_right(a);
          cout << endl
               << "Parcours prefixe de l'arbre 1 : " << a.prefixe();
          break;

     case 7:
          cout << "Arbre 1 : " << endl;
          pretty_print_left_right(a);
          cout << endl
               << "Parcours postfixe (recursif) de l'arbre 1 : " << a.postfixe();
          break;

     case 8:
          cout << "Arbre 1 : " << endl;
          pretty_print_left_right(a);
          cout << endl
               << "Valeur du noeud le plus a gauche : " << most_left(a)->value;
          break;

     case 9:
          int value_to_delete{};
          cout << "Choisissez une valeur a supprimer de l'arbre : " << endl
               << "> ";
          cin >> value_to_delete;
          // remove(a, value_to_delete);
          break;

          // case 10:
          //      break;

          // case 11:
          //      break;
          // }

          // cout << endl;
     }
}