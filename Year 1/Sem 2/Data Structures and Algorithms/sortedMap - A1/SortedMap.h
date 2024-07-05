#pragma once
// DO NOT INCLUDE SORTEDMAPITERATOR

// DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
#include <utility>
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TPAIR pair<TKey, TValue>(-111111, -111111);
class SMIterator;
typedef bool (*Relation)(TKey, TKey);

class SortedMap
{
	friend class SMIterator;

private:
	/*
		We represent the map as a dynamic vector and we keep the elements sorted
		in order to perform the search operation faster
	*/
	// Extra:
	TElem *elements;
	Relation rel;
	int capacity;
	int numberOfPairs;
	int getPositionOfTheElementGreaterOrEqual(TKey key) const;

public:
	// implicit constructor
	SortedMap(Relation r);

	// adds a pair (key,value) to the map
	// if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
	// if the key SMes not exist, a new pair is added and the value null is returned
	// BC: T(n), WC: T(n), TC: O(n) - we need to resize the array
	TValue add(TKey c, TValue v);

	// searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
	// BC: T(1), WC: T(log2(n)), O(log2(n))
	TValue search(TKey c) const;

	// removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
	// BC: T(n), WC: T(n), TC: T(n)
	TValue remove(TKey c);

	// returns the number of pairs (key,value) from the map
	// BC = WC = TC = T(1)
	int size() const;

	// checks whether the map is empty or not
	// BC = WC = TC = T(1)
	bool isEmpty() const;

	// return the iterator for the map
	// the iterator will return the keys following the order given by the relation
	// BC = WC = TC = T(1)
	SMIterator iterator() const;

	// destructor
	~SortedMap();
};