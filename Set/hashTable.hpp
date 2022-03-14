#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <typeinfo>
#include "set.hpp"
// Maximum size if it's not specified
const int HASH_SET_SIZE = 10;

template <class T>
class HashSet : public Set<T>
{
private:
    // Inner class for containing data
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

    // Pointer to a pointers of different hash keys
    Node<T> **head;
    // Given size
    int reservedSize;
    // Real number of elements
    int realSize = 0;

public:
    // Constructor with arguments
    HashSet(int size = HASH_SET_SIZE);
    // Destructor
    ~HashSet();

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
    // Checking if the table is empty
    bool isEmpty() const;

    // Make clone of HashTable
    HashSet &clone();

    // Pop all elements that appears in enother hashTable
    void popAll(const HashSet &other);

    int size();

    HashSet makeUnion(HashSet &other);
    HashSet makeIntersection(HashSet &other);
    HashSet makeDifference(HashSet &other);

    // Exception for already existing element
    class ExistingElementException : std::exception
    {
        const char *what() const throw()
        {
            return "Element already exists";
        }
    };

    // Exception for empty Set
    class EmptySetException : std::exception
    {
        const char *what() const throw()
        {
            return "Set is empty and not operable";
        }
    };

private:
    // Delete all nodes
    void clear();
};

template <class T>
HashSet<T>::HashSet(int size) // Constructor with arguments
{
    head = new Node<T> *[size];
    this->reservedSize = size;
    for (int i = 0; i < size; i++)
    {
        head[i] = nullptr;
    }
}

template <class T>
HashSet<T>::~HashSet() // Destructor
{
    if (head != nullptr)
    {
        clear();
        delete[] head;
    }
}

template <class T>
bool HashSet<T>::isEmpty() const
{
    return realSize == 0;
}

template <class T>
void HashSet<T>::clear()
{
    if (!isEmpty())
    {
        for (int i = 0; i < size; i++)
        {
            if (head[i] != nullptr)
            {
                realSize--;
                delete[] head[i];
            }
        }
    }
}

template <class T>
int HashSet<T>::hash(const T &x) const
{
    if (typeid(T) == typeid(std::string))
    {
        return std::strlen(x) % reservedSize;
    }
    return x % reservedSize;
}

template <class T>
int HashSet<T>::size()
{
    return this->reservedSize;
}

template <class T>
bool HashSet<T>::insert(const T &x)
{
    if (realSize == reservedSize)
    {
        Node<T> *newHead = Node<T> *[this->reservedSize];
        for (int i = 0; i < reservedSize; i++)
        {
            newHead[i] = this->head[i];
        }
        delete this->head;
        this->head = newHead;
        this->reservedSize += 2; 
    }

    if (!contains(x))
    {
        int index = hash(x);
        if (head[index] == nullptr)
        {
            head[index] = new Node<T>(x);
            realSize++;
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
            realSize++;
            return true;
        }
    }
    else
    {
        throw ExistingElementException();
    }
}

template <class T>
void HashSet<T>::printHashTable()
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
        throw EmptySetException();
    }
}

template <class T>
bool HashSet<T>::contains(const T &x) const
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
        throw EmptySetException();
    }
}

template <class T>
bool HashSet<T>::remove(const T &x)
{
    if (!isEmpty())
    {
        int index = hash(x);
        Node<T> *node = head[index];
        if (node != nullptr)
        {
            if (node->element == x)
            {
                Node<T> *toDelete = head[index];
                head[index] = node->next;
                delete toDelete;
                realSize--;
                return true;
            }
            while (node->next != nullptr)
            {
                if (node->next->element == x)
                {
                    Node<T> *toDelete = node->next;
                    node->next = node->next->next;
                    delete toDelete;
                    realSize--;
                    return true;
                }
                node = node->next;
            }
        }
        return false;
    }
    else
    {
        throw EmptySetException();
    }
}

template <class T>
void HashSet<T>::makeEmpty()
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

template <class T>
HashSet<T> &HashSet<T>::clone()
{
    HashSet newHash = new HashSet(this.size);

    for (int i = 0; i < size; i++)
    {
        for (Node<T> node : head[i])
        {
            newHash.insert(node.element);
        }
    }
    return &newHash;
}

template <class T>
void HashSet<T>::popAll(const HashSet &other)
{
    if (!other.isEmpty())
    {
        for (int i = 0; i < other.size(); i++)
        {
            Node<T> node = other.head[i];
            while (node != nullptr)
            {
                if (this.contains(node.element))
                {
                    this->remove(node.element);
                }
                node = node.next;
            }
        }
    }
}

template <class T>
HashSet<T> HashSet<T>::makeUnion(HashSet &other)
{
    if (this->isEmpty() && other.isEmpty())
    {
        return HashSet<T>();
    }
    if (this->isEmpty())
    {
        return other.clone();
    }
    if (other.isEmpty())
    {
        return this->clone();
    }

    int lenght = this->size() + other.size();

    HashSet<T> newSet = new HashSet<T>(lenght);

    Node<T> node = nullptr;

    for (int i = 0; i < this->size(); i++)
    {
        node = this->head[i];
        while (node != nullptr)
        {
            newSet.insert(node.element);
            node = node.next;
        }
    }
    for (int i = 0; i < other.size(); i++)
    {
        node = other.head[i];
        while (node != nullptr)
        {
            newSet.insert(node.element);
            node = node.next;
        }
    }

    return newSet;
}

#endif // HASHTABLE_HPP