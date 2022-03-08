#ifndef SET_HPP
#define SET_HPP

#include <string>
#include "./HashTable/hashTable.hpp"

#define MAX_SIZE 10

template <class T>
class Set
{
private:
    HashTable<T> data = nullptr;

public:
    // Constructor
    Set(int size = MAX_SIZE);
    // Destructor
    ~Set();

    // Inserting element to a set
    void insert(const T &element);
    // Getting and removing element from the set
    T remove(const T &element);

    // Checking if the set is Empty
    bool isEmpty();
    // Checking if the fiven element appears in the set
    bool isMember(const T &element) const;

    // Delete all elements
    void clear();
    // Remove all elements
    void makeEmpty();
    // Assignment operator
    Set operator=(const Set &other);

    // Get a set of common elements
    Set getIntersection(const Set &other);
    // Get a set of all elements form all elements from two sets
    Set getUnion(const Set &other);
    // Get a set of elements that does not appear in other set
    Set getDifference(const Set &other);
    // Removes all elements in fisrt set that equal to elements of second set
    Set popAll(const Set &other);

    // Display set
    std::string toString();

    // Exception for empty set
    class EmptySetException : std::exception
    {
        const char *what() const throw()
        {
            return "Set is empty and not operable";
        }
    };

    // Exception for already existing element
    class ExistingElementException : std::exception
    {
        const char *what() const throw()
        {
            return "The element is already exists in set";
        }
    };

    class NotFoundException : std::exception
    {
        const char *what() const throw()
        {
            return "Element not found";
        }
    };

private:
    Set makeIntersection(const Set &other);
    Set makeUnion(const Set &other);
    Set makeDifference(const Set &other);
};

template <class T>
Set<T>::Set(int size)
{
    data = new HashTable<T>(size);
}

template <class T>
Set<T>::~Set()
{
    data.~HashTable();
}

template <class T>
bool Set<T>::isEmpty()
{
    return data.isEmpty();
}

template <class T>
bool Set<T>::isMember(const T &element) const
{
    return data.contains(element);
}

template <class T>
void Set<T>::insert(const T &element)
{
    if (!isMember(element))
    {
        data.insert(element);
    }
    else
    {
        throw ExistingElementException();
    }
}

template <class T>
T Set<T>::remove(const T &element)
{
    if (isMember(element))
    {
        data.remove(element);
    }
    else
    {
        throw NotFoundException();
    }
}

template <class T>
void Set<T>::clear()
{
    data.clear();
}

template <class T>
void Set<T>::makeEmpty()
{
    data.makeEmpty();
}

template <class T>
Set<T> Set<T>::operator=(const Set &other)
{
    if (this == &other)
    {
        
        
        
    }
    
}

template <class T>
Set<T> Set<T>::getIntersection(const Set &other)
{
    if (!(this->isEmpty() && other.isEmpty()))
    {
        return makeIntersection(other);
    }
    else
    {
        return Set();
    }
}

template <class T>
Set<T> Set<T>::getUnion(const Set &other)
{
    if (!(this->isEmpty() && other.isEmpty()))
    {
        return makeUnion(other);
    }
    else
    {
        return Set();
    }
}

template <class T>
Set<T> Set<T>::getDifference(const Set &other)
{
    if (!(this->isEmpty() && other.isEmpty()))
    {
        return makeDifference(other);
    }
    else
    {
        return Set();
    }
}

template <class T>
Set<T> Set<T>::popAll(const Set &other)
{
    if (!other.isEmpty())
    {
    }
}

template <class T>
std::string Set<T>::toString()
{
    return data.toString();
}

#endif // SET_HPP