#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "list.h"

template <class T>
class ArrayList : public List<T>
{
private:
    T *items;
    int item_size;
    int reserved_size;
    int capacity;

public:
    ArrayList();
    ArrayList(int size);
    ~ArrayList();

    bool isEmpty() override;
    int getLength() override;
    bool insert(int index, const T &a) override;
    bool remove(int index) override;
    T retrieve(int index) override;
    string toString() override;

    int locate(const T &a);
    int end();
    int first();
    int next(int index);
    int previous(int index);
    int last();
    T back();
    void push_front(const T &a);
    void push_back(const T &a);
    bool pop_front();
    bool pop_back();
    void printArrayList();
    void makeUnique();
    void removeDuplicates();
    void reverse();
};

#include <iostream>
#include "arrayList.h"

using namespace std;

template <class T>
ArrayList<T>::ArrayList() // --- Basic constructor ---
{
    this->item_size = 0;
    this->items = new T[0];
    this->capacity = 0;
    this->reserved_size = 0;
}

template <class T>
ArrayList<T>::ArrayList(int size) // --- Constructor with arguments ---
{
    this->item_size = 0;
    this->items = new T[size];
    this->capacity = size;
    this->reserved_size = size;
}

template <class T>
ArrayList<T>::~ArrayList() // --- Destructor ---
{
    delete[] items;
}

template <class T>
bool ArrayList<T>::isEmpty() // --- Checking if array is empty ---
{
    if (items != nullptr)
    {
        return item_size == 0;
    }
    return false;
}

template <class T>
int ArrayList<T>::getLength() // --- Gette for length of array ---
{
    return item_size;
}

template <class T>
bool ArrayList<T>::insert(int index, const T &a) // --- Element insertion ---
{
    if (index < 0 || index > item_size || items == nullptr) //Checking if index fits limit of array.
    {
        return false;
    }

    if (capacity == 0) //Checking if we need to add new space for a new element.
    {
        reserved_size = item_size + 1;
    }
    else if (item_size == reserved_size) //Checking if number of items equals reserved places.
    {
        reserved_size = item_size + capacity;
    }

    T *newArrayList = new T[reserved_size]; //Creating of a new array.

    for (int i = 0; i < item_size; ++i) //Copying all elements to a new array.
    {
        newArrayList[i] = items[i];
    }

    for (int i = item_size; i > index; --i) //Shifting elements after index to free space for new element.
    {
        newArrayList[i] = newArrayList[i - 1];
    }

    newArrayList[index] = a; //Inserting a new element.
    item_size++;             //Increasing number of elements in array.

    delete[] items;       //Freeing memory.
    items = newArrayList; //"Repointing" to a new array.
    return true;
}

template <class T>
bool ArrayList<T>::remove(int index) // --- Element removing ---
{
    if (index < 0 || index > item_size) //Checking if index fits array limit.
    {
        return false;
    }

    if (capacity == 0) //Prepearing size for a new array.
    {
        reserved_size = item_size - 1;
    }

    for (int i = index; i < item_size; i++) //Removing element from old array.
    {
        items[i] = items[i + 1];
    }

    T *newArray = new T[reserved_size]; //Creating new array.
    item_size--;                        //Decreasing size.
    for (int i = 0; i < item_size; ++i) //Moving elements to a new array that has less size.
    {
        newArray[i] = items[i];
    }

    delete[] items; //"Repointing" our array to a new one.
    items = newArray;

    return true;
}

template <class T>
T ArrayList<T>::retrieve(int index) // --- Retriving element form array ---
{
    if (index >= item_size || index < 0) //Checking if index fits array limit.
    {
        throw std::out_of_range("Index dosen't fit the array limits");
    }
    return items[index];
}

string to_string(string str) {
    return str;
}

template <class T>
string ArrayList<T>::toString() // --- Converting array to string ---
{
    string arrayListStr = "";           //Creating container for elements.
    for (int i = 0; i < item_size; ++i) //Fiiling the container
    {
        arrayListStr += to_string(items[i]);
        if (i != last())
        {
            arrayListStr += ", ";
        }
    }
    return arrayListStr = "[ " + arrayListStr + " ]"; //Adding brackets
}

template <class T>
int ArrayList<T>::locate(const T &a) // --- Locating the element ---
{
    for (int i = 0; i < item_size; ++i) //Finding element in array
    {
        if (a == items[i])
        {
            return i;
        }
    }
    return -1; //returning "-1" if didn't find element
}

template <class T>
int ArrayList<T>::end() // --- Retriving location after last element ---
{
    return item_size;
}

template <class T>
int ArrayList<T>::first() // --- Retriving location of firts element ---
{
    if (item_size == 0)
    {
        return -1;
    }
    return 0;
}

template <class T>
int ArrayList<T>::next(int index) // --- Retriving location of element after given index ---
{
    if (index < 0 || index >= item_size)
    {
        return -1;
    }
    return index + 1;
}

template <class T>
int ArrayList<T>::previous(int index) // --- Retriving location of element before given index ---
{
    if (index <= 0 || index > item_size)
    {
        return -1;
    }
    return index - 1;
}

template <class T>
int ArrayList<T>::last() // --- Retriving location of last element ---
{
    return item_size - 1;
}

template <class T>
T ArrayList<T>::back() // --- Retriving last element ---
{
    return retrieve(item_size - 1);
}

template <class T>
void ArrayList<T>::push_front(const T &a) // --- Adding element on the beging of array ---
{
    insert(0, a);
}

template <class T>
void ArrayList<T>::push_back(const T &a) // --- Adding element on the end of array ---
{
    if (item_size < reserved_size) //Checking if reversed size is bigger then actual item size
    {
        items[item_size] = a;
        item_size++;
    }
    else
    {
        insert(item_size, a);
    }
}

template <class T>
bool ArrayList<T>::pop_front() // --- Removing elemeny from the begining of array ---
{
    return remove(first());
}

template <class T>
bool ArrayList<T>::pop_back() // --- Removing elemeny from the end of array ---
{
    return remove(last());
}

template <class T>
void ArrayList<T>::printArrayList() // --- Printing all elements of array ---
{
    for (int i = 0; i < item_size; ++i)
    {
        cout << items[i] << endl;
    }
}

template <class T>
void ArrayList<T>::makeUnique() // --- Removing all elements that are not unique ---
{
    for (int i = 0; i < item_size; ++i)
    {
        T element = retrieve(i);                 //Taking element.
        for (int j = i + 1; j < item_size; ++j) //Checking if following elements are equal to taken element.
        {
            if (element == items[j])
            {
                remove(j);
                i--;
            }
        }
    }
}

template <class T>
void ArrayList<T>::removeDuplicates() // --- Removing repeating elements ---
{
    int counter = 0;
    for (int i = 0; i < item_size; ++i) //First walk through array to collect information how many times the element meets in array
    {
        T element = retrieve(i);
        for (int j = i; j < item_size; ++j)
        {
            if (element == items[j])
            {
                counter++;
            }
        }
        if (counter > 1)
        {
            for (int j = item_size; j >= 0; j--) //Second walk through array to remove duplicates
            {
                if (element == items[j])
                {
                    remove(j);
                }
            }
        }
        counter = 0;
    }
}

template <class T>
void ArrayList<T>::reverse() // --- Reversing of array ---
{
    if (item_size <= 1) //Checking if number of elements is bigger than 1.
    {
        return;
    }

    T *newArray = new T[item_size];   //Creating new array.
    
    for (int i = last(); i >= 0; i--) //Moving elements to a new array with reverse order.
    {
        newArray[i] = items[item_size - i - 1];
    }

    delete[] items; //"Repointing" arrays.
    items = newArray;
}


#endif //!ARRAYLIST_H
