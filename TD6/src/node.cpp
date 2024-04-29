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
    if (val <= value)
    {
        (left == nullptr) ? left = create_node(val) : left->insert(val);
    }
    else
    {
        (right == nullptr) ? right = create_node(val) : right->insert(val);
    }
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

int Node::has_one_child()
{
    if (left != nullptr && right == nullptr)
    {
        return 1;
    }
    else if (left != nullptr && right == nullptr)
    {
        return 2;
    }
    return 0;
}

Node *&most_left(Node *&node)
{
    if (node->left != nullptr)
    {
        return most_left(node->left);
    }
    return node;
}

void remove_with_one_children(Node *&node)
{
    int child = node->has_one_child();
    switch (child)
    {
    case 1:
        node->value = node->left->value;
        delete node->left;
        node->left = nullptr;
        break;

    case 2:
        node->value = node->right->value;
        delete node->right;
        node->right = nullptr;
        break;
    }
}

void remove_with_two_children(Node *&node, int &smallest)
{
    node->value = node->left->value;
    if (node->left->value != smallest)
    {
        if (node->left->is_leaf())
        {
            delete node;
            node = nullptr;
        }
        else if (node->left->has_one_child())
        {
            remove_with_one_children(node->left);
        }
        else
        {
            remove_with_two_children(node->left, smallest);
        }
    }
    else
    {
        delete node->left;
        node->left = nullptr;
    }
}

bool remove(Node *&node, int value)
{
    if (node == nullptr)
    {
        return false;
    }
    else if (value < node->value)
    {
        remove(node->left, value);
    }
    else if (value > node->value)
    {
        remove(node->right, value);
    }
    else
    {
        return remove(node);
    }
}

bool remove(Node *&node)
{
    if (node->is_leaf())
    {
        delete node;
        node = nullptr;
        return true;
    }
    else if (node->has_one_child() != 0)
    {
        remove_with_one_children(node);
        return true;
    }
    else
    {
        int smallest = most_left(node)->value;
        remove_with_two_children(node, smallest);
        return true;
    }
    return true;
}

void delete_tree(Node *node)
{
    if (node == nullptr)
        return;

    delete_tree(node->left);
    delete_tree(node->right);

    if (node->left != nullptr)
    {
        delete node->left;
        node->left = nullptr;
    }
    if (node->right != nullptr)
    {
        delete node->right;
        node->right = nullptr;
    }
}

int Node::max()
{
    if (this == nullptr)
        return INT_MIN;

    int max = this->value;
    int lMax = left->max();
    int rMax = right->max();

    if (lMax > max)
        max = lMax;
    if (rMax > max)
        max = rMax;

    return max;
}

int Node::min()
{
    if (this == nullptr)
        return INT_MAX;

    int min = this->value;
    int lMin = left->min();
    int rMin = right->min();

    if (lMin < min)
        min = lMin;
    if (rMin < min)
        min = rMin;

    return min;
}