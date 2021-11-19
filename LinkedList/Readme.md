# Implemetetation of List using Linked List

- ### Compiling program:

```bash
$ g++ main.cpp -o main
```

- ### Running program:

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
```

## Class Linked List

Class Linked List is a implentation of List class that uses doubly linked list to store and operate the elements. Because of that it is usefull for manipulating data.

- ### Constructors:

```C++
LinkedList(); // --- Basic constructor ---
```

> Basic constructor with no arguments, creates empty Linked list.

- ### Public methods:

---

```C++
bool isEmpty();
```

> Checks if Linked List is empty. Returns true if size of array is 0, false - if it's bigger.

#### Domintaring operation:

```C++
item_size == 0; //cheking if number of elements is equal to 0.
```

---

```C++
int getLength();
```

> Returns size of Linked List;

---

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
previous = previous->pNext;
```

---

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

---

```C++
T retrive(int index);
```

> Returns element of given index.

#### Parameters:

index - position of element that will be returned.

#### Dominating operation:

> Moving throgth the Linked List.

```C++
    for (int i = 0; i < index; i++)
    {
        current = current->pNext;
    }
```

---

```C++
string toString();
```

> Returns string that contains array. Looks like: [ 1, 2, 3, 4 ]

#### Dominating operation:

> Adding new element to a string.

```C++
//examples of dominating operation
LinkedListStr += to_string(current->data);
LinkedListStr += ", ";
```

---

```C++
int locate(const T &a);
```

> finding a position of a given element.

#### Parameters:

a - element that we need to find.

#### Dominating operations:

> Cheking if given element is equal to some element in Linked List.

```C++
//Example of dominating operation
if (element == current->data)
```

---

```C++
void makeUnique();
```

> Removes elements that are reapeating exept the first one.

#### Dominating operation:

> Checking if element repeats.

```C++
//Example of dominating operation
if (ptr1->data == ptr2->pNext->data)
```

---

```C++
void removeAll(const T& a);
```

> Removes all elements that are repeating.

#### Parameters:

a - element appearances of which will be deleted.

#### Dominating operation:

> Cheking if element repeats

```C++
//Example of dominating operation
if (current->data == a)
```

---

```C++
void revesre();
```

> Reverses elements in Linked list

#### Dominating operation:

> Assignment.

```C++
//Example of dominating operation
temp = current->pNext;
current->pNext = prev;
prev = current;
current = temp;
```

---

```C++
int removeSecondElements();
```

> Removes all second element after the first element

#### Dominating operation:

> Removing elements

```C++
remove(i + 2); // Removing elements using remove() method.
```

---

```C++
int first();
```

> Returns position of the first element.

#### Dominating opration:

> Checking if array isn't empty.

---

```C++
int last();
```

> Returns position of last element in Linked list.

#### Dominating operation:

> Moving through the list.

---

```C++
int front()
```

> Returns value of the firts element in Linked List.

---

```C++
int back()
```

> Returns value of the last element in Linked List.

---

```C++
void push_front(const T &a)
```

> Inserts new element in the begining of the Linked List.

#### Parameters:

a - element that will be inserted in the begining of the Linked List.

---

```C++
void push_back(const T &a);
```

> Inserts new element in the end of the Linked List.

#### Parameters:

a - element that will be inserted in the end of the Linked List.

---

```C++
bool pop_front();
```

> Removes element from the begining of the Linked List;

---

```C++
bool pop_back();
```

> Removes element from the end of the Linked List;

---
