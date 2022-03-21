# Implemetetation of Hash Set

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

## Class HashSet

Class HashSet is a class that represents a hash set and has such methods and constructors:

````c++
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

    // Creating empty set.
    void makeEmpty() override;
    // Print set.
    void printHashSet();
    // Checking if the set is empty
    bool isEmpty() override;

    // Pop all elements that appears in enother hashSet
    void popAll(HashSet<T> &other);

    int size();

    std::string toString();

    std::string printUnion(HashSet<T> &other);
    std::string printIntersection(HashSet<T> &other);
    std::string printDifference(HashSet<T> &other);
````

- ### Constructors

```C++
HashSet(int size = HASH_SET_SIZE);
```

> Constructor with arguments, creates empty hash set with given size.

Parameters:

size - size of rows, by default equals 10.

- ### Destructors

```C++
~HashSet();
```

> Frees the allocated memory.

Dominating operation:
Walking through the hash set.

- ### Public methods

```C++
bool insert(const T &x);
```

> Calculates the hash of the given element. Inserting element to the set.

Parameters:

x - element that wil be inserted.

Dominating operation:

- walking throught the hash set (pesimistic situation, O(n)).
- creating new element of the hash set (optimistic sitution, O(1)).

---

```C++
bool remove(const T &x);
```

> Calculating hash of the given element.
> Searching if there is an element with this hash,
> checking if this element equals to given element.
> If yes, removing element.

Dominating operation:

- Checking if given element is equal to the element in hash set
  (optimistic sitation O(1), pesimistic situation O(n) - because of walking throungh the list of elements);

---

```C++
bool contains(const T &x) const;
```

> Checks if given element appears in the hash set.

Dominating operation:

- walking throught the hash set(both situations);
  O(1) - best situation.
  O(n) - worst situation(because of walking throught the hash set).

---

```C++
int hash(const T &x) const;
```

> Calculates hash of the given value.

Dominating operation:

- Calclating hash. O(1).

---

```C++
void makeEmpty();
```

> Remove all elements from the hash set.

Dominating operations:

- walking throught the hash set and deleting elements;
  O(1) - best situation.
  O(n) - worst situation(because of walking throught the hash set).

---

```C++
void printHashSet();
```

> Prints hash set.

Dominating operations:

- walking throught the hash set and printing it's elements.
  O(1) - best situation.
  O(n) - worst situation(because of walking throught the hash set).

---

```C++
    std::string toString();
```

> Prints hash set in a list like style.

Dominating operations:

- walking throught the hash set and printing it's elements.
  O(1) - best situation.
  O(n) - worst situation(because of walking throught the hash set).

---

```C++
    std::string printUnion(HashSet<T> &other);
```

> Prints union of two sets

Dominating operations:

- walking throught the hash sets and printing it's elements.
  O(n) - best situation.
  O(n^2) - worst situation(because of walking throught 2 hash sets).

---

```C++
    std::string printIntersection(HashSet<T> &other);
```

> Prints intersection of two sets

Dominating operations:

- walking throught the hash sets and printing it's elements.
  O(1) - best situation.
  O(n) - worst situation(because of walking throught the hash set).

---

```C++
    std::string printDifference(HashSet<T> &other);
```

> Prints difference of two sets.

Dominating operations:

- walking throught the hash sets and printing it's elements.
  O(1) - best situation.
  O(n) - worst situation(because of walking throught 2 the hash sets).

---

```C++
    void popAll(HashSet<T> &other);
```

> Pops all elements that appears in enother hashSet

Dominating operations:

- walking throught the hash set and popping elements.
  O(1) - best situation.
  O(n) - worst situation(because of walking throught the hash set).

---
