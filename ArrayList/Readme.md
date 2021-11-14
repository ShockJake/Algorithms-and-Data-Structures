# Implemetetation of List using Array List

* ### Compiling program:

```bash
$ g++ main.cpp -o main
```

* ### Running program:

#### for Linux:
```bash
$ ./main
```
#### for Windows:
```bash
> main.exe
```
## Class List
Class List is a interface for implementation, that has public methods for implementing.

```c++
    virtual bool isEmpty() = 0;
    virtual int getLength() = 0;
    virtual bool insert(int index, const T& a) = 0;
    virtual bool remove(int index) = 0;
    virtual T retrive(int index) = 0;
    virtual string toString() = 0;

    virtual int locate(const T& a) = 0;
    virtual int end() = 0;
    virtual int first() = 0;
    virtual int next(int index) = 0;
    virtual int previous(int index) = 0;
    virtual int last() = 0;
    virtual int back() = 0;
    virtual void push_front(const T& a) = 0;
    virtual void push_back(const T& a) = 0;
    virtual bool pop_front() = 0;
    virtual bool pop_back() = 0;
```
## Class Array List

Class Array List is a implentation of List class that uses array to store and operate the elements. Because of that it is usefull for storing and accessing data.

* ### Constructors:

```C++
ArrayList(); // --- Basic constructor ---
```
> Basic constructor with no arguments, creates empty array list with reseved size of 0.

```C++
ArrayList(int size); // --- Constructor with arguments ---
```
> Constructor with arguments, that creates empty array list with reserved size of given number.
#### Parameters:

size - number of reserved space.

* ### Public methods:
___
```C++
bool isEmpty();
```
> Checks if Array List is empty. Returns true if size of array is 0, false - if it's bigger.

#### Domintaring operation:
```C++
item_size == 0; //cheking if number of elements is equal to 0.
```
___

```C++
int getLength();
```
> Returns size of array;
___

```C++
bool insert(int index, const T &a);
```
> Inserts new element on a given position. 

#### Parameters:
index - position of element that will be inserted.  
a - element that will be inserted.
#### Dominating operation:
> Assignment.
```C++
//examples of dominating operation
newArrayList[i] = items[i]; //line 110
newArrayList[i] = newArrayList[i - 1]; //line 115
newArrayList[index] = a; //line 118
items = newArrayList; //line 122
```
___

```C++
bool remove(int index);
```
> Removes element in given position. 

#### Parameters:
index - position of element that will be removed.

#### Dominating operation:
> Assignment.

```C++
//examples of dominating operation
items[i] = items[i + 1]; //line 141
newArray[i] = items[i]; //line 148
```
___

```C++
T retrive(int index);
```
> Returns element of given index.

#### Parameters:
index - position of element that will be returned.

#### Dominating operation:
> Checking.

```C++
    if (index >= item_size || index < 0)
```
___

```C++
string toString();
```
> Returns string that contains array. Looks like: [ 1, 2, 3, 4 ]

#### Dominating operation:
> Adding new element to a string.
```C++
//examples of dominating operation
arrayListStr += to_string(items[i]); //line 173
arrayListStr += ", "; //line 176
```
___

```C++
int locate(const T &a);
```
> finding a position of a given element.
#### Parameters:
a - element that we need to find.
#### Dominating operations:
> Cheking if given element is equal to some element in array list.
```C++
//Example of dominating operation
if (a == items[i])
```
___

```C++
void makeUnique();
```
> Removes elements that are reapeating exept the first one.

#### Dominating operation:
> Checking if element repeats.
```C++
//Example of dominating operation
if (element == items[j])
```
___

```C++
void removeDuplicates();
```
> Removes all elements that are repeating.

#### Dominating operation:
> Cheking if element repeats

```C++
//Example of dominating operation
if (element == items[j]) //line 319
```

___

```C++
void revesre();
```
> Reverses elements in array list

#### Dominating operation:
> Assignment.
```C++
//Example of dominating operation
newArray[i] = items[item_size - i - 1]; //line 341
```

___

```C++
int end();
```
> Returns the position after the last element
___

```C++
int first();
```
> Returns position of the first element.
#### Dominating opration:
> Checking if array isn't empty.

___

```C++
int next(int index);
```
> Returns position of next element after the given, if it is.
#### Parameters:
index - position of element before the next one.
#### Dominating operation:
> Checking if there is a next element.
___

```C++
int previous(int index);
```
> Returns position of previous element, if it is.
#### Parameters:
index - position of element after the previous one.
#### Dominating operation:
> Checking if there is a previous element.
___

```C++
int last()
```
> Returns position of the last element in array.
___

```C++
int back()
```
> Returns value of the last element in array.

___

```C++
void push_front(const T &a)
```
> Inserts new element in the begining of the array.
#### Parameters:
a - element that will be inserted in the begining of the array.
___

```C++
void push_back(const T &a);
```
> Inserts new element in the end of the array.
#### Parameters:
a - element that will be inserted in the end of the array.
___

```C++
bool pop_front();
```
> Removes element from the begining of the array;
___

```C++
bool pop_back();
```
> Removes element from the end of the array;
___
