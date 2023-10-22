#include "HashT.h"

HashT::HashT() : size(100)
{
	ArrEntry = new Entry * [size];
	clear();
}

HashT::HashT(unsigned int tableSize) : size(tableSize) 
{
	ArrEntry = new Entry * [size];
	clear();
}

HashT::~HashT()
{
	for (int i = 0; i < size; i++)
	{
		delete ArrEntry[i];
	}
	delete ArrEntry;
}

int HashT::hashFunction(int k)
{
	return k % size;
}

void HashT::insert(int k, int e)
{
	int h = hashFunction(k);
	int ee = size;
	while (ArrEntry[h] != nullptr && ArrEntry[h]->key != k)
	{
		h = hashFunction(h + 1);
		ee--;
		if (ee <= 0)
		{
			throw "Таблица переполнена !\n";
		}
	}

	if (ArrEntry[h] != nullptr)
	{
		delete ArrEntry[h];
		ArrEntry[h] = nullptr;
	}

	ArrEntry[h] = new Entry(k, e);
}

void HashT::deleteElem(int k)
{
	int h = hashFunction(k);
	int ee = size;

	while (ArrEntry[h] != nullptr)
	{
		if (ArrEntry[h]->key == k)
		{
			break;
		}
		h = hashFunction(h + 1);
		ee--;
		if (ee <= 0)
		{
			return;
		}
	}

	if (ArrEntry[h] != nullptr)
	{
		delete ArrEntry[h];
	}
}

int HashT::searchKey(int k)
{
	int h = hashFunction(k);
	int ee = size;

	while (ArrEntry[h] != nullptr)
	{
		if (ArrEntry[h]->key == k)
		{
			break;
		}
		h = hashFunction(h + 1);
		ee--;
		if (ee <= 0)
		{
			return -1;
		}
	}

	if (ArrEntry[h] == nullptr)
	{
		return -1;
	}
	return ArrEntry[h]->value;
}


void HashT::clear()
{
	for (int i = 0; i < size; i++)
	{
		ArrEntry[i] = nullptr;
	}
}

bool HashT::isEmpty() {
	for (int i = 0; i < size; i++)
	{
		if (ArrEntry[i] != nullptr)
		{
			return false;
		}
	}
	return true;
}

HashT::iteratorHT& HashT::iteratorHT::operator++()
{
	i++;
	if (ptr[i] == nullptr)
	{
		while (ptr[i] == nullptr && i < tableSize - 1)
		{
			i++;
		}
	}
	return *this;
}

HashT::iteratorHT HashT::begin()
{
	return iteratorHT(*this);
}

HashT::iteratorHT HashT::end()
{
	return iteratorHT(*this, size);
}

int HashT::iteratorHT::operator*()
{
	if (ptr[i] != nullptr)
	{
		return ptr[i]->value;
	}
}

bool HashT::iteratorHT::operator==(const HashT::iteratorHT& other) const
{
	return this->ptr == other.ptr && this->i == other.i;
}

HashT::iteratorHT& HashT::iteratorHT::operator=(const HashT::iteratorHT& rhs)
{
	if (this != &rhs)
	{
		this->ptr = rhs.ptr;
		this->i = rhs.i;
	}
	return *this;
}

bool HashT::iteratorHT::operator!=(const iteratorHT& other) const
{
	return !(other == *this);
}
