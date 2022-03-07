#include <iostream>
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
    bool isMember(const T &element);

    // Delete all the elements
    void clear();

    // Get a set of common elements
    Set getIntersection(const Set &other);
    // Get a set of all elements form all elements from two sets
    Set getUnion(const Set &other);
    // Get a set of elements that does not appear in other set
    Set getDifference(const Set &other);
    // Removes all elements in fisrt set that equal to elements of second set
    Set popAll(cosnt Set &other);
};
