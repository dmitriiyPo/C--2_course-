#pragma once

class HashT
{
private:

	class Entry					// ���� ����-��������
	{ 
	public:

		Entry(int key, int value) : key(key), value(value) {}
		int key;
		int value;

	};

	Entry** ArrEntry;
	const unsigned int size;

public:

	HashT();
	HashT(unsigned int tableSize);
	~HashT();
	

	void insert(int, int);		// �������� �������
	void deleteElem(int);		// ������� �������
	int searchKey(int);			// ����� �������
	void clear();				// ������� ������� ������
	bool isEmpty();				// �������� ������� �� ������
	int hashFunction(int k);	// ��������� ���-������� �� �����
	
	

	class iteratorHT
	{
	public:

		explicit iteratorHT(HashT& _ptr) : tableSize(_ptr.size), ptr((_ptr.ArrEntry)), i(0) {};
		iteratorHT(HashT& _ptr, int _i) : tableSize(_ptr.size), ptr((_ptr.ArrEntry)), i(_i) {};

		iteratorHT& operator++();							// �������� �������� �� 1
		int operator*();									// �������� ���������������
		iteratorHT& operator=(const iteratorHT& rhs);		// �������� �����������
		bool operator==(const iteratorHT& other) const;
		bool operator!=(const iteratorHT& other) const;
		

	private:

		const unsigned int tableSize;
		unsigned i;
		Entry** ptr;

	};

	iteratorHT begin();
	iteratorHT end();
};

