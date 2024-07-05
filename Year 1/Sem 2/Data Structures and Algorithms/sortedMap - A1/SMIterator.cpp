#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap &m) : map(m)
{
	// TODO - Implementation
	this->currentIndex = 0;
}

// One operation -> BC = WC = TC = T(1)
void SMIterator::first()
{
	// TODO - Implementation
	this->currentIndex = 0;
}

// One operation -> BC = WC = TC = T(1)
void SMIterator::next()
{
	// TODO - Implementation
	if (!this->valid())
		throw exception();

	this->currentIndex++;
}

// One operation -> BC = WC = TC = T(1)
bool SMIterator::valid() const
{
	// TODO - Implementation
	if (this->currentIndex < this->map.numberOfPairs && this->currentIndex >= 0)
		return true;
	return false;
}

// One operation -> BC = WC = TC = T(1)
TElem SMIterator::getCurrent() const
{
	// TODO - Implementation
	if (!this->valid())
		throw exception();
	else
		return this->map.elements[this->currentIndex];
}

void SMIterator::jumpForward(int k)
{
	if (k <= 0)
		throw exception();
	if (!this->valid())
		throw exception();
	this->currentIndex += k;
}
