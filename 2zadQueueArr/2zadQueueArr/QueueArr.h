#pragma once
#include <iostream>
using namespace std;

class QueueArr
{
private:

	int* Array;	        //начало списка, голова очереди 
	int maxSize;		//max размер очереди, размер массив будет maxSize+1
	int head;			//индекс начального элемента
	int tail;			//индекс буферного элемента (находится в конце очереди), следующего за последним в очереди, массив может быть заполнен не весь

public:

	QueueArr(int size);				//constructor int - задачем максимальную глубину очереди
	~QueueArr();

	int size();			//размер очереди
	void pop();			//delete первый эл-т очереди
	void push(int);		//положить в конец очереди
	int front();		//посмотреть первый эл-т очереди
	bool empty();
	bool full();
	void clear();		//сделать пустым

	
	//get for iterator
	int getHead();
	int getTail();
	int* getArr();

};
