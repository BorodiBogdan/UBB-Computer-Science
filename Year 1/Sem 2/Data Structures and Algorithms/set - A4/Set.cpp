#include "Set.h"
#include "SetITerator.h"
#include <iostream>

// BC = WC = TC = Theta(capacity + numberOfElements)
void Set::rehash()
{
	////Worst case : Teta(n), Best case: Teta(n), Total complexity: O(n) where n is the nb of elements in the table
	int oldCapacity = this->capacity;
	this->capacity *= 2;
	Node **newTable = new Node *[this->capacity] {};

	for (int i = 0; i < oldCapacity; ++i)
	{
		Node *entry = HashTable[i];

		while (entry != nullptr)
		{
			int index = hashFunction(entry->info);

			Node *newNode = new Node;
			newNode->info = entry->info;
			newNode->next = newTable[index];
			newTable[index] = newNode;
			entry = entry->next;
		}
	}

	for (int i = 0; i < oldCapacity; ++i)
	{
		Node *entry = HashTable[i];
		while (entry != nullptr)
		{
			Node *temp = entry;
			entry = entry->next;
			delete temp;
		}
	}
	delete[] HashTable;
	this->HashTable = newTable;
}

// BC = WC = TC = Theta(capacity)
Set::Set()
{
	// TODO - Implementation
	this->capacity = 1000;
	this->HashTable = new Node *[this->capacity];
	this->numberOfElements = 0;
	this->loadFactor = 0.5;

	for (int i = 0; i < this->capacity; ++i)
		HashTable[i] = nullptr;
}

// BC = Theta(1), WC = Theta(numberOfElements + capacity)(we need to rehash), TC = O(numberOfElements)
bool Set::add(TElem elem)
{
	// TODO - Implementation
	if (this->search(elem) == true)
		return false;

	int position = hashFunction(elem);

	Node *current = HashTable[position];
	Node *nodeToAdd = new Node;

	nodeToAdd->info = elem;
	nodeToAdd->next = current;
	nodeToAdd->previous = nullptr;

	if (current != nullptr)
		current->previous = nodeToAdd;

	this->HashTable[position] = nodeToAdd;
	this->numberOfElements++;

	if (this->numberOfElements / this->capacity >= this->loadFactor)
		this->rehash();

	return true;
}

// BC = Theta(1), WC = Theta(numberOfElements)(all elements have the same hash key), TC = O(numberOfElements)
bool Set::remove(TElem elem)
{
	// TODO - Implementation
	int position = hashFunction(elem);

	Node *current = HashTable[position];
	Node *previous = nullptr;

	while (current != nullptr && current->info != elem)
	{
		previous = current;
		current = current->next;
	}

	if (current == nullptr)
		return false;

	if (previous == nullptr)
	{
		HashTable[position] = current->next;
		current->previous = nullptr;
	}
	else
	{
		previous->next = current->next;
		current->previous = previous;
	}
	delete current;
	this->numberOfElements--;

	return true;
}

// BC = Theta(1), WC = Theta(numberOfElements)(all elements have the same hash key), TC = O(numberOfElements)
bool Set::search(TElem elem) const
{
	// TODO - Implementation
	int position = hashFunction(elem);

	Node *current = HashTable[position];

	while (current != nullptr && current->info != elem)
		current = current->next;

	if (current == nullptr)
		return false;

	return true;
}

// BC = WC = TC = Theta(1);
int Set::size() const
{
	// TODO - Implementation
	return this->numberOfElements;
}
// BC = WC = TC = Theta(1);
bool Set::isEmpty() const
{
	// TODO - Implementation
	return this->numberOfElements == 0;
}
// BC = WC = TC = Theta(size + numberOfElements);
Set::~Set()
{
	// TODO - Implementation

	for (int i = 0; i < this->capacity; ++i)
		if (HashTable[i] != nullptr)
			delete[] HashTable[i];

	if (HashTable != nullptr)
		delete[] HashTable;
}
// BC = WC = TC = Theta(1);
SetIterator Set::iterator() const
{
	return SetIterator(*this);
}
