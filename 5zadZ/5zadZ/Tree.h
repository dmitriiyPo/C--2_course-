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
    // служебные методы
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
    void clear(); // очистка

    void insert(int, const vector<bool>&);              // вставка элемента в дерево
    friend ostream& operator<<(ostream& out, Tree& o)   // оператор вывода
    { 
        o.Print(out);
        return out;
    };

    unsigned countOfEven() // количество четных чисел в дереве
    { 
        return countOfEven(root);
    };

    bool allPositive() // проверка того, что в дереве только положительные числа
    { 
        return allPositive(root);
    };

    void deleteLeaves() // удаление в дереве всех листьев
    { 
        deleteLeaves(root);
    }

    double average();               // среднее арифметическое всех чисел в дереве
    vector<bool> searchElem(int);   // поиск заданного элемента x в дереве

private:

    Node* root;

    Node* copyTree(Node*);                       // копирование
    void clear(Node*);                           // удаляет конкретный элемент
    void Print(Node*, unsigned int, ostream&);   // печать уровня
    void Print(ostream& out)
    {
        Print(root, 0, out);
    }

    unsigned countOfEven(Node* elem) // количество четных чисел на уровне
    { 
        return (elem == nullptr ? 0 : (elem->data % 2 == 0) + countOfEven(elem->left) + countOfEven(elem->right));
    }

    bool allPositive(const Node* elem) // проверка того, что на уровне только положительные числа
    { 
        return elem == nullptr || elem->data > 0 && allPositive(elem->left) && allPositive(elem->right);
    }

    bool deleteLeaves(Node*);
    void average(Node*, pair<long, int>&);
    bool searchElem(Node* elem, vector<bool>& arr, int x);
};