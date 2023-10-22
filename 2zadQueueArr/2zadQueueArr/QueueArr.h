#pragma once
#include <iostream>
using namespace std;

class QueueArr
{
private:

	int* Array;	        //������ ������, ������ ������� 
	int maxSize;		//max ������ �������, ������ ������ ����� maxSize+1
	int head;			//������ ���������� ��������
	int tail;			//������ ��������� �������� (��������� � ����� �������), ���������� �� ��������� � �������, ������ ����� ���� �������� �� ����

public:

	QueueArr(int size);				//constructor int - ������� ������������ ������� �������
	~QueueArr();

	int size();			//������ �������
	void pop();			//delete ������ ��-� �������
	void push(int);		//�������� � ����� �������
	int front();		//���������� ������ ��-� �������
	bool empty();
	bool full();
	void clear();		//������� ������

	
	//get for iterator
	int getHead();
	int getTail();
	int* getArr();

};
