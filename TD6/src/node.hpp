#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};

    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_childs();
    void display_infixe() const;
};

// EXERCICE 1

void pretty_print_left_right(Node const &node, string const &prefix, bool is_left);
void pretty_print_left_right(Node const &node);

Node *create_node(int value);
