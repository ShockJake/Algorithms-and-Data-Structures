#include <iostream>
#include "arrayList.h"

using namespace std;

template <class T>
class ArrayBasedStack
{
private:
    ArrayList<T> *stack;
    int max_size;
public:
    ArrayBasedStack();
    ArrayBasedStack(int size);
    void push(const T &element);
    T pop();
    T peek();
    bool isEmpty();
    int size();
    bool isFull();

    class EmptyStackException : public exception
    {
        const char *what() throw()
        {
            return "Stack is empty and not operable\n";
        }
    };

    class FullStackException : public exception
    {
        const char *what() throw()
        {
            return "Stack is full\n";
        }
    };
};

template <class T>
ArrayBasedStack<T>::ArrayBasedStack(int max_size)
{
    stack = new ArrayList<T>(max_size);
    this->max_size = max_size;
}

template <class T>
void ArrayBasedStack<T>::push(const T &element)
{
    if(size() == max_size)
    {
        throw FullStackException();
    }
    else
    {
        stack->push_back(element);
    }
}

template <class T>
T ArrayBasedStack<T>::pop()
{
    if(isEmpty())
    {
        throw EmptyStackException();
    }
    else
    {
        T element = stack->retrieve(stack->last());
        stack->pop_back();
        return element;
    }
}

template <class T>
T ArrayBasedStack<T>::peek()
{
    if(isEmpty())
    {
        throw EmptyStackException();
    }
    else
    {
        return stack->retrieve(stack->last());
    }
}

template <class T>
bool ArrayBasedStack<T>::isEmpty()
{
    return stack->isEmpty();
}

template <class T>
int ArrayBasedStack<T>::size()
{
    return stack->getLength();
}

template <class T>
bool ArrayBasedStack<T>::isFull()
{
    return size() == max_size;
}

