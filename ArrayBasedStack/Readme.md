# Implemetetation of Stak using Array List

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

## Class ArrayBasedStack

Class ArrayBasedStack is a class that represents a stack using ArrayList. And has such methods and constructors.

```c++
    ArrayBasedStack();
    ArrayBasedStack(int size);
    void push(const T &element);
    T pop();
    T peek();
    bool isEmpty();
    int size();
    bool isFull();
```

## Class Array List

Class Array List is a implentation of List class that uses array to store and operate the elements. Because of that it is usefull for storing and accessing data.

- ### Constructors:

```C++
ArrayBasedList(); // --- Basic constructor ---
```

> Basic constructor with no arguments, creates empty array list with reseved size of 0.

```C++
ArrayBasedList(int size); // --- Constructor with arguments ---
```

> Constructor with arguments, that creates empty array list with reserved size of given number.

#### Parameters:

size - number of reserved space.

- ### Public methods:

---

```C++
bool isEmpty();
```

> Checks if Stack is empty. Returns true if size of stack is 0, false - if it's bigger.

#### Domintaring operation:

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

> Returns size of array;

---

```C++
void push(cosnt T &element);
```

> Pushes the elements on the top of stack, uses the push_back() method.

---

```C++
T pop();
```

> Pops the element from the top of stack, uses the pop_back() method.

---

```C++
T peek();
```

> Returns a value of the element on the top of stack, without deleting it, uses retrieve() method.

---
