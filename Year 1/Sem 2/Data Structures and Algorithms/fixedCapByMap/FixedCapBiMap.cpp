#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"

FixedCapBiMap::FixedCapBiMap(int capacity)
{
	// TODO - Implementation
	this->capacity = capacity;
	this->sizeMap = 0;
	elements = new TElem[capacity];
}

FixedCapBiMap::~FixedCapBiMap()
{
	// TODO - Implementation
	delete[] this->elements;
}

bool FixedCapBiMap::add(TKey c, TValue v)
{
	int count = 0;

	for (int i = 0; i < this->sizeMap; ++i)
	{
		if (elements[i].first == c)
			count++;
	}

	if (count >= 2)
		return 0;

	elements[this->sizeMap++] = {c, v};

	return 1;
}

ValuePair FixedCapBiMap::search(TKey c) const
{
	// TODO - Implementation
	ValuePair res = {NULL_TVALUE, NULL_TVALUE};

	for (int i = 0; i < this->sizeMap; ++i)
	{
		if (this->elements[i].first == c && res.first == NULL_TVALUE)
			res.first = elements[i].second;
		else if (this->elements[i].first == c && res.second == NULL_TVALUE)
			res.second = elements[i].second;
	}
	return res;
}

bool FixedCapBiMap::remove(TKey c, TValue v)
{
	int p = -1;
	for (int i = 0; i < this->sizeMap; ++i)
	{
		if (this->elements[i].first == c && this->elements[i].second == v)
			p = i;
	}
	if (p < 0)
		return false;

	for (int i = p; i < this->sizeMap - 1; ++i)
		this->elements[i] = this->elements[i + 1];

	this->sizeMap--;

	return true;
}

int FixedCapBiMap::size() const
{
	return this->sizeMap;
}

bool FixedCapBiMap::isEmpty() const
{
	return this->sizeMap == 0;
}

bool FixedCapBiMap::isFull() const
{
	return this->sizeMap == this->capacity;
}
bool FixedCapBiMap::replace(TKey a, TValue oldValue, TKey newValue)
{
	for (int i = 0; i < this->sizeMap; ++i)
		if (this->elements[i].first == a && this->elements[i].second == oldValue)
		{
			this->elements[i].second = newValue;
			return true;
		}
	return false;
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const
{
	return FixedCapBiMapIterator(*this);
}
