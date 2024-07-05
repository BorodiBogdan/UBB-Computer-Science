#include "SetIterator.h"
#include "Set.h"
#include <exception>
#include <iostream>

// BC = WC = TC = Theta(1);
SetIterator::SetIterator(const Set &m) : set(m)
{
	// TODO - Implementation
	this->first();
}

// BC = Theta(1), WC = Theta(capacity), TC = O(capacty);
void SetIterator::first()
{
	// TODO - Implementation

	this->currentPos = 0;

	while (set.HashTable[this->currentPos] == nullptr && this->currentPos != set.capacity)
		this->currentPos++;

	this->chainIterator = set.HashTable[this->currentPos];
}

// BC = Theta(1), WC = Theta(capacity), TC = O(Capacity)
void SetIterator::next()
{
	// TODO - Implementation
	if (this->valid() == false)
		throw std::exception();

	if (this->chainIterator->next != nullptr)
		chainIterator = chainIterator->next;
	else
	{
		this->currentPos++;

		while (this->currentPos < set.capacity && set.HashTable[this->currentPos] == nullptr)
			this->currentPos++;

		this->chainIterator = set.HashTable[this->currentPos];
	}
}
// BC = Theta(1), WC = Theta(capacity + numberofelemens) TC = O(capacity + numberofelemens)
void SetIterator::previous()
{
	// TODO - Implementation
	if (this->valid() == false)
		throw std::exception();

	if (chainIterator->previous == nullptr)
	{
		this->currentPos--;

		while (this->currentPos > 0 && set.HashTable[this->currentPos] == nullptr)
			this->currentPos--;

		if (this->currentPos == 0)
		{
			chainIterator = nullptr;
		}
		else
		{
			this->chainIterator = set.HashTable[this->currentPos];

			while (this->chainIterator->next != nullptr)
				this->chainIterator = this->chainIterator->next;
		}
	}
	else
		chainIterator = chainIterator->previous;
}

// BC = WC = TC = Theta(1);
TElem SetIterator::getCurrent()
{
	// TODO - Implementation
	if (this->valid() == false)
		throw std::exception();

	return chainIterator->info;
}

// BC = WC = TC = Theta(1);
bool SetIterator::valid() const
{
	// TODO - Implementation
	if (this->currentPos == set.capacity)
		return false;

	return chainIterator != nullptr;
}
