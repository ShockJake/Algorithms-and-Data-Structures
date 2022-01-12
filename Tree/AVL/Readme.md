# Implemetetation of AVL Tree

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

## Class AVLTree

Class AVLTree is a class that represents a AVL tree and has such methods and constructors:

```c++
    AVLTree();
    AVLTree(const AVLTree<T> &t);
    ~AVLTree();

    AVLTree<T> &operator=(const AVLTree<T> &t);

    const T &findMin() const;
    const T &findMax() const;
    Node<T> *findMin(Node<T> *t) const;
    Node<T> *findMax(Node<T> *t) const;

    bool contains(const T &data) const;
    bool contains(const T &x, Node<T> *node) const;

    bool isEmpty() const;

    void insert(const T &data);
    void remove(const T &data);

    void clear();

    void printInOrder() const;
    void printPreOrder() const;
    void printPostOrder() const;
    Node<T> *clone(Node<T> *t) const;
```

- ### Constructors

```C++
AVLTree(); // --- Basic constructor ---
```

> Basic constructor with no arguments, creates empty AVL tree.

```C++
AVLTree(const AVLTree<T> &t); // --- Constructor of copying ---
```

> Copies the tree.

#### Parameters

t - other tree, that needs to be copied.

- ### Destructors

```C++
~AVLTree(); // --- Basic destructor ---
```

> Uses clear() method.

- ### Operators

```C++
AVLTree<T> &operator=(const AVLTree &t); // --- = operator ---
```

> Changing all tree elements to elements of enother tree.

- ### Public methods

```C++
const T &findMin() const; // --- Returns value of the smallest element ---
```

Dominating operation:

- walking throught the three;

---

```C++
const T &findMax() const; // --- Returns value of the biggest element ---
```

Dominating operation:

- walking throught the three;

---

```C++
Node<T> *findMin(Node<T> *t) const; // --- Returns pointer of the smallest element ---
```

Dominating operation:

- walking throught the three;

---

```C++
Node<T> *findMax(Node<T> *t) const; // --- Returns pointer of the biggest element ---
```

Dominating operation:

- walking throught the three;

---

```C++
bool contains(const T &data) const; // --- Checks if the element is in the tree ---
```

Dominating operations:

- walking throught the three and checking wheather the element is in the tree;

---

```C++
bool contains(const T &x, Node<T> *node) const; // --- Checks if the element is in the subtree ---
```

Dominating operations:

- walking throught the three and checking wheather the element is in the subtree;

---

```C++
bool isEmpty();
```

> Checks if Tree is empty. Returns true if root is null pointer.

Dominating operation

```C++
this->root == nullptr; //checking if root  is equal to nullptr.
```

---

```C++
void insert(const T &x);
```

> Inserts new element to the tree.

Parameters

x - element that needs to be inserted.

Dominating operation

In diffrent situations:

- bad case:
  > > rotations.
- good case:
  > > comparing values

---

```C++
void remove(const T &x);
```

> Removes element with given value from tree.

Paramters:

x - element that needs to be removed.

Dominating operation

In diffrent situations:

- bad case:
  > > rotations.
- good case:
  > > comparing values

---

```C++
void clear();
```

> Deletes all nodes of the tree;

---

```C++
void printInOrder() const;
```

> Prints all nodes of the tree in in traversal order.

---

```C++
void printPreOrder() const;
```

> Prints all nodes of the tree in pre traversal order.

---

```C++
void printPostOrder() const;
```

> Prints all nodes of the tree in post traversal order.

---

```C++
Node<T> *clone(Node<T> *t) const;
```

> Returns pointer to a cloned tree.

Parameters:
t - staring node.
