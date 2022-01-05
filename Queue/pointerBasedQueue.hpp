#include "linkedlist.h"

template <class T>
class PointerBasedQueue
{
private:
    LinkedList<T> *linkedQueue;
    int real_size, reserved_size;

public:
    PointerBasedQueue();
    PointerBasedQueue(int reserved_size);
    ~PointerBasedQueue();

    bool isEmpty() const;
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
PointerBasedQueue<T>::PointerBasedQueue() // --- Basic constructor ---
{
    linkedQueue = new LinkedList<T>();
    this->real_size = 0;
    this->reserved_size = 20;
}

template <class T>
PointerBasedQueue<T>::PointerBasedQueue(int reserved_size) // --- Constructor with arguments ---
{
    linkedQueue = new LinkedList<T>();
    this->real_size = 0;
    this->reserved_size = reserved_size;
}

template <class T>
PointerBasedQueue<T>::~PointerBasedQueue() // --- Destructor ---
{
    linkedQueue->~LinkedList();
}

template <class T>
bool PointerBasedQueue<T>::isEmpty() const //checking if number of elements is equal to 0.s
{
    return real_size == 0;
}

template <class T>
int PointerBasedQueue<T>::size() const // Returns number of elements.
{
    return real_size;
}

template <class T>
void PointerBasedQueue<T>::enqueue(const T &element) // Inserts element to the queue.
{
    if (real_size != reserved_size)
    {
        linkedQueue->push_back(element);
        real_size++;
    }
    else
    {
        throw FullQueueExcepion();
    }
}

template <class T>
void PointerBasedQueue<T>::dequeue() // Removes element form the queue.
{
    if (!isEmpty())
    {
        linkedQueue->pop_front();
        real_size--;
    }
    else
    {
        throw EmptyQueueException();
    }
}

template <class T>
T PointerBasedQueue<T>::front() // Returns value of first element.
{
    if (!isEmpty())
    {
        return linkedQueue->front();
    }
    else
    {
        throw EmptyQueueException();
    }
}

template <class T>
T PointerBasedQueue<T>::rear() // Returns value of the last element.
{
    if (!isEmpty())
    {
        return linkedQueue->back();
    }
    else
    {
        throw EmptyQueueException();
    }
}

template <class T>
string PointerBasedQueue<T>::toString() // Returns string that contains representation of queue.
{
    if(!isEmpty()) 
    {
        string result = "";
        for (int i = 0; i < real_size - 1; i++)
        {
            result += to_string(linkedQueue->retrieve(i));
            result += " <- ";
        }
        result += to_string(linkedQueue->retrieve(real_size - 1));
        return result;
        
    }
    else 
    {
        throw EmptyQueueException();
    }
}