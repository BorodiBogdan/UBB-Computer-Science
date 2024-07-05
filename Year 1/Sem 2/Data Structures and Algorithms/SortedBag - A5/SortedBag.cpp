#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <algorithm>
using namespace  std;

Node NULLNODE = {0, 0, -1, -1, 0, -1};
#define nullNodePtr -1

//BC = WC = TC = THETA(1)
SortedBag::SortedBag(Relation r)
{
    this -> relation = r;
    this->capacity = 10;
    this->head = 9;
    this->root = nullNodePtr;
    this->firstIsEmpty = 0;
    this->numberOfElements = 0;

    this->elementList = new Node[this->capacity];
    this->next = new int[this->capacity];

    for (int i = 0; i < this->capacity; ++i)
    {
        this->next[i] = i + 1;
        this->elementList[i] = NULLNODE;
    }

    this->next[this->head] = nullNodePtr;
}

//BC = WC = TC = THETA(Capacity)
void SortedBag::resize()
{
    int oldCapacity = this->capacity;
    this->capacity = this->capacity * 2;
    this -> firstIsEmpty = oldCapacity;

    Node *newElementList = new Node[this->capacity];
    int *newNext = new int[this->capacity];

    newNext[this->head] = oldCapacity;
    this->head = this->capacity - 1;

    for (int i = 0; i < oldCapacity; ++i)
    {
        newElementList[i] = this->elementList[i];
        newNext[i] = this->next[i];
    }

    for (int i = oldCapacity; i < this->capacity; ++i)
    {
        newNext[i] = i + 1;
        newElementList[i] = NULLNODE;
    }

    newNext[head] = nullNodePtr;

    delete[] this->next;
    delete[] this->elementList;

    this->next = newNext;
    this->elementList = newElementList;
}
//BC = Theta(1) WC = THETA(number of nodes) TC = O (number of nodes)
int SortedBag::searchPosition(TComp elem) const
{
    int currentPos = nullNodePtr;
    int nextPos = this -> root;

    TComp value = 0;

    while (nextPos != nullNodePtr)
    {
        // on the left we store lower values
        // on the right we store bigger values
        currentPos = nextPos;
        value = elementList[currentPos].info;

        if (value == elem)
            return currentPos;
        else if (this -> relation(elem, value) == true)
            nextPos = this->elementList[currentPos].left;
        else
            nextPos = this->elementList[currentPos].right;
    }

    return nullNodePtr;
}
//BC = Theta(1) WC = THETA(number of nodes) TC = O (number of nodes)
int SortedBag::searchDadOfPosition(TComp elem) const
{
    int currentPos = this->root;
    int nextPos = this->root;
    TComp value = 0;

    while (nextPos != nullNodePtr)
    {
        // on the left we store lower values
        // on the right we store bigger values
        currentPos = nextPos;
        value = elementList[currentPos].info;

        if (this -> relation(elem, value) == true)
            nextPos = this->elementList[currentPos].left;
        else
            nextPos = this->elementList[currentPos].right;

        if (nextPos != nullNodePtr && elementList[nextPos].info == elem)
            return currentPos;
    }

    return currentPos;//it is a leaf
}
//BC = Theta(1) WC = THETA(capacity) TC = O(capacity)
void SortedBag::add(TComp elem)
{
    if (firstIsEmpty == nullNodePtr)
        resize();

    this->numberOfElements++;

    if (this->numberOfElements == 1)
    {
        this->root = this->firstIsEmpty;
        this->elementList[this->root] = {elem, 1, nullNodePtr, nullNodePtr, this -> root, -1};
        this->firstIsEmpty = this->next[this->firstIsEmpty];
        return;
    }

    int currentPos = this->searchPosition(elem);

    if (currentPos != nullNodePtr)
    {
        this->elementList[currentPos].frequency++;
        //cout << elem << " " << currentPos << " " << elementList[currentPos].frequency << "\n";
        return;
    }

    int posOfDad = this->searchDadOfPosition(elem);
    int value = elementList[posOfDad].info;

    // currentPos is on the last node of the tree
    // on the left we store lower values
    // on the right we store bigger values

    if (this->relation(value, elem) == false)
        this->elementList[posOfDad].left = this->firstIsEmpty;
    else
        this->elementList[posOfDad].right = this->firstIsEmpty;

    elementList[firstIsEmpty] = {elem, 1, nullNodePtr, nullNodePtr, firstIsEmpty, posOfDad};
    firstIsEmpty = next[firstIsEmpty];
}

//BC = Theta(1) WC = Theta(n) TC = O(n)
bool SortedBag::remove(TComp elem)
{
    // case 1 -> we need to update the frequency of a node -> happy case

    int posOfNode = this->searchPosition(elem);

    if (posOfNode == nullNodePtr)
        return false; // nothing to remove

    Node nodeToBeRemoved = this->elementList[posOfNode];

    Node dadOfNodeToBeRemoved = this -> elementList[this ->searchDadOfPosition(elem)];

    return this ->removeNode(nodeToBeRemoved, dadOfNodeToBeRemoved);
}

//BC = Theta(1) WC = Theta(1) TC = Theta(1)
bool SortedBag::removeNode(Node nodeToBeRemoved, Node dadOfNodeToBeRemoved){
    int posOfNode = nodeToBeRemoved.pos;

    if (posOfNode == nullNodePtr)
        return false; // nothing to remove

    this->numberOfElements--; // we will remove it anyway

    if (this->elementList[posOfNode].frequency > 1)
    {
        this->elementList[posOfNode].frequency--;
        return true; //-> happy ending
    }
    else
    {
        // case one -> it's a leaf

        if (this->elementList[posOfNode].left == nullNodePtr && this->elementList[posOfNode].right == nullNodePtr)
        {
            int posOfDadNode = dadOfNodeToBeRemoved.pos;

            // it is a leaf but also the root ->

            if(posOfNode == this -> root){//it is the root
                freeSpace(posOfNode);
                this -> root = nullNodePtr;
            }
            else{
                if(this -> elementList[posOfDadNode].left == posOfNode)
                    this -> elementList[posOfDadNode].left = nullNodePtr;
                else this -> elementList[posOfDadNode].right = nullNodePtr;

                freeSpace(posOfNode);
            }
        }
        else if (this->elementList[posOfNode].left == nullNodePtr || this->elementList[posOfNode].right == nullNodePtr)
        {
            // case 2 - just one child
            // in this case we need to     the dad node to the children
            int nextPos = 0;

            if(this->elementList[posOfNode].left == nullNodePtr)
                nextPos = elementList[posOfNode].right;
            else nextPos = elementList[posOfNode].left;

            if(posOfNode == this -> root){
                freeSpace(this -> root);
                this -> root = nextPos;
            }
            else {
                //this is for nodes with one son
                int posOfDadNode = dadOfNodeToBeRemoved.pos;

                if(this -> elementList[posOfDadNode].left == posOfNode)
                    this -> elementList[posOfDadNode].left = nextPos;
                else this -> elementList[posOfDadNode].right = nextPos;

                freeSpace(posOfNode);
            }
        }
        else {
            // finally last case -> we have two children -> in this case we can take a leaf and replace
            // it with the dad node -> the tree keeps it's properties
            // not any leaf is proper for this task
            // we will parse the smaller vertices to find the leaf(the left children) because
            // we need a node bigger then the left part of the tree
            // and smaller then the right part

            int positionIterator = this->elementList[posOfNode].right;
            int positionOfTheNodeThatWillBeDeleted = nullNodePtr;
            int posOfDadNode = nullNodePtr;

            while (positionIterator != nullNodePtr) {
                posOfDadNode = positionOfTheNodeThatWillBeDeleted;
                positionOfTheNodeThatWillBeDeleted = positionIterator;
                positionIterator = this->elementList[positionIterator].left;
            }

            int rightChildOfDeletedNode = this -> elementList[positionOfTheNodeThatWillBeDeleted].right;

            this -> elementList[posOfNode].info = this -> elementList[positionOfTheNodeThatWillBeDeleted].info;
            this -> elementList[posOfNode].frequency = this -> elementList[positionOfTheNodeThatWillBeDeleted].frequency;

            if(positionOfTheNodeThatWillBeDeleted == this -> elementList[posOfNode].right){
                this-> elementList[posOfNode].right = this -> elementList[positionOfTheNodeThatWillBeDeleted].right;

                freeSpace(positionOfTheNodeThatWillBeDeleted);
                return true;
            }

            // it is a leaf but also the root ->

            if(positionOfTheNodeThatWillBeDeleted == this -> root){//it is the root
                freeSpace(positionOfTheNodeThatWillBeDeleted);
                this -> root = nullNodePtr;
            }
            else{
                if(this -> elementList[posOfDadNode].left == positionOfTheNodeThatWillBeDeleted)
                    this -> elementList[posOfDadNode].left = rightChildOfDeletedNode;
                else this -> elementList[posOfDadNode].right = nullNodePtr;

                freeSpace(posOfNode);
            }
        }
    }

    return true;
}
//BC = Theta(1) WC = Theta(n) TC = O(n)
bool SortedBag::search(TComp elem) const
{
    int currentPos = this->searchPosition(elem);

    return currentPos != nullNodePtr;
}
//BC = Theta(1) WC = Theta(n) TC = O(n)
int SortedBag::nrOccurrences(TComp elem) const
{
    int currentPos = this->searchPosition(elem);

    if (currentPos == nullNodePtr)
        return 0;
    else
        return this->elementList[currentPos].frequency;
}
//BC = Theta(1) WC = Theta(1) TC = Theta(1)
int SortedBag::size() const
{
    return this->numberOfElements;
}

//BC = Theta(1) WC = Theta(1) TC = Theta(1)
bool SortedBag::isEmpty() const
{
    return this->numberOfElements == 0;
}

SortedBagIterator SortedBag::iterator() {
    return SortedBagIterator(*this);
}

SortedBag::~SortedBag()
{
    delete [] this->next;
    delete [] this->elementList;
}

//BC = Theta(1) WC = Theta(1) TC = Theta(1)
void SortedBag::freeSpace(int spot) {
    this -> elementList[spot] = NULLNODE;
    this -> next[head] = spot;
    this -> head = spot;
    this -> next[head] = nullNodePtr;
}