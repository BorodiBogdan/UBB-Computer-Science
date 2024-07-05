#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

// BC = WC = TC = Theta(1)
ListIterator::ListIterator(const SortedIteratedList &list) : list(list)
{
	this->iterator = this->list.head;

	if (list.head != nullptr)
		this->howManyLeft = iterator->howManyComps;
	else
		this->howManyLeft = 0;
	// TODO - Implementation
}

// BC = WC = TC = Theta(1)
void ListIterator::first()
{
	this->iterator = list.head;
	if (list.head != nullptr)
		this->howManyLeft = iterator->howManyComps;
	else
		this->howManyLeft = 0;
	// TODO - Implementation
}

// BC = WC = TC = Theta(1)
void ListIterator::next()
{
	// TODO - Implementation
	if (this->iterator == nullptr)
		throw exception();

	if (this->howManyLeft <= 1)
	{
		this->iterator = iterator->next;

		if (iterator != nullptr)
			this->howManyLeft = iterator->howManyComps;
	}
	else
		this->howManyLeft--;
}

// BC = WC = TC = Theta(1)
bool ListIterator::valid() const
{
	if (this->iterator == nullptr)
		return false;
	// TODO - Implementation
	return true;
}

// BC = WC = TC = Theta(1)
TComp ListIterator::getCurrent() const
{
	// TODO - Implementation
	if (this->valid())
		return this->iterator->information;
	else
		return NULL_TCOMP;
}
