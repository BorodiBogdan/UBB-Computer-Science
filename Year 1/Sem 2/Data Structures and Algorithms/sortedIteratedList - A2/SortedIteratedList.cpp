#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>

// BC = WC = TC = Theta(1)
SortedIteratedList::SortedIteratedList(Relation r)
{
	// TODO - Implementation
	this->compareRelation = r;
	this->listSize = 0;
	this->head = nullptr;
}

// BC = WC = TC = Theta(1)
int SortedIteratedList::size() const
{
	// TODO - Implementation
	return this->listSize;
}

// BC = WC = TC = Theta(1)
bool SortedIteratedList::isEmpty() const
{
	// TODO - Implementation
	if (this->listSize == 0)
		return true;

	return false;
}

// BC = WC = TC = Theta(1)
ListIterator SortedIteratedList::first() const
{
	// TODO - Implementation
	return ListIterator(*this);
}

// BC = WC = TC = Theta(1)
TComp SortedIteratedList::getElement(ListIterator poz) const
{
	// TODO - Implementation
	if (!poz.valid())
		throw exception();

	return poz.getCurrent();
}

// BC = Theta(1) WC = Theta(n) TC = O(n)
TComp SortedIteratedList::remove(ListIterator &poz)
{
	if (!poz.valid())
		throw exception();

	// TODO - Implementation
	node *where = poz.iterator;
	TComp info = where->information;

	where->howManyComps--;
	this->listSize--;

	if (where == head)
	{
		if (where->howManyComps == 0)
		{
			if (where->next != nullptr)
			{
				head = where->next;
				poz.iterator = where->next;
			}
			else
				head = nullptr;

			delete where;
		}

		return info;
	}

	if (where->howManyComps == 0)
	{
		node *current = this->head;

		while (current->next != where)
			current = current->next;

		current->next = where->next;
		delete where;
	}
	return info;
}

// BC = Theta(1) WC = Theta(n) TC = O(n)
ListIterator SortedIteratedList::search(TComp e) const
{
	// TODO - Implementation
	ListIterator current = first();

	while (current.valid())
	{
		if (current.getCurrent() == e)
			return current;

		current.next();
	}

	return current;
}

// BC = theta(1) WC = Theta(n) TC = O(n)
void SortedIteratedList::removeBetween(ListIterator &start, ListIterator &end)
{
	if (start.valid() == false || end.valid() == false)
		throw exception();

	node *left = this->head;

	while (left != start.iterator && left != nullptr)
		left = left->next;

	int diff = 0;

	// case 1 we need to remove ale elements after start
	if (end.iterator->next == nullptr)
		left->next = nullptr;
	else if (start.iterator == this->head)
	{
		// case 2 we remove pos 1 ..... x

		node *current = start.iterator;
		while (current != end.iterator)
		{
			node *deletedNode = current;
			current = current->next;
			delete deletedNode;
			diff++;
		}
		this->head = end.iterator->next;
	}
	else
	{

		// case two, we have elements after right
		node *right = end.iterator;
		right = right->next;

		node *current = start.iterator;
		while (current != end.iterator)
		{
			node *deletedNode = current;
			current = current->next;
			delete deletedNode;
			diff++;
		}
		// we link the nodes
		left->next = right;
	}
	this->listSize -= diff;
	start.iterator = nullptr;
	end.iterator = nullptr;
}

// BC = Theta(1) WC = Theta(n) TC = O(n)
void SortedIteratedList::add(TComp e)
{
	// TODO - Implementation
	node *current = this->head;

	// we do not have elements
	if (current == nullptr)
	{
		current = new node;
		current->information = e;
		current->howManyComps = 1;
		this->head = current;
		this->listSize++;
		return;
	}
	// now we need to search for the place where we add the element

	// Case I - We add on the first position

	if (this->compareRelation(e, current->information))
	{
		if (current->information == e)
		{
			current->howManyComps++;
			this->listSize++;
			return;
		}
		node *newNode = new node;
		newNode->information = e;
		newNode->next = current;
		this->head = newNode;
		newNode->howManyComps = 1;
		this->listSize++;
		return;
	}

	// We need to search where we add the element
	node *whereToAdd = current;

	while (current != NULL && this->compareRelation(current->information, e) == 1)
	{
		if (e == current->information)
		{
			current->howManyComps++;
			this->listSize++;
			return;
		}
		whereToAdd = current;
		current = current->next;
	}

	node *nodeToAdd = new node;
	nodeToAdd->next = whereToAdd->next;
	nodeToAdd->howManyComps = 1;
	nodeToAdd->information = e;
	whereToAdd->next = nodeToAdd;
	this->listSize++;
}

// AC = WC = TC = Theta(n)
SortedIteratedList::~SortedIteratedList()
{
	// TODO - Implementation

	node *current = this->head;

	while (current != nullptr)
	{
		node *toBeDeleted = current;
		current = current->next;
		delete toBeDeleted;
	}
}
