#include <iostream>

template <typename T>
class DynamicVector
{
private:
    T *listOfElements;
    int size;
    int capacity;

    void resizeDynamicVector();
    T getElement(int pos);

public:
    int getSize();
    bool isElement(T elem);
    void addElement(T &elem);
    void deleteElement(int posOfElement);
    DynamicVector(const int capacity = 20);
    DynamicVector &operator=(const DynamicVector &v);
    DynamicVector(const DynamicVector &other);
    ~DynamicVector();
    T &operator[](int indexOfElement);
};

/*
copy constructor for the DynamicVector class
@param other - the DynamicVector object to be copied
*/
template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector &other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->listOfElements = new T[this->capacity];
    for (int index = 0; index < this->size; ++index)
        this->listOfElements[index] = other.listOfElements[index];
}

/*
getSize() - returns the size of the DynamicVector
*/
template <typename T>
inline int DynamicVector<T>::getSize()
{
    return this->size;
}

/*
overloading the operator [] for the DynamicVector class
@param indexOfElement - the index of the element to be returned
*/
template <typename T>
T &DynamicVector<T>::operator[](int indexOfElement)
{
    if (indexOfElement >= this->size || indexOfElement < 0)
        throw("Not a valid position");
    return this->listOfElements[indexOfElement];
}

/*
contructor for the DynamicVector class
@param capacity - the capacity of the DynamicVector
*/
template <typename T>
DynamicVector<T>::DynamicVector(const int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->listOfElements = new T[this->capacity];
}

/*
void resizeDynamicVector() - resizes the DynamicVector
in the function below, the capacity of the DynamicVector is doubled
*/
template <typename T>
void DynamicVector<T>::resizeDynamicVector()
{
    this->capacity *= 2;
    T *newListOfElements = new T[this->capacity];

    for (int i = 0; i < this->size; ++i)
        newListOfElements[i] = this->listOfElements[i];

    delete[] this->listOfElements;
    this->listOfElements = newListOfElements;
}

/*
desctructor for the DynamicVector class
we delete the list of elements
*/
template <typename T>
inline DynamicVector<T>::~DynamicVector()
{
    delete[] this->listOfElements;
}

/*
void addElement(T &elem) - adds an element to the DynamicVector
@param elem - the element to be added
*/
template <typename T>
void DynamicVector<T>::addElement(T &elem)
{
    if (this->size == this->capacity)
        resizeDynamicVector();

    this->listOfElements[this->size] = elem;
    this->size++;
}

/*
void deleteElement(int posOfElement) - deletes an element from the DynamicVector
@param posOfElement - the position of the element to be deleted
the element is deleted by shifting all the elements with one position to the left
*/
template <typename T>
void DynamicVector<T>::deleteElement(int posOfElement)
{
    if (posOfElement >= this->getSize() || posOfElement < 0)
        throw("Invalid position!!");

    for (int i = posOfElement; i < this->size - 1; ++i)
        this->listOfElements[i] = this->listOfElements[i + 1];

    this->size--;
}

/*
overloading the operator = for the DynamicVector class
we overload the = operator to copy the elements from one DynamicVector to another
@param v - the DynamicVector object to be copied
we overload the operator in order to copy the elements from one DynamicVector to another
*/
template <typename T>
DynamicVector<T> &DynamicVector<T>::operator=(const DynamicVector &v)
{
    if (this == &v)
        return *this;

    this->size = v.size;
    this->capacity = v.capacity;

    delete[] this->listOfElements;

    this->listOfElements = new T[this->capacity];

    for (int index = 0; index < this->size; ++index)
        this->listOfElements[index] = v.listOfElements[index];

    return *this;
}

/*
bool isElement(T elem) - checks if an element is in the DynamicVector
@param elem - the element to be checked
we return true if the element is in the DynamicVector, false otherwise
*/
template <typename T>
bool DynamicVector<T>::isElement(T elem)
{
    for (int index = 0; index < this->size; ++index)
        if (this->listOfElements[index].getTitle() == elem.getTitle())
            return true;

    return false;
}