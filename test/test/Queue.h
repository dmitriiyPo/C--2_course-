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
	void push(int); // добавить элемент в конец
	void pop(); // взять элемент в начале очереди
	int front(); // получить элемент в начале очередь
	bool full(); // проверка на переполнение 
	bool empty(); // проверка на пустоту
	int size(); // размер очереди
	void clear(); // очистка очереди 
	int size_();
	// геттеры для итератора 
	int getHead();
	int getTail();
	int* getArr();
};
