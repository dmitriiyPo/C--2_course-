#include "Tree.h"

Tree& Tree::operator=(const Tree& o)
{
    if (this != &o)
    {
        delete root;
        root = copyTree(o.root);
    }
    return *this;
}

Tree& Tree::operator=(Tree&& o) noexcept
{
    if (this != &o)
    {
        delete root;
        root = o.root;
        o.root = nullptr;
    }
    return (*this);
}

void Tree::clear()
{
    if (root != nullptr)
    {
        clear(root);
        root = nullptr;
    }
}

void Tree::insert(int x, const vector<bool>& boolArr)
{
    if (root == nullptr)
    {
        if (!boolArr.empty())
        {
            throw exception();
        }
        root = new Node;
        root->data = x;
    }
    else
    {
        Node* current = root;
        for (unsigned i = 0; i < boolArr.size(); i++)
        {
            if (i == boolArr.size() - 1)
            {
                Node* old = current;
                current = new Node;
                boolArr[i] ? old->right = current : old->left = current;
                current->left = nullptr;
                current->right = nullptr;
            }
            else if (boolArr[i] && current->right != nullptr)
            {
                current = current->right;
            }
            else if (!boolArr[i] && current->left != nullptr)
            {
                current = current->left;
            }
            else
            {
                throw exception();
            }
        }
        current->data = x;
    }
}

double Tree::average()
{
    pair<long, int> res(0, 0);
    average(root, res);
    return ((double)res.first) / res.second;
}

vector<bool> Tree::searchElem(int x)
{
    vector<bool> res{};
    if (!searchElem(root, res, x))
    {
        throw exception();
    }
    return res;
}

// private

Node* Tree::copyTree(Node* o)
{
    if (o == nullptr)
    {
        return nullptr;
    }
    return new Node(o->data, copyTree(o->left), copyTree(o->right));
}


void Tree::clear(Node* elem)
{
    if (elem != nullptr)
    {
        clear(elem->left);
        clear(elem->right);
        delete elem;
    }
}

void Tree::Print(Node* elem, unsigned int level, ostream& out)
{
    if (elem != nullptr)
    {
        for (unsigned i = 0; i != level; i++)
        {
            out << "\t";
        }
        out << elem->data << "\n";
        Print(elem->left, level + 1, out);
        Print(elem->right, level + 1, out);
    }
}

bool Tree::deleteLeaves(Node* elem)
{
    if (elem == nullptr)
    {
        return false;
    }
    else
    {
        if (elem->right == nullptr && elem->left == nullptr)
        {
            delete elem;
            return true;
        }
        if (deleteLeaves(elem->left))
        {
            elem->left = nullptr;
        }
        if (deleteLeaves(elem->right))
        {
            elem->right = nullptr;
        }
        return false;
    }
}

void Tree::average(Node* elem, pair<long, int>& values)
{
    if (elem != nullptr)
    {
        values.first += elem->data;
        values.second += 1;
        average(elem->left, values);
        average(elem->right, values);
    }
}

bool Tree::searchElem(Node* const elem, vector<bool>& arr, int x)
{
    if (elem != nullptr)
    {
        if (elem->data == x)
        {
            return true;
        }
        arr.push_back(false);
        if (searchElem(elem->left, arr, x))
        {
            return true;
        }
        arr.pop_back();
        arr.push_back(true);
        if (searchElem(elem->right, arr, x))
        {
            return true;
        }
        arr.pop_back();
    }
    return false;
}