#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

template <class T, class U>
class Element : public std::pair<T, U>
{
};

template <class T>
class PriorityQueue
{
private:
    std::vector<Element<T, int>> *data = nullptr;
    int _size = 0;
    void heapify(int i);

public:
    // Cunstructor
    PriorityQueue();
    // Destructor
    ~PriorityQueue();
    // Insertion
    void insertElement(Element<T, int> e);
    // Getting value of the biggest priority
    int getMaxPriority();
    // Getting and removing element of the highest priority
    Element<T, int> pop();
    // Increasing elements priority
    void increasePriority(Element<T, int> e, int priority);
    // Get size
    int getSize();
    // Print priority queue
    std::string toString();

    class EmptyQueueException : std::exception
    {
        const char *what() const throw()
        {
            return "Queue is empty";
        }
    };

private:
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }
    int parrent(int i) { return floor(i / 2); }
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    data = new std::vector<Element<T, int>>;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    delete data;
}

template <class T>
int PriorityQueue<T>::getSize()
{
    return data->size();
}

inline std::string to_string(std::string _Val)
{ // avoiding problem with convertion string to string
    return _Val;
}

template <class T>
std::string PriorityQueue<T>::toString()
{
    if (_size == 0)
    {
        throw EmptyQueueException();
    }

    std::string result = "";
    Element<T, int> e;
    for (int i = 0; i < data->size() - 1; i++)
    {
        e = data->at(i);
        result += to_string(e.first);
        result += " ";
    }
    e = data->at(data->size() - 1);
    result += to_string(e.first);

    return result;
}

template <class T>
void PriorityQueue<T>::heapify(int i)
{
    int l = i * 2;
    int r = i * 2 + 1;
    int lg = i;

    if (l < this->_size && r <= this->_size)
    {
        if(r == this->_size)
        {
            r--;
        }

        Element<T, int> leftEl = data->at(l);
        Element<T, int> rightEl = data->at(r);
        Element<T, int> lgEl = data->at(lg);

        if (leftEl.second > lgEl.second)
        {
            lg = l;
        }
        else if (rightEl.second > lgEl.second)
        {
            lg = r;
        }
        if (lg != i)
        {
            std::swap(data->at(i), data->at(lg));
            heapify(lg);
        }
    }
}

template <class T>
void PriorityQueue<T>::insertElement(Element<T, int> e)
{
    _size++;
    data->push_back(e);
    for (int i = data->size() - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

template <class T>
Element<T, int> PriorityQueue<T>::pop()
{
    if(this->_size == 0)
    {
        throw EmptyQueueException();
    }

    Element<T, int> result = data.at(0);
    data[0] = data->back();
    data->pop_back();
    heapify(0);

    return result;
}

#endif // PRIORITY_QUEUE_HPP