# Implemetetation of Priority Queue

- ## Compiling program

```bash
$: g++ main.cpp -o main
```

- ## Running program

### for Linux

```bash
$: ./main
```

### for Windows

```cmd
> main.exe
```

## Class Element

Class Element is a class that represents a pair (tuple), here used as
pair of chosen data type (CDT) and integer - (CDT, int).

## Class PriorityQueue

Class PriorityQueue is a class that represents a hash set and has such methods and constructors:

````c++
    // Constructor
    PriorityQueue();
    // Destructor
    ~PriorityQueue();

    // Insertion
    void insertElement(Element<T, int> e);
    // Getting value of the biggest priority
    int getMaxPriority();
    // Getting and removing element of the highest priority
    Element<T, int> pop();
    // Increasing elements priority
    void increasePriority(Element<T, int> e, int priority);
    // Get size
    int getSize();
    // Print priority queue
    std::string toString();
````

- ### Constructors

```C++
PriorityQueue();
```

> Constructor with arguments, creates empty priority queue.

- ### Destructors

```C++
~PriorityQueue();
```

> Frees the allocated memory.

- ### Public methods

```C++
void insertElement(Element<T, int> e);
```

> Inserts element to the queue, calculating priorities of all objects
and setting them in special order.

Parameters:

e - object of Element class that needs to be inserted.

---

```C++
int getMaxPriority();
```

> Getting the highest priority in queue.

---

```C++
Element<T, int> pop();
```

> Dequeueing element with the highest priority from the queue.

---

```C++
void increasePriority(Element<T, int> e, int priority);
```

> Checks if element exists in queue and increases it's priority.

---

```C++
int getSize();
```

> Getting size of queue.

---
