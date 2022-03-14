#ifndef SET_HPP
#define SET_HPP

template <class T>
class Set
{
public:
    // Function to insert element into a Set
    virtual bool insert(const T &element) = 0;
    // Function to remove element from a Set
    virtual bool remove(const T &element) = 0;
    // Function to get size
    virtual int size() = 0;
    // Function to check if Set contains an element
    virtual bool contains(const T &element) = 0;
    // Function to check if Set is empty
    virtual bool isEmpty() = 0;
    // Function to clear all elements
    virtual void makeEmpty() = 0;

    // // Function to create union of two sets
    // virtual Set getUnion(Set &other) = 0;
    // // Function to create intersection of two sets
    // virtual Set getIntersection(Set &other) = 0;
    // // Function to create difference of two sets
    // virtual Set getDifference(Set &other) = 0;
    // // Function to pop all elements form other Set
    // virtual void popAll(Set &other) = 0;
};

#endif // SET_HPP
