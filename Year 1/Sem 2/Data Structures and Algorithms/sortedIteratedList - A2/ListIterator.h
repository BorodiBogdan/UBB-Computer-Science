#pragma once
#include "SortedIteratedList.h"

// DO NOT CHANGE THIS PART
class ListIterator
{
	friend class SortedIteratedList;

private:
	const SortedIteratedList &list;
	ListIterator(const SortedIteratedList &list);

	// TODO - Representation
	node *iterator;
	int howManyLeft;

public:
	void first();
	void next();
	bool valid() const;
	TComp getCurrent() const;
};
