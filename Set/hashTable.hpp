#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>

// Maximum size if it's not specified
const int HASH_TABLE_SIZE = 10;

template <class T>
class HashTable
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
    int size;
    // Real number of elements
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
    // Checking if the table is empty
    bool isEmpty() const;

    // Make clone of HashTable
    HashTable &clone();

    // Pop all elements that appears in enother hashTable
    void popAll(const HashTable &other);

    int getSize();
    class EmptyHashTableException : std::exception
    {
        const char *what() const throw()
        {
            return "Hast Table is empty and not operable";
        }
    };

    HashTable makeUnion(HashTable &other);
    HashTable makeIntersection(HashTable &other);
    HashTable makeDifference(HashTable &other);

private:
    // Delete all nodes
    void clear();
};

template <class T>
HashTable<T>::HashTable(int size) // Constructor with arguments
{
    head = new Node<T> *[size];
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        head[i] = nullptr;
    }
}

template <class T>
HashTable<T>::~HashTable() // Destructor
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
int HashTable<T>::getSize()
{
    return this->size;
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
            if (node->element == x)
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

template <class T>
HashTable<T> &HashTable<T>::clone()
{
    HashTable newHash = new HashTable(this.size);

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
void HashTable<T>::popAll(const HashTable &other)
{
    if (!other.isEmpty())
    {
        for (int i = 0; i < other.size(); i++)
        {
            Node<T> node = other.head[i];
            while (node != nullptr)
            {
                if(this.contains(node.element))
                {
                    this->remove(node.element);
                }   
                node = node.next;
            }   
        }
    }
}

template <class T>
HashTable<T> HashTable<T>::makeUnion(HashTable &other)
{
    HashTable<T> newHash = new HashTable<T>(this->real_size + other.real_size);

    for (int i = 0; i < count; i++)
    {
        /* code */
    }
    
}
#endif // HASHTABLE_HPP