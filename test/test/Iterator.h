#pragma once


#include "Queue.h"

class Iterator
{
private:
	Queue& queue;
	int i;
public:
	explicit Iterator(Queue& queue_) : queue(queue_), i(0) {
	}
	void start(); // ������ �������
	void next(); // ������� � ���������� ��������
	bool finish(); // ��������, �� �� ��������������� 
	int getValue(); // �������� ��������� �������
};

