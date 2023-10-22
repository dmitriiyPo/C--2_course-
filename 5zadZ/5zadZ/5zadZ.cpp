#include <iostream>
#include "Tree.h"
#include <locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");

    Tree bt1(-6);
    vector<bool> arr1{};
    try
    {
        arr1.push_back(false);
        bt1.insert(06, arr1);
        arr1.push_back(false);
        bt1.insert(66, arr1);
        arr1.push_back(true);
        bt1.insert(666, arr1);
        arr1.pop_back();
        arr1.push_back(false);
        bt1.insert(-666, arr1);
        arr1.push_back(true);
        bt1.insert(6661, arr1);
    }
    catch (exception& ex)
    {
        cout << "!!Ошибка добавления элемента!!!\n";
    }
    try
    { 
        arr1.pop_back();
        arr1.push_back(true);
        arr1.push_back(true);
        arr1.push_back(true);
        arr1.push_back(true);
        bt1.insert(13, arr1);
    }
    catch (exception& ex) // тут должен выкинуть ошибку
    {  
        cout << "!!Ошибка добавления элемента!!!\n(Но так надо)\n" << endl;
    }
    cout << bt1 << endl;

    Tree bt2 = bt1;
    cout << bt2 << endl;

    bt2.deleteLeaves();
    cout << bt2 << endl;

    cout << "Чётных чисел в первом дереве: " << bt1.countOfEven() << endl;

    if (bt2.allPositive())
    {
        cout << "Все числа в дереве положительные\n";
    }
    else
    {
        cout << "Не все числа в дереве положительные\n";
    }

    cout << "Среднее арифметическое в первом дереве: " << bt1.average() << endl;

    vector<bool> arr666 = bt1.searchElem(666);
    cout << "Путь до 666 в первом дереве: " << endl;
    for (int i = 0; i < arr666.size(); i++)
    {
        if (arr666[i])
        {
            cout << "Право\n" << endl;
        }
        else
        {
            cout << "Лево\n" << endl;
        }
    }
}
