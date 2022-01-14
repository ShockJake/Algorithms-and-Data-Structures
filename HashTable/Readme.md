# Implemetetation of Hash Table

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

## Class HashTable

Class HashTable is a class that represents a hash table and has such methods and constructors:

````c++
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
    void printHashTable();```
````

- ### Constructors

```C++
HashTable(int size = HASH_TABLE_SIZE);
```

> Constructor with arguments, creates empty hash table with given size.

Parameters:

size - size of rows, by default equals 10.

- ### Destructors

```C++
~HashTable();
```

> Frees the allocated memory.

Dominating operation:
Walking through the hash table.

- ### Public methods

```C++
bool insert(const T &x);
```

> Calculates the hash of the given element. Inserting element to the table.

Parameters:

x - element that wil be inserted.

Dominating operation:

- walking throught the hash table (pesimistic situation, O(n)).
- creating new element of the hash table (optimistic sitution, O(1)).

---

```C++
bool remove(const T &x);
```

> Calculating hash of the given element.
> Searching if there is an element with this hash,
> checking if this element equals to given element.
> If yes, removing element.

Dominating operation:

- Checking if given element is equal to the element in hash table
  (optimistic sitation O(1), pesimistic situation O(n) - because of walking throungh the list of elements);

---

```C++
bool contains(const T &x) const;
```

> Checks if given element appears in the hash table.

Dominating operation:

- walking throught the hash table(both situations);
  O(1) - best situation.
  O(n) - worst situation(because of walking throught the hash table).

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

> Remove all elements from the hash table.

Dominating operations:

- walking throught the hash table and deleting elements;
  O(1) - best situation.
  O(n) - worst situation(because of walking throught the hash table).

---

```C++
void printHashTable();
```

> Prints hash table.

Dominating operations:

- walking throught the hash table and printing it's elements.
  O(1) - best situation.
  O(n) - worst situation(because of walking throught the hash table).

---
