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

	virtual void start() = 0; // ������ �������
	virtual void next() = 0; // ������� � ���������� ��������
	virtual Node* get() = 0; // �������� ��������� �������
	virtual bool finish() = 0; // ��������, �� �� ��������������� 

};

class List_Abstr
{
public:

	virtual void push_I(Iterator_Abstr*, int) = 0; // �������� ������� � ������� ���������� ����������
	virtual void del_I(Iterator_Abstr*) = 0; // ������� ������� ���������� ����������
	virtual void clear() = 0; // �������
	virtual bool empty() = 0; // �������� �� �������
	virtual int size_() const = 0; // ������ 
	virtual Iterator_Abstr* first_I() = 0; // �������� �������� �� ������ ������� 
	virtual const Iterator_Abstr* first_appearance_I(int) = 0; // ����� ������ ��������� �������� � ������

protected:
	int count;
	Node* buffer;
};

class List : public List_Abstr
{
public:

	List(); // ����������� �� ���������
	List(const List& list); // ����������� �����������
	List(List&& obj); // ����������� �����������
	~List(); // ����������

	List& operator=(const List& obj);
	List operator=(List&& obj);

	class Iterator : public Iterator_Abstr
	{
	public:

		Iterator(const List& list_);
		void start(); // ������ �������
		void next(); // ������� � ���������� ��������
		Node* get(); // �������� ��������� �������
		bool finish(); // ��������, �� �� ��������������� 

	private:
		int index;
		int count;      //kol-vo elem in list
		Node* buf;
		Node* p;
	};

	void push_I(Iterator_Abstr*, int); // �������� ������� � ������� ���������� ����������
	void del_I(Iterator_Abstr*); // ������� ������� ���������� ����������
	void clear(); // �������
	bool empty(); // �������� �� �������
	int size_() const; // ������ 
	Iterator_Abstr* first_I(); // �������� �������� �� ������ ������� 
	const Iterator_Abstr* first_appearance_I(int); // ����� ������ ��������� �������� � ������
	Node* getBuffer() const;
private:
	int count;
	Node* buffer;
};