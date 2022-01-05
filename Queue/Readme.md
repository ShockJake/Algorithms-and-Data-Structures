# Implemetetation of Queue using Array List

- ## Compiling program

```bash
g++ main.cpp -o main
```

- ## Running program

### for Linux

```bash
./main
```

### for Windows

```cmd
> main.exe
```

## Class ArrayBasedQueue

Class ArrayBasedStack is a class that represents a stack using ArrayList. And has such methods and constructors.

```c++
    ArrayBasedQueue();
    ArrayBasedQueue(int reserved_size);
    ~ArrayBasedQueue();
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void enqueue(const T &element);
    void dequeue();
    T front();
    T rear();
    string toString();
```

## ArrayBasedQueue

- ### Constructors

```C++
ArrayBasedQueue(); // --- Basic constructor ---
```

> Basic constructor with no arguments, creates empty array based queue with reseved size of 0 (works up to 20 elements).

```C++
ArrayBasedQueue(int size); // --- Constructor with arguments ---
```

> Constructor with arguments, that creates empty array based queue with reserved size of given number (works only with reserved size).

Parameters:

size - number of reserved space.

- ### Public methods of ArrayBasedQueue

---

```C++
bool isEmpty();
```

> Checks if Queue is empty. Returns true if size of stack is 0, false - if it's bigger.

#### Domintaring operation

```C++
real_size == 0; //cheking if number of elements is equal to 0.
```

---

```C++
bool isFull();
```

> Checks if Queue is full. Returns true if size of queue equals the entered size, false if it's less than entered size.

---

```C++
int size();
```

> Returns size of queue;

---

```C++
void enqueue(cosnt T &element);
```

> Enqueues the elements on the back of queue, uses the push_back() method.

---

```C++
T dequeue();
```

> Dequeues the element from the front of queue, uses the pop_front() method.

---

```C++
T rear();
```

> Returns a value of the element on the back of queue, without deleting it, uses retrieve(0) method.

---

```C++
T front();
```

> Returns a value of the element on the front of queue, without deleting it, uses back() method.

---

```C++
string toString();
```

> Returns string which contains representation of queue;

---

## Implemetetation of Queue using Linked List

- ### Compiling

```bash
g++ main.cpp -o main
```

- ### Running

#### Linux

```bash
./main
```

#### Windows

```cmd
> main.exe
```

## Class PointerBasedQueue

Class PointerBasedStack is a class that represents a stack using LinkedList. And has such methods and constructors.

```c++
    PointerBasedQueue();
    PointerBasedQueue(int reserved_size);
    ~PointerBasedQueue();

    bool isEmpty() const;
    int size() const;
    void enqueue(const T &element);
    void dequeue();
    T front();
    T rear();
    string toString();
```

## Class LinkedList

Class Linked List is a implentation of List class that uses doubly linked list to store and operate the elements. Because of that it is usefull for manipulating data.

- ### Constructors of PointerBasedQueue

```C++
PointerBasedQueue(); // --- Basic constructor ---
```

> Basic constructor with no arguments, creates empty pointer based queue with reseved size of 0 (works up to 20 elements).

```C++
PointerBasedQueue(int max_size); // --- Constructor with arguments ---
```

> Constructor with arguments, that creates empty pointer reserved queue with reserved size of given number (Works up to the reserved size.

Parameters:

size - number of reserved space.

- ### Public methods of PointerBasedQueue

---

```C++
bool isEmpty();
```

> Checks if Stack is empty. Returns true if size of stack is 0, false - if it's bigger.

#### Domintaring operations

```C++
item_size == 0; //cheking if number of elements is equal to 0.
```

---

```C++
bool isFull();
```

> Checks if Stack is full. Returns true if size of stack equals the entered size, false if it's less than entered size.

---

```C++
int size();
```

> Returns size of queue;

---

```C++
void enqueue(cosnt T &element);
```

> Enqueues the elements on the back of queue, uses the push_back() method.

---

```C++
T dequeue();
```

> Dequeues the element from the front of queue, uses the pop_front() method.

---

```C++
T rear();
```

> Returns a value of the element on the back of queue, without deleting it, uses retrieve(0) method.

---

```C++
T front();
```

> Returns a value of the element on the front of queue, without deleting it, uses back() method.

---

```C++
string toString();
```

> Returns string which contains representation of queue;

---
