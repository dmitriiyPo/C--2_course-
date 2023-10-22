#pragma once
#include <iostream>

struct Node
{
	Node* prev;
	Node* next;
	int data;
};

class Iterator_Abstr
{
public:

	virtual void start() = 0; // начать перебор
	virtual void next() = 0; // перейти к слодующему элементу
	virtual Node* get() = 0; // получить очередной элемент
	virtual bool finish() = 0; // преверка, всё ли проэтерированно 

};

class List_Abstr
{
public:

	virtual void push_I(Iterator_Abstr*, int) = 0; // добавить элемент в позицию отмеченную итератором
	virtual void del_I(Iterator_Abstr*) = 0; // удалить элемент отмеченный итератором
	virtual void clear() = 0; // очистка
	virtual bool empty() = 0; // проверка на пустоту
	virtual int size_() const = 0; // размер 
	virtual Iterator_Abstr* first_I() = 0; // получить итератор на первый элемент 
	virtual const Iterator_Abstr* first_appearance_I(int) = 0; // найти первое вхождение элемента в список

protected:
	int count;
	Node* buffer;
};

class List : public List_Abstr
{
public:

	List(); // конструктор по умолчанию
	List(const List& list); // конструктор копирования
	List(List&& obj); // конструктор перемещения
	~List(); // диструктор

	List& operator=(const List& obj);
	List operator=(List&& obj);

	class Iterator : public Iterator_Abstr
	{
	public:

		Iterator(const List& list_);
		void start(); // начать перебор
		void next(); // перейти к слодующему элементу
		Node* get(); // получить очередной элемент
		bool finish(); // преверка, всё ли проэтерированно 

	private:
		int index;
		int count;      //kol-vo elem in list
		Node* buf;
		Node* p;
	};

	void push_I(Iterator_Abstr*, int); // добавить элемент в позицию отмеченную итератором
	void del_I(Iterator_Abstr*); // удалить элемент отмеченный итератором
	void clear(); // очистка
	bool empty(); // проверка на пустоту
	int size_() const; // размер 
	Iterator_Abstr* first_I(); // получить итератор на первый элемент 
	const Iterator_Abstr* first_appearance_I(int); // найти первое вхождение элемента в список
	Node* getBuffer() const;
private:
	int count;
	Node* buffer;
};