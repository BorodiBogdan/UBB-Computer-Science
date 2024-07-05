#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;


//BC = WC = TC = Theta(n) where n is the number of nodes
SortedBagIterator::SortedBagIterator (SortedBag &c) : bag(c)
{
    this -> first();
}

//BC = WC = TC = Theta(n) where n is the number of nodes
void SortedBagIterator::dfs(Node root, int pos)
{
    int left = bag.elementList[pos].left;
    int right = bag.elementList[pos].right;

    if(left >= 0)
        bag.elementList[left].posOfDadd = pos;

    if(right >= 0)
        bag.elementList[right].posOfDadd = pos;

    int newPos = bag.elementList[pos].left;

    if (newPos != -1)
        dfs(this->bag.elementList[newPos], newPos);

    newPos = bag.elementList[pos].right;
    this->listOfNodes[this->sizeOfList++] = root;

    if (newPos != -1)
        dfs(this->bag.elementList[newPos], newPos);

}

//BC = WC = TC = Theta(n) where n is the number of nodes
void SortedBagIterator::first()
{
    this->sizeOfList = 0;
    this->listOfNodes = new Node[bag.numberOfElements + 1];

    if (bag.root != -1)
        dfs(bag.elementList[bag.root], bag.root);

    this->pos = 0;
    this->howMany = this->listOfNodes[this->pos].frequency;
}

//BC = WC = TC = THETA(1)
void SortedBagIterator::next()
{
    if (!this->valid())
        throw exception();

    if (this->howMany >= 1)
        this->howMany--;

    if (this->howMany == 0)
    {
        this->pos = this->pos + 1;
        this->howMany = this->listOfNodes[pos].frequency;
    }
}

//BC = WC = TC = THETA(1)
bool SortedBagIterator::valid() {
    // TODO - Implementation
    if (this->pos >= this->sizeOfList)
        return false;

    return true;
}

//BC = WC = TC = THETA(1)
TComp SortedBagIterator::getCurrent() {
    // TODO - Implementation
    if (!this->valid())
        throw exception();

    return this -> listOfNodes[this -> pos].info;
}
//BC = WC = TC = THETA(1)
TElem SortedBagIterator::remove() {
    if(!this -> valid())
        throw exception();

    Node current = this -> listOfNodes[pos];
    Node dadOfCurrent;
    TComp elem = this -> listOfNodes[pos].info;

    if(listOfNodes[pos].posOfDadd != -1)
        dadOfCurrent = this -> bag.elementList[listOfNodes[pos].posOfDadd];
    else dadOfCurrent = {0, -1, -1, -1, -1 };

    this -> next();
    this -> bag.removeNode(current, dadOfCurrent);

    return elem;
}

