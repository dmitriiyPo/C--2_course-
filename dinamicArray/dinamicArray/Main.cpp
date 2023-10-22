#include <iostream>
#include <exception>
#include "DinamicArray.h"
#include "CannotBeCompared.h"
#include <locale.h>
using namespace std;



int main()
{
	setlocale(LC_ALL, "Rus");
	
	int n = 0;
	cout << "Введите размер массива: ";
	cin >> n;
	DinamicArray arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
	}
	
	int z = 0;
	cout << "Введите размер массива4: ";
	cin >> z;
	DinamicArray arr4(z);
	for (int i = 0; i < z; i++)
	{
		cin >> arr4[i];
	}

	int w = 0;
	cout << "Ведите размер массива5: ";
	cin >> w;
	DinamicArray arr5(w);
	for (int i = 0; i < w; i++)
	{
		cin >>arr5[i];
	}

	cout << arr;
	cout << endl;
	cout << arr[2];
	cout << endl;

	DinamicArray arr2(6, 10);
	cout << arr2;

	arr.resize(8);
	cout << arr;

	if (arr == arr2)
	{
		cout << "ok";
	}
	else
	{
		cout << "fail" << endl;
	}
	cout << endl;

	DinamicArray arr3(arr2);
	for (int i = 0; i < 6; i++)
	{
		cout << arr3[i] << endl;
	}

	//DinamicArray arr4(5, 9);
	//DinamicArray arr5(5, 8);

	cout << endl;


	if (arr4 < arr5)
	{
		cout << "arr4 < arr5" << endl;
	}
	else
	{
		cout << "no arr4 < arr5" << endl;
	}
	

	//if (arr4 > arr5)
	//{
	//	cout << "arr4 > arr5" << endl;
	//}
	//else
	//{
	//	cout << "no arr4 > arr5" << endl;
	//}

	//if (arr4 <= arr5)
	//{
	//	cout << "arr4 <= arr5" << endl;
	//}
	//else
	//{
	//	cout << "no arr4 <= arr5" << endl;
	//}

	//if (arr4 >= arr5)
	//{
	//	cout << "arr4 >= arr5" << endl;
	//}
	//else
	//{
	//	cout << "no arr4 >= arr5" << endl;
	//}


	return 0;
}
