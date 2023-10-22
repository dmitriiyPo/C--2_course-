#pragma once
#include<iostream>
using namespace std;

class DinamicArray
{
private:

	int* arr = nullptr;
	int size = 0;

public:
	
	DinamicArray();
	DinamicArray(int n);
	DinamicArray(int size, int n);
	~DinamicArray();
	DinamicArray(const DinamicArray& copying);
	DinamicArray(DinamicArray&& move);

	int getSize() const;
	int arrayLength(int n);
	int& operator[](int index);
	void resize(int newSize);

	DinamicArray& operator=(DinamicArray&& tmp);
	DinamicArray& operator=(const DinamicArray& tmp);
	
	bool operator==(const DinamicArray& tmp);
	bool operator!=(const DinamicArray& tmp);

	bool operator<(const DinamicArray& obj) const;
	bool operator<=(const DinamicArray& obj) const;
	bool operator>(const DinamicArray& obj) const;
	bool operator>=(const DinamicArray& obj) const;

	DinamicArray operator+(DinamicArray& tmp);

	friend std::ostream& operator<<(std::ostream& os, DinamicArray& arr);
	friend std::istream& operator>>(std::istream& in, DinamicArray& arr);

};