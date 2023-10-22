#pragma once

class HashT
{
private:

	class Entry					// пара ключ-значение
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
	

	void insert(int, int);		// добавить элемент
	void deleteElem(int);		// удалить элемент
	int searchKey(int);			// найти элемент
	void clear();				// сделать таблицу пустой
	bool isEmpty();				// проверка таблицы на пустот
	int hashFunction(int k);	// вычислить хэш-функцию по ключу
	
	

	class iteratorHT
	{
	public:

		explicit iteratorHT(HashT& _ptr) : tableSize(_ptr.size), ptr((_ptr.ArrEntry)), i(0) {};
		iteratorHT(HashT& _ptr, int _i) : tableSize(_ptr.size), ptr((_ptr.ArrEntry)), i(_i) {};

		iteratorHT& operator++();							// сдвинуть итератор на 1
		int operator*();									// оператор разыменовывания
		iteratorHT& operator=(const iteratorHT& rhs);		// оператор копирования
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

