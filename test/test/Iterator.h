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
	void start(); // начать перебор
	void next(); // перейти к слодующему элементу
	bool finish(); // преверка, всё ли проэтерированно 
	int getValue(); // получить очередной элемент
};

