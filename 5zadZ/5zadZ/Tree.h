#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data, Node* leftPtr, Node* rightPtr) : data(_data), left(leftPtr), right(rightPtr) {}
};

class Tree
{
public:
    // ��������� ������
    Tree() : root(nullptr) {};
    explicit Tree(int x) : root(new Node(x, nullptr, nullptr)) {};
    Tree(const Tree& o) : root(copyTree(o.root)) {};
    Tree(Tree&& o) noexcept : root(o.root)
    {
        o.root = nullptr;
    };
    ~Tree()
    {
        clear();
    };
    Tree& operator=(const Tree&);
    Tree& operator=(Tree&&) noexcept;
    void clear(); // �������

    void insert(int, const vector<bool>&);              // ������� �������� � ������
    friend ostream& operator<<(ostream& out, Tree& o)   // �������� ������
    { 
        o.Print(out);
        return out;
    };

    unsigned countOfEven() // ���������� ������ ����� � ������
    { 
        return countOfEven(root);
    };

    bool allPositive() // �������� ����, ��� � ������ ������ ������������� �����
    { 
        return allPositive(root);
    };

    void deleteLeaves() // �������� � ������ ���� �������
    { 
        deleteLeaves(root);
    }

    double average();               // ������� �������������� ���� ����� � ������
    vector<bool> searchElem(int);   // ����� ��������� �������� x � ������

private:

    Node* root;

    Node* copyTree(Node*);                       // �����������
    void clear(Node*);                           // ������� ���������� �������
    void Print(Node*, unsigned int, ostream&);   // ������ ������
    void Print(ostream& out)
    {
        Print(root, 0, out);
    }

    unsigned countOfEven(Node* elem) // ���������� ������ ����� �� ������
    { 
        return (elem == nullptr ? 0 : (elem->data % 2 == 0) + countOfEven(elem->left) + countOfEven(elem->right));
    }

    bool allPositive(const Node* elem) // �������� ����, ��� �� ������ ������ ������������� �����
    { 
        return elem == nullptr || elem->data > 0 && allPositive(elem->left) && allPositive(elem->right);
    }

    bool deleteLeaves(Node*);
    void average(Node*, pair<long, int>&);
    bool searchElem(Node* elem, vector<bool>& arr, int x);
};