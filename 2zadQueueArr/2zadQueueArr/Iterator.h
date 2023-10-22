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

	explicit Iterator(QueueArr& queue_) : queue(queue_), i(0) { //объ€вление конструктора от одного параметра
	}
	void start(); // начать перебор
	void next(); // перейти к слодующему элементу
	bool finish(); // преверка, всЄ ли проэтерированно 
	int getValue(); // получить очередной элемент

};