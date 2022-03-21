#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <typeinfo>
#include <cstring>
#include <string>
#include "set.hpp"

using namespace std;

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

    // Inserting element to the set.
    bool insert(const T &x) override;
    // Removing element from the set.
    bool remove(const T &x) override;

    // Checking if element with given value is in the set.
    bool contains(const T &x) override;
    // Returns key for the given value.
    int hash(const T &x) const;

    // Asignment operator
    HashSet &operator=(const HashSet &other);

    // Creating empty table.
    void makeEmpty() override;
    // Print table.
    void printHashSet();
    // Checking if the table is empty
    bool isEmpty() override;

    // Pop all elements that appears in enother hashSet
    void popAll(HashSet<T> &other);

    int size();

    std::string toString();

    std::string printUnion(HashSet<T> &other);
    std::string printIntersection(HashSet<T> &other);
    std::string printDifference(HashSet<T> &other);

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

int newHash(std::string x)
{
   return strlen(x.c_str());
}

int newHash(int x)
{
   return x;
}

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

inline std::string to_string(std::string str)
{
    return str;
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
bool HashSet<T>::isEmpty()
{
    return realSize == 0;
}

template <class T>
void HashSet<T>::clear()
{
    if (!isEmpty())
    {
        for (int i = 0; i < reservedSize; i++)
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
int HashSet<T>::hash(const T &element) const
{
    int x = newHash(element);

    if (x < 0)
    {
        x *= -1;
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
        return false;
    }

    if (realSize == 0)
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
            return false;
        }
    }
}

template <class T>
void HashSet<T>::printHashSet()
{
    if (!isEmpty())
    {
        for (int i = 0; i < reservedSize; i++)
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
HashSet<T> &HashSet<T>::operator=(const HashSet<T> &other)
{
    Node<T> *node = nullptr;
    for (int i = 0; i < other.reservedSize; i++)
    {
        node = other.head[i];
        while (node != nullptr)
        {
            this->insert(node->element);
            node = node->next;
        }
    }
    return *this;
}

template <class T>
bool HashSet<T>::contains(const T &x)
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
        for (int i = 0; i < reservedSize; i++)
        {
            head[i] = nullptr;
        }
    }
}

template <class T>
std::string HashSet<T>::toString()
{
    std::string result = "";
    Node<T> *node = nullptr;
    for (int i = 0; i < reservedSize; i++)
    {
        node = head[i];
        while (node != nullptr)
        {
            result += to_string(node->element) + ' ';
            node = node->next;
        }
    }

    return result;
}

template <class T>
void HashSet<T>::popAll(HashSet<T> &other)
{
    if (!other.isEmpty())
    {
        for (int i = 0; i < other.size(); i++)
        {
            Node<T> *node = other.head[i];
            while (node != nullptr)
            {
                if (this->contains(node->element))
                {
                    this->remove(node->element);
                }
                node = node->next;
            }
        }
    }
}

template <class T>
std::string HashSet<T>::printUnion(HashSet<T> &other)
{
    if (this->isEmpty() && other.isEmpty())
    {
        return HashSet<T>().toString();
    }
    if (this->isEmpty())
    {

        return this->toString();
    }
    if (other.isEmpty())
    {
        return other.toString();
    }

    int lenght = this->size() + other.size();

    HashSet<T> newSet(lenght);

    Node<T> *node = nullptr;

    for (int i = 0; i < this->reservedSize; i++)
    {
        node = this->head[i];
        while (node != nullptr)
        {
            newSet.insert(node->element);
            node = node->next;
        }
    }
    for (int i = 0; i < other.size(); i++)
    {
        node = other.head[i];
        while (node != nullptr)
        {
            if (!newSet.contains(node->element))
            {
                newSet.insert(node->element);
            }
            node = node->next;
        }
    }
    return newSet.toString();
}

template <class T>
std::string HashSet<T>::printIntersection(HashSet<T> &other)
{
    if (this->isEmpty() || other.isEmpty())
    {
        return HashSet<T>().toString();
    }

    HashSet<T> intersection(this->size());
    Node<T> *node = nullptr;

    if (this->size() >= other.size())
    {
        for (int i = 0; i < this->reservedSize; i++)
        {
            node = this->head[i];
            while (node != nullptr)
            {
                if (other.contains(node->element))
                {
                    intersection.insert(node->element);
                }
                node = node->next;
            }
        }
    }
    else
    {
        for (int i = 0; i < other.reservedSize; i++)
        {
            node = other.head[i];
            while (node != nullptr)
            {
                if (this->contains(node->element))
                {
                    intersection.insert(node->element);
                }
                node = node->next;
            }
        }
    }

    return intersection.toString();
}

template <class T>
std::string HashSet<T>::printDifference(HashSet<T> &other)
{
    if (this->isEmpty() || other.isEmpty())
    {
        return HashSet<T>().toString();
    }

    HashSet<T> difference(this->size());
    Node<T> *node = nullptr;

    for (int i = 0; i < this->reservedSize; i++)
    {
        node = this->head[i];
        while (node != nullptr)
        {
            if (!other.contains(node->element))
            {
                difference.insert(node->element);
            }
            node = node->next;
        }
    }
    for (int i = 0; i < other.reservedSize; i++)
    {
        node = other.head[i];
        while (node != nullptr)
        {
            if (!this->contains(node->element))
            {
                difference.insert(node->element);
            }
            node = node->next;
        }
    }
    return difference.toString();
}

#endif // HASHTABLE_HPP