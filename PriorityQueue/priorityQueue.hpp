#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>
#include <vector>
#include <string>

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

    class LackOfElementException : std::exception
    {
        const char *what() const throw()
        {
            return "There is no such element in the queue";
        }
    };

private:
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }
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

template <class T>
int PriorityQueue<T>::getMaxPriority()
{
    Element<T, int> el = data.at(0);
    return el.second;
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
    int l = left(i);
    int r = right(i);
    int lg = i;

    if (l < this->_size && r <= this->_size)
    {
        if (r == this->_size)
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
void PriorityQueue<T>::increasePriority(Element<T, int> e, int priority)
{
    Element<T, int> innerEl;
    for (int i = 0; i < data->size(); i++)
    {
        innerEl = data.at(i);
        if (innerEl.first == e.first && innerEl.second == e.second)
        {
            if (priority < innerEl.second)
            {
                std::cout << "New priority is smaller that current\n";
            }

            innerEl.second = priority;
            heapify(0);
            return;
        }
    }
    throw LackOfElementException();
}

template <class T>
Element<T, int> PriorityQueue<T>::pop()
{
    if (this->_size == 0)
    {
        throw EmptyQueueException();
    }

    Element<T, int> result = data.at(0);
    data[0] = data->back();
    data->pop_back();
    heapify(0);
    _size--;
    return result;
}

#endif // PRIORITY_QUEUE_HPP