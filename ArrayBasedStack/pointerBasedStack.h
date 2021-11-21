#include "linkedList.h"
#include <iostream>

template <class T>
class PointerBasedStack
{
private:
    LinkedList<T> *stack;
    int max_size;

public:
    PointerBasedStack(int max_size);
    void push(const T &element);
    T pop();
    T peek();
    bool isEmpty();
    int size();
    bool isFull();
    class FullStackException : public exception
    {
        const char *what() throw()
        {
            return "Stack is full\n";
        }
    };

    class EmptyStackException : public exception
    {
        const char *what() throw()
        {
            return "Stack is empty and not operable\n";
        }
    };
};

template <class T>
PointerBasedStack<T>::PointerBasedStack(int max_size)
{
    stack = new LinkedList<T>();
    this->max_size = max_size;
}

template <class T>
void PointerBasedStack<T>::push(const T &element)
{
    if (isFull())
    {
        throw FullStackException();
    }
    else
    {
        stack.push_back(element);
    }
}

template <class T>
T PointerBasedStack<T>::pop()
{
    if(isEmpty())
    {
        throw EmptyStackException();
    }
    else
    {
        stack.pop_back();
    }
}

template <class T>
T PointerBasedStack<T>::peek()
{
    if(isEmpty())
    {
        throw EmptyStackException();
    }
    else
    {
        stack.retrieve(stack.last());
    }
}

template <class T>
bool PointerBasedStack<T>::isEmpty()
{
    return stack.isEmpty();
}

template <class T>
int PointerBasedStack<T>::size()
{
    return stack.getLength();
}

template <class T>
bool PointerBasedStack<T>::isFull()
{
    return size() == max_size;
}