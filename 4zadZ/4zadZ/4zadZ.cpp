#include <iostream>
#include "HashT.h"
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	HashT ht1(10);
	ht1.insert(0, 11);
	ht1.insert(1, 22);
	ht1.insert(2, 33);
	ht1.insert(3, 44);
	ht1.insert(4, 55);
	ht1.insert(5, 66);
	ht1.insert(6, 77);
	ht1.insert(7, 88);
	ht1.insert(8, 99);
	ht1.insert(9, 5);

	HashT ht2(10);
	ht2.insert(0, 10);
	ht2.insert(1, 20);
	ht2.insert(2, 30);
	ht2.insert(3, 40);
	ht2.insert(4, 50);
	ht2.insert(5, 60);
	ht2.insert(6, 70);
	ht2.insert(7, 80);
	ht2.insert(8, 90);
	ht2.insert(9, 5);

	

	cout << "HashTable1: " << endl;

	for (HashT::iteratorHT it = ht1.begin(); it != ht1.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;

	cout << "HashTable2: " << endl;

	for (HashT::iteratorHT it = ht2.begin(); it != ht2.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;

	HashT::iteratorHT it1(ht1);
	HashT::iteratorHT it2(ht2);
	HashT::iteratorHT it3(it1);

	if (it1 == it2)
	{
		cout << "it1 == it2" << endl;
	}
	else
	{
		cout << " no it1 == it2 "<< endl;
	}
	cout << endl;

	if (it1 == it3)
	{
		cout << "it1 == it3" << endl;
	}
	else
	{
		cout << " no it1 == it3 " << endl;
	}
	cout << endl;

	unsigned a, b, c;

	cout << "Имеющиеся ключи [0..9]" << endl;

	cout << "1) Введите ключ: ";
	cin >> a;
	cout << ht1.searchKey(a) << endl;

	cout << "2) Введите ключ: ";
	cin >> b;
	cout << ht1.searchKey(b) << endl;

	cout << "3) Введите ключ: ";
	cin >> c;
	cout << ht1.searchKey(c) << endl;

	cout << endl;
	cout << endl;

	cout << "Очистим хэш-таблицу 2" << endl;
	ht2.clear();
	if(ht2.isEmpty())
	{
		cout << "ht2 isEmpty" << endl;
	}
	else
	{
		cout << "Error. ht2 not Empty";
	}

}


