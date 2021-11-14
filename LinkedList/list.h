#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>

using namespace std;

template <class T>
class List
{
public:
    virtual bool isEmpty() = 0;
    virtual int getLength() = 0;
    virtual bool insert(int index, const T& a) = 0;
    virtual bool remove(int index) = 0;
    virtual T retrive(int index) = 0;
    virtual string toString() = 0;
};

#endif //!LIST_H