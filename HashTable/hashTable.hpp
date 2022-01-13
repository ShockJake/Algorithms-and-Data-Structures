#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>

const int HASH_TABLE_SIZE = 10;

template <class T>
class HashTable
{
private:
    template <class U>
    class Node
    {
    public:
        T element;
        Node *next;

        Node(const T &data)
        {
            element = data;
            next = nullptr;
        }
    };

    Node<T> **head;
    int size;
    int real_size = 0;

public:
    // Constructor with arguments
    HashTable(int size = HASH_TABLE_SIZE);
    // Destructor
    ~HashTable();

    // Inserting element to the table.
    bool insert(const T &x);
    // Removing element from the table.
    bool remove(const T &x);

    // Checking if element with given value is in the table.
    bool contains(const T &x) const;
    // Returns key for the given value.
    int hash(const T &x) const;

    // Creating empty table.
    void makeEmpty();
    // Print table.
    void printHashTable();

    class EmptyHashTableException : std::exception
    {
        const char *what() const throw()
        {
            return "Hast Table is empty and not operable";
        }
    };

private:
    bool isEmpty() const;
    void clear();
};

template <class T>
HashTable<T>::HashTable(int size)
{
    head = new Node<T> *[size];
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        head[i] = nullptr;
    }
}

template <class T>
HashTable<T>::~HashTable()
{
    if (head != nullptr)
    {
        clear();
        delete[] head;
    }
}

template <class T>
bool HashTable<T>::isEmpty() const
{
    return real_size == 0;
}

template <class T>
void HashTable<T>::clear()
{
    if (!isEmpty())
    {
        for (int i = 0; i < size; i++)
        {
            if (head[i] != nullptr)
            {
                real_size--;
                delete[] head[i];
            }
        }
    }
}

template <class T>
int HashTable<T>::hash(const T &x) const
{
    return x % size;
}

template <class T>
bool HashTable<T>::insert(const T &x)
{
    int index = hash(x);
    if (head[index] == nullptr)
    {
        head[index] = new Node<T>(x);
        real_size++;
        return true;
    }
    else
    {
        Node<T> *newNode = head[index];
        while (newNode->next != nullptr)
        {
            newNode = newNode->next;
        }
        newNode->next = new Node<T>(x);
        real_size++;
        return true;
    }
    return false;
}

template <class T>
void HashTable<T>::printHashTable()
{
    if (!isEmpty())
    {
        for (int i = 0; i < size; i++)
        {
            if (head[i] != nullptr)
            {
                std::cout << i << ": ";
                Node<T> *curr = head[i];
                while (curr->next != nullptr)
                {
                    std::cout << curr->element << ", ";
                    curr = curr->next;
                }
                std::cout << curr->element << '\n';
            }
        }
    }
    else
    {
        throw EmptyHashTableException();
    }
}

template <class T>
bool HashTable<T>::contains(const T &x) const
{
    if (!isEmpty())
    {
        int index = hash(x);
        Node<T> *node = head[index];
        if (node != nullptr)
        {
            while (node != nullptr)
            {
                if (node->element == x)
                {
                    return true;
                }
                node = node->next;
            }
        }
        return false;
    }
    else
    {
        throw EmptyHashTableException();
    }
}

template <class T>
bool HashTable<T>::remove(const T &x)
{
    if (!isEmpty())
    {
        int index = hash(x);
        Node<T> *node = head[index];
        if (node != nullptr)
        {
            if(node->element == x)
            {
                Node<T> *toDelete = head[index];
                head[index] = node->next;
                delete toDelete;
                real_size--;
                return true;
            }
            while (node->next != nullptr)
            {
                if (node->next->element == x)
                {
                    Node<T> *toDelete = node->next;
                    node->next = node->next->next;
                    delete toDelete;
                    real_size--;
                    return true;
                }
                node = node->next;
            }
        }
        return false;
    }
    else
    {
        throw EmptyHashTableException();
    }
}

template <class T>
void HashTable<T>::makeEmpty()
{
    if (!isEmpty())
    {
        clear();
        for (int i = 0; i < size; i++)
        {
            head[i] = nullptr;
        }
    }
}

#endif // HASHTABLE_HPP