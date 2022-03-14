#ifndef SET_HPP
#define SET_HPP

#include "hashTable.hpp"

template <class T>
class Set
{
private:
    HashTable<T> data = nullptr;

public:
    // Constructor
    Set(int size = 10);
    // Destructor
    ~Set();

    // Function to insert element into a Set
    bool insert(const T &element);
    // Function to remove element from a Set
    bool remove(const T &element);
    // Function to get size
    int size();
    // Function to check if Set contains an element
    bool contains(const T &element);
    // Function to check if Set is empty
    bool isEmpty();
    // Function to clear all elements
    void makeEmpty();

    // Function to create union of two sets
    Set getUnion(Set &other);
    // Function to create intersection of two sets
    Set getIntersection(Set &other);
    // Function to create difference of two sets
    Set getDifference(Set &other);
    // Function to pop all elements form other Set
    void popAll(Set &other);

    // Exception for already existing element
    class ExistingElementException : std::exception
    {
        const char *what() const throw()
        {
            return "Element already exists";
        }
    };

    // Exception for empty Set
    class EmptySetException : std::exception
    {
        const char *what() const throw()
        {
            return "Set is empty and not operable";
        }
    };
};

template <class T>
Set<T>::Set(int size = 10)
{
    this.data = new HashTable(size);
}

template <class T>
Set<T>::~Set()
{
    this.data.~HashTable();
}

template <class T>
bool Set<T>::contains(const T &element)
{
    return this.data.contains(element);
}

template <class T>
int Set<T>::size()
{
    return this.data.real_size;
}

template <class T>
bool Set<T>::insert(const T &element)
{
    if (!isEmpty())
    {
        if (!this->data.contains(element))
        {
            return data.insert(element);
        }
        else
        {
            throw ExistingElementException();
        }
    }
    else
    {
        throw EmptySetException();
    }
}

template <class T>
bool Set<T>::isEmpty()
{
    return data.isEmpty();
}

template <class T>
bool Set<T>::contains(const T &element)
{
    if (!isEmpty())
    {
        return data.contains(element);
    }
    else
    {
        throw EmptySetException();
    }
}

template <class T>
void Set<T>::makeEmpty()
{
    if (!isEmpty())
    {
        data.makeEmpty();
    }
    else
    {
        throw EmptySetException();
    }
}

template <class T>
bool Set<T>::remove(const T &element)
{
    if (!isEmpty())
    {
        return data.remove(element);
    }
    else
    {
        throw EmptySetException();
    }
}

template <class T>
void Set<T>::popAll(Set &other)
{
    if(!other.isEmpty())
    {
        data.popAll(other.data);
    }
}



#endif // SET_HPP
