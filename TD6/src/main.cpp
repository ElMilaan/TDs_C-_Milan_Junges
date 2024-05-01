#include <iostream>
#include < vector>

#include "node.hpp"
#include "utils.hpp"

using namespace std;

int main(int argc, char **argv)
{
     /* ====================== CONSTRUCTION DE L'ARBRE ===================== */

     Node *a{create_node(5)};
     a->insert(3);
     a->insert(7);
     a->insert(2);
     a->insert(4);
     a->insert(6);
     a->insert(8);
     a->insert(1);
     a->insert(9);
     a->insert(0);

     int value_to_remove{7}; // pour tester la suppression d'une valeur de l'arbre dans le cas 9

     /* ======================================================================== */

     int choice{};
     bool stop{0};

     while (!stop)
     {
          cout << "CHOISISSEZ L'ACTION A EFFECTUER : " << endl
               << endl
               << "0 - Quitter le programme" << endl
               << "1 - Afficher les arbres" << endl
               << "2 - Afficher les feuilles des arbres" << endl
               << "3 - Calculer la hauteur de l'arbre" << endl
               << "4 - Supprimer un enfant de l'arbre" << endl
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

          switch (choice)
          {
          case 0:
               stop = !stop;
               break;

          case 1:
               cout << "Arbre : " << endl;
               pretty_print_left_right(*a);
               break;

          case 2:
               cout << "Feuilles de l'arbre : ";
               a->leaves();
               cout << endl;
               break;

          case 3:
               cout << "Hauteur de l'arbre : " << a->height() << endl;
               break;

          case 4:
               cout << "Arbre avant suppression : " << endl
                    << endl;
               pretty_print_left_right(*a);
               a->delete_childs();
               cout << endl
                    << "Arbre apres suppression : " << endl
                    << endl;
               pretty_print_left_right(*a);
               break;

          case 5:
               cout << "Arbre : " << endl;
               pretty_print_left_right(*a);
               cout << endl
                    << "Parcours infixe de l'arbre : ";
               a->display_infixe();
               break;

          case 6:
               cout << "Arbre : " << endl;
               pretty_print_left_right(*a);
               cout << endl
                    << "Parcours prefixe de l'arbre : " << a->prefixe();
               break;

          case 7:
               cout << "Arbre : " << endl;
               pretty_print_left_right(*a);
               cout << endl
                    << "Parcours postfixe (recursif) de l'arbre : " << a->postfixe();
               break;

          case 8:
               cout << "Arbre : " << endl;
               pretty_print_left_right(*a);
               cout << endl
                    << "Valeur du noeud le plus a gauche : " << most_left(a)->value;
               break;

          case 9:
               cout << "Arbre : " << endl;
               pretty_print_left_right(*a);
               remove(a, value_to_remove);
               cout << endl
                    << "Arbre apres suppression de la valeur " << value_to_remove << " : " << endl
                    << endl;
               pretty_print_left_right(*a);
               break;

          case 10:
               cout << "Arbre : " << endl;
               pretty_print_left_right(*a);
               cout << endl
                    << "Suppression de l'arbre entier : " << endl;
               delete_tree(a);
               pretty_print_left_right(*a);
               break;

          case 11:
               cout << "Arbre : " << endl;
               pretty_print_left_right(*a);
               cout << endl
                    << "Valeur max de l'arbre = " << a->max();
               cout << endl
                    << "Valeur min de l'arbre = " << a->min();
               break;
          }
     }
}