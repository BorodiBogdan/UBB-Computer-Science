
#include "PriorityQueue.h"
#include <exception>
#include <iostream>
using namespace std;

// BC = WC = TC = Theta(size)
void PriorityQueue::init(int size)
{
	this->capacity = size;
	this->head = -1;
	this->firstEmpty = 0;
	this->elements = new Element[size];
	this->next = new int[size];

	for (int i = 0; i < size - 1; i++)
		this->next[i] = i + 1;

	// end of the list
	this->next[size - 1] = -1;
}
// WC = BC = TC = Theta(capacity)
void PriorityQueue::resize()
{
	int newCapacity = this->capacity * 2;
	Element *newElements = new Element[newCapacity];
	int *newNext = new int[newCapacity];

	for (int i = 0; i < this->capacity; i++)
	{
		newElements[i] = this->elements[i];
		newNext[i] = this->next[i];
	}

	for (int i = this->capacity; i < newCapacity - 1; i++)
		newNext[i] = i + 1;

	newNext[newCapacity - 1] = -1;

	delete[] this->elements;
	delete[] this->next;

	this->elements = newElements;
	this->next = newNext;
	this->firstEmpty = this->capacity;
	this->capacity = newCapacity;
}
// WC = BC = TC = Theta(1)
PriorityQueue::PriorityQueue(Relation r)
{
	// TODO - Implementation
	this->relation = r;
	this->init(1);
}

// BC = THETA(1) WC = THETA(n) AC = O(n)
void PriorityQueue::push(TElem e, TPriority p)
{
	// TODO - Implementation

	// if the queue is full, resize it
	if (this->firstEmpty == -1)
		this->resize();

	// if the queue is empty, add the element as the head
	if (this->head == -1)
	{
		this->head = this->firstEmpty;
		this->elements[this->head] = make_pair(e, p);
		this->firstEmpty = this->next[this->firstEmpty];
		this->next[this->head] = -1;
		return;
	}

	int current = this->head;
	int prev = -1;

	// find the position where the element should be added
	while (current != -1 && this->relation(this->elements[current].second, p))
	{
		prev = current;
		current = this->next[current];
	}
	// we need to add the node between prev and current
	int newPosition = this->firstEmpty;
	this->firstEmpty = this->next[this->firstEmpty];
	this->elements[newPosition] = make_pair(e, p);
	this->next[newPosition] = current;

	if (prev == -1)
	{
		this->head = newPosition;
	}
	else
	{
		this->next[prev] = newPosition;
	}
}

// throws exception if the queue is empty
// WC = BC = TC = Theta(1)
Element PriorityQueue::top() const
{
	// TODO - Implementation
	if (this->isEmpty())
		throw exception();

	return this->elements[this->head];
}

// WC = BC = TC = Theta(1)
Element PriorityQueue::pop()
{
	// TODO - Implementation
	if (this->isEmpty())
		throw exception();

	// save the head
	Element e = this->elements[this->head];
	int aux = this->head;
	this->head = this->next[this->head];

	// add the head to the list of empty positions
	this->next[aux] = this->firstEmpty;
	this->firstEmpty = aux;

	return e;
}

// BC = WC= TC = Theta(1)
bool PriorityQueue::isEmpty() const
{
	// TODO - Implementation
	if (this->head == -1)
		return true;
	return false;
}

PriorityQueue::~PriorityQueue()
{
	// TODO - Implementation
	delete[] this->elements;
	delete[] this->next;
}
// BC = Theta(1) WC = Theta(n) TC = O(n)
bool PriorityQueue::search(TElem elem) const
{
	int current = this->head;

	while (current != -1)
	{
		if (elements[current].first == elem)
			return true;

		current = next[current];
	}
	return false;
}
