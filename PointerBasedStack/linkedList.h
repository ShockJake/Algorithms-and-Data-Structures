#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "list.h"

template <class T>
class LinkedList : public List<T>
{
private:
    template <class U>
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
    T retrieve(int index) override;
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

    void removeAll(const T &a);
    void makeUnique();
    void reverse();
    void removeSecondElements();

    class EmptyListException : public exception
    {
        const char *what() const throw()
        {
            return "List is empty and not operable\n";
        }
    };

    class BadIndexException : public exception
    {
        const char *what() const throw()
        {
            return "Index does not fit the limits of the list\n-1\n";
        }
    };

private:
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
T LinkedList<T>::retrieve(int index) // --- Returning element in th given index ---
{
    if (index < 0 || index > size) // Cheking if index fits the limits of the list
    {
        throw BadIndexException();
    }

    Node<T> *current = head;        // Creating pointer to the head.
    for (int i = 0; i < index; i++) // Iterating througth the list.
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
bool LinkedList<T>::isEmpty() // --- Checking if the list is empty ---
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
    return remove(size - 1); // Removing last element using method remove();
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
        return head;
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

template <class T>
void LinkedList<T>::removeAll(const T &a) // --- Remove all apearances of given element ---
{
    if (!isEmpty()) // Checking if the list isn't empty.
    {
        Node<T> *current = head;
        for (int i = 0; i < size; i++)
        {
            if (current->data == a)   //
            {                         //
                remove(i);            // Removing.
                i--;                  //
            }                         //
            current = current->pNext; //
        }
    }
    else
    {
        throw EmptyListException();
    }
}

template <class T>
void LinkedList<T>::makeUnique() // --- Remove all not-unique elements ---
{
    if (!isEmpty()) // Checking if the list isn't empty.
    {
        Node<T> *ptr1 = head;    //
        Node<T> *ptr2 = nullptr; // Creating hepling pointers.
        Node<T> *dup = nullptr;  //
        while (ptr1 != nullptr && ptr1->pNext != nullptr)
        {
            ptr2 = ptr1;

            while (ptr2->pNext != nullptr)
            {
                if (ptr1->data == ptr2->pNext->data) // Checking if element is equal to enother element.
                {
                    dup = ptr2->pNext;                //
                    ptr2->pNext = ptr2->pNext->pNext; // Deleting element.
                    size--;                           //
                    delete (dup);                     //
                }
                else
                {
                    ptr2 = ptr2->pNext; // Moving througth the list.
                }
            }
            ptr1 = ptr1->pNext; // Moving througth the list.
        }
    }
    else
    {
        throw EmptyListException();
    }
}

template <class T>
void LinkedList<T>::reverse()
{
    if (!isEmpty()) // Checking if the list isn't empty.
    {
        Node<T> *temp = nullptr; //
        Node<T> *prev = nullptr; // Creating helping pointers.
        Node<T> *current = head; //

        while (current != nullptr) //
        {                          //
            temp = current->pNext; //
            current->pNext = prev; //
            prev = current;        // Reversing list.
            current = temp;        //
        }                          //
        head = prev;               //
    }
    else
    {
        throw EmptyListException();
    }
}

template <class T>
void LinkedList<T>::removeSecondElements() // --- Remove all second element after the first element ---
{
    if (!isEmpty()) // Checking if the list isn't empty.
    {
        if (size > 3)
        {
            Node<T> *current = head;       // Creating pointer to the "head" of the list.
            for (int i = 0; i < size; i++) // Iterating througth the list and removing every 3-rd element.
            {
                remove(i + 2);
            }
            pop_front(); // Removing first element.
        }
        else
        {
            remove(0); // Removing first element even if size of Linked List is less than 3.
        }
    }
    else
    {
        throw EmptyListException();
    }
}

#endif //LINKEDIST_H