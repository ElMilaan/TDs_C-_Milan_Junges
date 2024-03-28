#include <iostream>
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

void Node::display_infixe() const
{
}