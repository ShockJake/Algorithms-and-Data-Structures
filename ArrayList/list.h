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

    virtual int locate(const T& a) = 0;
    virtual int end() = 0;
    virtual int first() = 0;
    virtual int next(int index) = 0;
    virtual int previous(int index) = 0;
    virtual int last() = 0;
    virtual int back() = 0;
    virtual void push_front(const T& a) = 0;
    virtual void push_back(const T& a) = 0;
    virtual bool pop_front() = 0;
    virtual bool pop_back() = 0;
};

#endif //!LIST_H
