#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};

    bool is_leaf() const;
    void leaves() const;
    void insert(int value);
    int height() const;
    void delete_childs();
    void display_infixe();
    void prefixe(vector<int> &vec);
    vector<int> prefixe();
    void postfixe(vector<int> &vec);
    vector<int> postfixe();
    int has_one_child(); // return 0 si n'a pas un seul enfant, 1 s'il n'a qu'un fils gauche, 2 s'il n'a qu'un fils droit
};

// EXERCICE 1

void pretty_print_left_right(Node const &node, string const &prefix, bool is_left);
void pretty_print_left_right(Node const &node);

Node *create_node(int value);
Node *&most_left(Node *&node);

void remove_with_two_children(Node *&node, int &smallest);
void remove_with_one_children(Node *&node);
bool remove(Node *&node, int value);
bool remove(Node *&node);