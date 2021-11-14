#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "list.h"

template <class T>
class LinkedList : public List<T>
{
private:
    template <class T>
    class Node
    {
    public:
        Node *pNext;
        T data;
        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node<T> *head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() override;
    int getLength() override;
    bool insert(int index, const T &a) override;
    bool remove(int index) override;
    T retrive(int index) override;
    string toString() override;

    int locate(const T &element);
    T &operator[](const int index);
    Node<T> *first();
    Node<T> *last();
    T front();
    T back();
    bool push_back(T data);
    bool push_front(T data);
    bool pop_front();
    bool pop_back();
    void clear();
};

template <class T>
LinkedList<T>::LinkedList()
{
    size = 0;
    head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <class T>
int LinkedList<T>::getLength()
{
    return size;
}

template <class T>
bool LinkedList<T>::insert(int index, const T &a)
{
    if (index > size + 1 || index < 0) // Cheking if index fits the limits of the list
    {
        return false;
    }

    if (index == 0) // Cheking if index is 0 to add element in the begining of the list.
    {
        push_front(a); // Using push_front() to add element in the begining of the list.
        size++;        // Incrementing size.
        return true;
    }
    else
    {
        Node<T> *previous = this->head;     // Creating pointer to the element that goes before the element of the given index.
        for (int i = 0; i < index - 1; i++) // Finding element that goes before the element of the given index.
        {
            previous = previous->pNext;
        }
        previous->pNext = new Node<T>(a, previous->pNext); // Creating new element and connecting it to the previous and next element.
        size++;                                            // Incrementing size.
        return true;
    }
}

template <class T>
T LinkedList<T>::retrive(int index)
{
    if (index < 0 || index > size) // Cheking if index fits the limits of the list
    {
        return -1;
    }

    Node<T> *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->pNext;
    }
    return current->data;
}

template <class T>
bool LinkedList<T>::remove(int index) // --- Removing element from the list on the given index ---
{
    if (index < 0 || index > size) // Cheking if index fits the limits of the list
    {
        return false;
    }
    if (index == 0) // Cheking if index is 0 to remove element in the begining of the list.
    {
        pop_front(); // Using pop_front() to remove element in the begining of the list.
        size--;      // Decreasing size.
        return true;
    }
    else
    {
        Node<T> *previous = this->head;     // Creating pointer to the element that goes before the element of the given index.
        for (int i = 0; i < index - 1; i++) // Finding element that goes before the element of the given index.
        {
            previous = previous->pNext;
        }

        Node<T> *toDelete = previous->pNext; // Creating pointer to the element the would be deleted.

        previous->pNext = toDelete->pNext; // Connecting "next" pointer of previous element to the "next" pointer of the next element.

        delete toDelete; // Deleting element that is not in the list.
        size--;          // Decrementing size.
        return true;
    }
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return size == 0;
}

template <class T>
string LinkedList<T>::toString() // --- Converting list to a string ---
{
    string LinkedListStr = "";     // Creating container for elements.
    Node<T> *current = this->head; // Creating pointer to iterate the list.

    while (current->pNext != nullptr) // Moving througth the list and fiiling the container.
    {
        LinkedListStr += to_string(current->data);
        LinkedListStr += ", ";
        current = current->pNext;
    }
    LinkedListStr += to_string(current->data);
    return LinkedListStr = "[" + LinkedListStr + "]"; //Adding brackets
}

template <class T>
bool LinkedList<T>::push_back(T data) // --- Adding new element in the end of the list ---
{
    if (head == nullptr) // Cheking if the list is empty.
    {
        head = new Node<T>(data); // Creating new element.
        size++;                   // Increasing size.
        return true;
    }
    else
    {
        Node<T> *current = this->head; // Creating pointer to move to the end of the list.

        while (current->pNext != nullptr) // Moving througth the list
        {
            current = current->pNext;
        }

        current->pNext = new Node<T>(data); // Adding new element in the end of the list.
    }
    size++; // Increasing size.
    return true;
}

template <class T>
T &LinkedList<T>::operator[](const int index) // --- Overloading "brackets" operator to get easier access to the elements ---
{

    if (index > size + 1 || index < 0) // Cheking if index fits the limits of the list
    {
        return -1;
    }

    int counter = 0; // Seting up a counter.
    Node<T> *current = this->head;
    while (current != nullptr)
    {
        if (counter == index) // Cheking if counter equals to index and returning data of this element.
        {
            return current->data;
        }
        current = current->pNext; // Moving throught the elements.
    }
}

template <class T>
bool LinkedList<T>::push_front(T data) // --- Adding new element in the begining of the list ---
{
    head = new Node<T>(data, head); // Creating new element that would be next element in the list.
    size++;                         // Increasing size.
    return true;
}

template <class T>
bool LinkedList<T>::pop_front() // --- Remove element in the begining of the list ---
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        Node<T> *temp = head; // Creating temporary pointer to the fisrt element of list.
        head = head->pNext;   // Moving head to next element.
        delete temp;          // Deleting "old" first element.
        size--;               // Decreasing size.
        return true;
    }
}

template <class T>
bool LinkedList<T>::pop_back() // --- Remove element in the end of the list ---
{
    remove(size - 1); // Removing last element using method remove();
}

template <class T>
void LinkedList<T>::clear() // --- Delete all data and free memory ---
{
    while (size)
    {
        pop_front(); // Deleating all elements using pop_front() method.
    }
}

template <class T>
int LinkedList<T>::locate(const T &element) // --- Locate element in the list ---
{
    if (isEmpty()) // Checking if the list is empty.
    {
        return -1;
    }
    else
    {
        Node<T> *current = head;       // Creating pointer to head.
        for (int i = 0; i < size; i++) // Moving througth the list.
        {
            if (element == current->data) // Checking if the given element is equal to the element in list.
            {
                return i + 1;
            }
            current = current->pNext;
        }
        return -1;
    }
}

template <class T>
LinkedList<T>::Node<T> *LinkedList<T>::first() // --- Returns pointer to the begining of the list.
{
    if (!isEmpty()) // Checking if the list isn't empty.
    {
        return head->pNext;
    }
    cout << "Funtion first() error" << endl;
    return nullptr;
}

template <class T>
LinkedList<T>::Node<T> *LinkedList<T>::last() // --- Returning pointer to the end of the list ---
{
    if (!isEmpty()) // Checking if the list isn't empty.
    {
        if (size == 1)
        {
            return head;
        }

        if (size == 2)
        {
            return head->pNext;
        }
        else
        {
            Node<T> *current = head;           // Creating a pointer to head.
            for (int i = 0; i < size - 2; i++) // Moving through the list.
            {
                current = current->pNext;
            }
            return current;
        }
    }
    return nullptr;
}

template <class T>
T LinkedList<T>::front() // --- Returning first element ---
{
    if (!isEmpty()) // Checking if the list isn't empty.
    {
        return head->data;
    }
    else
    {
        return -1;
    }
}

template <class T>
T LinkedList<T>::back() // --- Returning the last element ---
{
    if (!isEmpty()) // Checking if the list isn't empty.
    {
        Node<T> *current = head;           // Creating pointer to the head.
        for (int i = 0; i < size - 1; i++) // Moving througth the list.
        {
            current = current->pNext;
        }
        return current->data;
    }
    else
    {
        return -1;
    }
}

#endif //LINKEDIST_H