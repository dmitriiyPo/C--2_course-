#include <iostream>
#include <exception>
#include "DinamicArray.h"
#include "CannotBeCompared.h"
using namespace std;


DinamicArray::DinamicArray()
{
	this->size = 0;
	this->arr = nullptr;
}

DinamicArray::DinamicArray(int n)
{
	this->size = n;
	this->arr = new int[n];
}

DinamicArray::DinamicArray(int size, int n)
{
	this->size = size;
	this->arr = new int[size];
	for(int i = 0; i < size; i++)
	{
		arr[i] = n;
	}
}

DinamicArray::DinamicArray(DinamicArray&& move) 
{
	this->size = move.size;
	this->arr = move.arr;
	move.arr = nullptr;
}

DinamicArray::~DinamicArray()
{
	delete[] arr;
}

DinamicArray::DinamicArray(const DinamicArray& copying)
{
	arr = new int[copying.size];
	for(int i = 0; i < copying.size; i++)
	{
		arr[i] = copying.arr[i];
	}
}

int DinamicArray::arrayLength(int n)
{
	this->size = n;
	int count = 0;
	arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		count++;
	}
	return count;
}

int DinamicArray::getSize() const
{
	return size;
}

int &DinamicArray::operator[](int index)
{
	return arr[index];
}

void DinamicArray::resize(int newSize)
{
	int* arr1 = new int[newSize];

	for(int i = 0; i < this->size; i ++)
	{
		arr1[i] = this->arr[i];
	}



	if (newSize > this->size)
	{
		for(int i = this->size; i < newSize; i++)
		{
			arr1[i] = 0;
		}
	}
	delete[] arr;
	this->size = newSize;
	this->arr = arr1;
}

DinamicArray &DinamicArray::operator=(DinamicArray&& tmp)//оператор перемещения
{
	delete this;
	size = tmp.size;
	arr = tmp.arr;
	tmp.arr = nullptr;
	return *this;
}

DinamicArray& DinamicArray::operator=(const DinamicArray& tmp) //оператор присваивания
{
	delete this;
	size = tmp.size;
	arr = new int[size];
	for(int i = 0; i < size; i++)
	{
		arr[i] = tmp.arr[i];
	}
	return *this;
}

bool DinamicArray::operator==(const DinamicArray &tmp)
{
	if (size == tmp.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] != tmp.arr[i]) return false;
		}
		return true;
	}
	else return false;
}

bool DinamicArray::operator!=(const DinamicArray &tmp)
{
	if (size != tmp.size)
	{
		return true;
	}
	for(int i = 0; i < size; i++)
	{
		if(arr[i] != tmp.arr[i])
		{
			return true;
		}
	}
	return false;
}

bool DinamicArray::operator<(const DinamicArray& obj) const
{
	if (this->size < obj.size)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i] < obj.arr[i])
			{
				return true;
			}
			else if (this->arr[i] > obj.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i < obj.size; i++)
		{
			if (this->arr[i] < obj.arr[i])
			{
				return true;
			}
			else if (this->arr[i] > obj.arr[i])
			{
				return false;
			}
		}
		return false;
	}
}

bool DinamicArray::operator<=(const DinamicArray& obj) const
{
	return !(obj < *this);
}

bool DinamicArray::operator>(const DinamicArray& obj) const
{
	if (this->size < obj.size) {
		for (int i = 0; i < this->size; i++) {
			if (this->arr[i] > obj.arr[i]) {
				return true;
			}
			else if (this->arr[i] < obj.arr[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		for (int i = 0; i < obj.size; i++) {
			if (this->arr[i] > obj.arr[i]) {
				return true;
			}
			else if (this->arr[i] < obj.arr[i]) {
				return false;
			}
		}
		return false;
	}
}

bool DinamicArray::operator>=(const DinamicArray& obj) const
{
	return !(*this < obj);
}

DinamicArray DinamicArray::operator+(DinamicArray& tmp) {
	DinamicArray sumA(size + tmp.size);

	int j = 0;
	for (int i = 0; i < size; i++) {
		sumA[j] = arr[i];
		j++;
	}
	for (int i = 0; i < tmp.size; i++) {
		sumA[j] = tmp.arr[i];
		j++;
	}
	return sumA;
}

std::ostream& operator<<(ostream& os, DinamicArray& arr) {
	os << "Size: " << arr.getSize() << endl << "Array:" << endl;
	for (int i = 0; i < arr.getSize(); i++) {
		os << "[" << i << "] = " << arr[i] << endl;
	}
	return os;
}

std::istream& operator>>(istream& in, DinamicArray& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		in >> arr[i];
	}
	return in;
}