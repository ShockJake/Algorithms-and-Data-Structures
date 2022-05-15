#pragma once
#include <iostream>

class Element
{
private:
    std::pair<std::string, int> data;

public:
    Element()
    {
    }

    Element(std::string val, int priority)
    {
        data.first = val;
        data.second = priority;
    }

    std::string getValue() { return data.first; }
    int getPriority() { return data.second; }
};

class PriorityQueue
{
private:
    Element *arr = nullptr;
    unsigned int maxSize;
    unsigned int size;
    unsigned int largest;

    unsigned int left(unsigned int i) { return i * 2; }
    unsigned int right(unsigned int i) { return i * 2 + 1; }
    unsigned int parent(unsigned int i) { return i / 2; }

    void swap(unsigned int i, unsigned int j);
    void buildMaxHeap(unsigned int &heapSize);
    void maxHeapify(unsigned int &heapSize, unsigned int i);
    void maxHeapInsert(unsigned int &heapSize, Element el);
    void heapIncreaseKey(unsigned int i, Element el);
    void removeFirst();

public:
    PriorityQueue(unsigned int size);
    ~PriorityQueue();
    void InsertElement(Element e);
    bool isEmpty();
    Element pop();
};

PriorityQueue::PriorityQueue(unsigned int size)
{
    this->size = 0;
    maxSize = size;
    arr = new Element[size];
}

PriorityQueue::~PriorityQueue()
{
    if (arr != nullptr)
    {
        delete[] arr;
    }
}

Element PriorityQueue::pop()
{
    Element element = arr[0];
    removeFirst();
    return element;
}

bool PriorityQueue::isEmpty()
{
    return size == 0;
}

void PriorityQueue::InsertElement(Element element)
{
    maxHeapInsert(size, element);
}

void PriorityQueue::swap(unsigned int i, unsigned int j)
{
    Element tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
}

void PriorityQueue::buildMaxHeap(unsigned int &heapSize)
{
    for (int i = heapSize / 2; i >= 0; i--)
    {
        maxHeapify(heapSize, i);
    }
}

void PriorityQueue::maxHeapify(unsigned int &heapSize, unsigned int i)
{
    unsigned int l = left(i);
    unsigned int r = right(i);
    if ((l < heapSize) && (arr[l].getPriority() > arr[i].getPriority()))
        largest = l;
    else
        largest = i;
    if ((r < heapSize) && (arr[r].getPriority() > arr[largest].getPriority()))
        largest = r;
    if (largest != i)
    {
        swap(i, largest);
        maxHeapify(heapSize, largest);
    }
}

void PriorityQueue::maxHeapInsert(unsigned int &heapSize, Element el)
{
    arr[heapSize] = el;
    heapIncreaseKey(heapSize, el);
    heapSize++;
}

void PriorityQueue::heapIncreaseKey(unsigned int i, Element el)
{
    if (el.getPriority() < arr[i].getPriority())
        throw std::runtime_error("New key is smaller than current key");
    arr[i] = el;
    while ((i > 0) && arr[parent(i)].getPriority() < arr[i].getPriority())
    {
        swap(i, parent(i));
        i = parent(i);
    }
}

void PriorityQueue::removeFirst()
{
    arr[0] = arr[size - 1];
    size--;
    buildMaxHeap(size);
}