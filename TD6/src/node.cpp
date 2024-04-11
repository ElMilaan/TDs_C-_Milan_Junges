#include <iostream>
#include <vector>
#include "node.hpp"

using namespace std;

void pretty_print_left_right(Node const &node, string const &prefix, bool is_left)
{
    if (node.right)
    {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << endl;
    if (node.left)
    {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const &node)
{
    pretty_print_left_right(node, "", true);
}

Node *create_node(int value)
{
    return new Node{value, nullptr, nullptr};
}

bool Node::is_leaf() const
{
    return (left == nullptr && right == nullptr);
}

void Node::leaves() const
{
    if (is_leaf())
        cout << value << " | ";
    if (left != nullptr)
    {
        left->leaves();
    }
    if (right != nullptr)
    {
        right->leaves();
    }
}

void Node::insert(int val)
{
    (val < value) ? left = create_node(val) : right = create_node(val);
}

int Node::height() const
{
    if (is_leaf())
    {
        return 1;
    }

    int leftHeight{0}, righHeight{0};

    if (left != nullptr)
    {
        leftHeight = 1 + left->height();
    }
    if (right != nullptr)
    {
        righHeight = 1 + right->height();
    }

    return (leftHeight > righHeight)
               ? leftHeight
               : righHeight;
}

void Node::delete_childs()
{
    if (left == nullptr || right == nullptr)
    {
        return;
    }

    left->delete_childs();
    right->delete_childs();

    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
}

void Node::display_infixe()
{
    if (this == nullptr)
        return;

    left->display_infixe();

    cout << this->value << " | ";

    right->display_infixe();
}

void Node::prefixe(vector<int> &vec)
{
    vec.push_back(value);

    if (left != nullptr)
    {
        left->prefixe(vec);
    }

    if (right != nullptr)
    {
        right->prefixe(vec);
    }
}

vector<int> Node::prefixe()
{
    vector<int> vec{};
    if (this != nullptr)
        prefixe(vec);
    return vec;
}

void Node::postfixe(vector<int> &vec)
{
    if (this == nullptr)
        return;

    left->postfixe();

    right->postfixe();

    cout << value << " | ";
}

vector<int> Node::postfixe()
{
    vector<int> vec{};
    if (this != nullptr)
        postfixe(vec);
    return vec;
}

Node *&most_left(Node *&node)
{
    if (node->left != nullptr)
    {
        return most_left(node->left);
    }
    return node;
}

Node *&most_left(Node &node)
{
    return most_left(node.left);
}

// A FAIRE

// bool remove(Node *&node, int value)
// {
// }