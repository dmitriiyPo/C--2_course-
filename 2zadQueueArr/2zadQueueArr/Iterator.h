#pragma once
#include <iostream>
#include "QueueArr.h"
using namespace std;

class Iterator
{
private:

	QueueArr& queue;
	int i;

public:

	explicit Iterator(QueueArr& queue_) : queue(queue_), i(0) { //���������� ������������ �� ������ ���������
	}
	void start(); // ������ �������
	void next(); // ������� � ���������� ��������
	bool finish(); // ��������, �� �� ��������������� 
	int getValue(); // �������� ��������� �������

};