#pragma once
#include <iostream>

class Queue
{
private:
	int* Array;
	int maxSize;
	int head;
	int tail;
public:
	Queue(int);
	~Queue() {
		delete[] Array;
	}
	void push(int); // �������� ������� � �����
	void pop(); // ����� ������� � ������ �������
	int front(); // �������� ������� � ������ �������
	bool full(); // �������� �� ������������ 
	bool empty(); // �������� �� �������
	int size(); // ������ �������
	void clear(); // ������� ������� 
	int size_();
	// ������� ��� ��������� 
	int getHead();
	int getTail();
	int* getArr();
};
