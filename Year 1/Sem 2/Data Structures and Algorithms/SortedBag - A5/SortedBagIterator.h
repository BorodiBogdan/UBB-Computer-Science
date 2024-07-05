#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	SortedBag& bag;
	SortedBagIterator(SortedBag& b);

	//TODO - Representation
    int sizeOfList;
    Node *listOfNodes;
    int pos;
    int howMany;
    void dfs(Node root, int pos);



public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
    TElem remove();
};

