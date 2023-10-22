#include <iostream>
#include "QueueArr.h"
using namespace std;

QueueArr::QueueArr(int size) //size размер очереди
{
	maxSize = size;
	this->Array = new (std::nothrow) int[maxSize + 1];
	head = tail = 0;
}

int QueueArr::size()
{
	return (tail - head + maxSize + 1) % (maxSize + 1);
}



bool QueueArr::full()
{
	return (tail + 1) % (maxSize + 1) == head;
}

void QueueArr::push(int value)
{
	if (!full())
	{
		Array[tail] = value;
		tail = (tail + 1) % (maxSize + 1);
	}
	else
	{
		throw "!!!Очередь переполнена!!!";
	}
}


void QueueArr::pop()
{
	if (empty())
	{
		throw "!!!Очередь пуста!!!";
	}
	else
	{
		head = (head + 1) % (maxSize + 1);
	}
}

int QueueArr::front()
{
	if (empty())
	{
		throw "!!!Очередь пуста!!!";
	}
	else
	{
		return Array[head];
	}
}

bool QueueArr::empty()
{
	return head == tail; //условие на пустоту очереди
}



void QueueArr::clear()
{
	delete[] Array;
	this->Array = new int[maxSize+1];
	head = tail = 0;
}

QueueArr::~QueueArr()
{
	delete[] Array;
	Array = nullptr;
}

int QueueArr::getHead() {
	return head % (maxSize+1);
}

int QueueArr::getTail() {
	return tail % (maxSize + 1);
}

int* QueueArr::getArr()
{
	return Array;
}
