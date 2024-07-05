#pragma once
#include "SortedMap.h"

// DO NOT CHANGE THIS PART
class SMIterator
{
	friend class SortedMap;

private:
	const SortedMap &map;
	SMIterator(const SortedMap &mapionar);
	int currentIndex;
	// TODO - Representation

public:
	// One operation -> BC = WC = TC = T(1)
	void first();
	// One operation -> BC = WC = TC = T(1)
	void next();
	// One operation -> BC = WC = TC = T(1)
	bool valid() const;
	// One operation -> BC = WC = TC = T(1)
	TElem getCurrent() const;
	// Extra op
	void jumpForward(int k);
};
