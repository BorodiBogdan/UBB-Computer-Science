#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <iostream>
using namespace std;

int SortedMap::getPositionOfTheElementGreaterOrEqual(TKey key) const
{
	int left = 0;
	int right = this->numberOfPairs - 1;
	int posOfTheElement = this->numberOfPairs;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		TKey currentKey = this->elements[mid].first;

		// relation(element1, element2) == 1 if element1 <= element2
		if (currentKey == key)
			return mid;
		else if (this->rel(key, currentKey) == true) // element < k
		{
			right = mid - 1;
			posOfTheElement = mid;
		}
		else
			left = mid + 1;
	}
	return posOfTheElement;
}

SortedMap::SortedMap(Relation r)
{
	// TODO - Implementation
	this->capacity = 1;
	this->numberOfPairs = 0;
	this->rel = r;
	this->elements = new TElem[this->capacity];
}

// adds a pair (key,value) to the map
// if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
// if the key SMes not exist, a new pair is added and the value null is returned
TValue SortedMap::add(TKey k, TValue v)
{
	// We use binary search in order to find the element
	int pos = getPositionOfTheElementGreaterOrEqual(k);

	if (pos != this->numberOfPairs && this->elements[pos].first == k) // The key already exists
	{
		TValue oldValue = this->elements[pos].second;
		elements[pos].second = v;
		return oldValue;
	}
	else
	{ // we need to add the value in the array
		if (this->numberOfPairs == 0)
		{
			this->elements[0] = {k, v};
			this->numberOfPairs++;
			return NULL_TVALUE;
		}
		TElem *newElements = new TElem[this->numberOfPairs + 1];

		int i = 0, j = 0;
		this->numberOfPairs++;

		for (; i < this->numberOfPairs; ++i, j++)
		{
			if (i == pos)
			{
				newElements[i] = {k, v};
				i++;
			}
			if (j != this->numberOfPairs - 1)
				newElements[i] = this->elements[j];
		}

		delete[] this->elements;
		this->elements = newElements;
	}

	return NULL_TVALUE;
}
// searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
TValue SortedMap::search(TKey k) const
{
	// TODO - Implementation

	// We use binary search in order to find the element

	int pos = getPositionOfTheElementGreaterOrEqual(k);

	if (pos == this->numberOfPairs)
		return NULL_TVALUE;
	if (this->elements[pos].first == k)
		return this->elements[pos].second;
	return NULL_TVALUE;
}

// removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
TValue SortedMap::remove(TKey k)
{
	if (this->numberOfPairs == 0)
		return NULL_TVALUE;

	// TODO - Implementation
	int pos = getPositionOfTheElementGreaterOrEqual(k);

	if (pos == this->numberOfPairs)
		return NULL_TVALUE;

	if (this->elements[pos].first != k)
		return NULL_TVALUE;

	TValue removedValue = this->elements[pos].second;

	for (int i = pos; i < this->numberOfPairs - 1; ++i)
		this->elements[i] = this->elements[i + 1];

	this->numberOfPairs--;

	return removedValue;
}

int SortedMap::size() const
{
	// TODO - Implementation
	return this->numberOfPairs;
}

bool SortedMap::isEmpty() const
{
	// TODO - Implementation
	return this->numberOfPairs == 0;
}

SMIterator SortedMap::iterator() const
{
	return SMIterator(*this);
}

SortedMap::~SortedMap()
{
	// TODO - Implementation
	delete[] this->elements;
}
