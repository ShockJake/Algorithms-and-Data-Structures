#include "arrayList.h"

template <class T>
class ArrayBasedQueue
{
private:
    ArrayList<T> *array;
    int real_size, reserved_size;

public:
    ArrayBasedQueue();
    ArrayBasedQueue(int reserved_size);
    ~ArrayBasedQueue();
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void enqueue(const T &element);
    void dequeue();
    T front();
    T rear();
    string toString();

    class EmptyQueueException : exception
    {
        const char *what() const throw()
        {
            return "Queue is empty";
        }
    };

    class FullQueueExcepion : exception
    {
        const char *what() const throw()
        {
            return "Queue is full";
        }
    };
};

template <class T>
ArrayBasedQueue<T>::ArrayBasedQueue() // --- Basic constructor ---
{
    this->reserved_size = 20;
    this->real_size = 0;
}

template <class T>
ArrayBasedQueue<T>::ArrayBasedQueue(int reserved_size) // --- Constructor with arguments ---
{
    array = new ArrayList<T>(reserved_size);
    this->reserved_size = reserved_size;
    this->real_size = 0;
}

template <class T>
ArrayBasedQueue<T>::~ArrayBasedQueue() // --- Destructor ---
{
    array->~ArrayList();
}

template <class T>
bool ArrayBasedQueue<T>::isEmpty() const //checking if number of elements is equal to 0.
{
    return this->real_size == 0;
}

template <class T>
bool ArrayBasedQueue<T>::isFull() const // checking if number of elements is equal to the reserved size.
{
    return this->real_size == this->reserved_size;
}

template <class T>
void ArrayBasedQueue<T>::enqueue(const T &element) // Inserts element to the queue.
{
    if (!isFull())
    {
        array->push_back(element);
        real_size++;
    }
    else
    {
        throw FullQueueExcepion();
    }
}

template <class T>
void ArrayBasedQueue<T>::dequeue() // Removes element form the queue.
{
    if (!isEmpty())
    {
        array->pop_front();
        real_size--;
    }
    else
    {
        throw EmptyQueueException();
    }
}

template <class T>
T ArrayBasedQueue<T>::front() // Returns value of first element.
{
    if (!isEmpty())
    {
        return array->retrieve(0);
    }
    else
    {
        throw EmptyQueueException();
    }
}

template <class T>
T ArrayBasedQueue<T>::rear() // Returns value of the last element.
{
    if (!isEmpty())
    {
        return array->back();
    }
    else
    {
        throw EmptyQueueException();
    }
}

template <class T>
string ArrayBasedQueue<T>::toString() // Returns string that contains representation of queue. 
{
    if (!isEmpty())
    {
        string result = "";
        for (int i = 0; i < real_size - 1; i++)
        {
            result += to_string(array->retrieve(i));
            result += " <- ";
        }
        result += to_string(array->retrieve(real_size - 1));
        return result;
    }
    else
    {
        throw EmptyQueueException();
    }
}

template <class T>
int ArrayBasedQueue<T>::size() const // Returns number of elements.
{
    return real_size;
}