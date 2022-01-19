#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>

template <class T>
class AVLTree
{
private:
    template <class U>
    class Node
    {
    public:
        T element;
        Node *left;
        Node *right;
        int height;

        Node(T element)
        {
            this->element = element;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 1;
        }
    };

    Node<T> *root;

public:
    // Basic constructor
    AVLTree();
    // Constructor of copying
    AVLTree(const AVLTree &t);
    // Destructor
    ~AVLTree();

    AVLTree &operator=(const AVLTree &t);
    // AVLTree &operator=(AVLTree &&t);

    // Returns the element with the smallest value.
    const T &findMin() const;
    // Returns the element with the biggest value.
    const T &findMax() const;
    // Returns pointer to the element with the smallest value.
    Node<T> *findMin(Node<T> *t) const;
    // Returns pointer to the element with the biggest value.
    Node<T> *findMax(Node<T> *t) const;

    // Checks if the is an element with given value.
    bool contains(const T &x) const;

    // Checks if three contains element with given value.
    bool contains(const T &x, Node<T> *node) const;

    // Checks if the tree is empty.
    bool isEmpty() const;
    // Inserts new element to the tree.
    void insert(const T &x);
    // Removes element with given value from tree.
    void remove(const T &x);
    // void remove(const T &x, Node<T> *&t);

    void printInOrder() const;
    void printPreOrder() const;
    void printPostOrder() const;
    Node<T> *clone(Node<T> *t) const;

    // Deletes all nodes of the tree;
    void clear();

    class EmptyTreeException : std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Tree is empty and not operable";
        }
    };

private:
    int max(int a, int b);
    // Returns height of the node
    int getHeight(const Node<T> *node);
    // Returns balance factor of node
    int getBalance(Node<T> *node);
    // Clears all side nodes with given node.
    void clearFromNode(Node<T> *&node);
    // Copyes all nodes from other tree.
    void copyTree(const Node<T> *node);

    Node<T> *insert(Node<T> *node, const T &x);
    Node<T> *remove(Node<T> *node, const T &x);
    Node<T> *rightRotate(Node<T> *t);
    Node<T> *leftRotate(Node<T> *t);

    void printInOrder(const Node<T> *node) const;
    void printPreOrder(const Node<T> *node) const;
    void printPostOrder(const Node<T> *node) const;
};

template <class T>
AVLTree<T>::AVLTree() // --- Basic constructor ---
{
    this->root = nullptr;
}

template <class T>
AVLTree<T>::AVLTree(const AVLTree<T> &t) // --- Constructor of copying ---
{
    this->root = nullptr;
    *this = t;
}

template <class T>
AVLTree<T>::~AVLTree() // --- Destructor ---
{
    this->clear();
}

template <class T>
AVLTree<T> &AVLTree<T>::operator=(const AVLTree<T> &t)
{
    this->clearFromNode(this->root);
    this->copyTree(t.root);
    return *this;
}

template <class T>
bool AVLTree<T>::isEmpty() const
{
    return this->root == nullptr;
}

template <class T>
void AVLTree<T>::clearFromNode(Node<T> *&node)
{
    if (node != nullptr)
    {
        clearFromNode(node->left);
        clearFromNode(node->right);
        delete node;
    }
    node = nullptr;
}

template <class T>
void AVLTree<T>::clear()
{
    if (!isEmpty())
    {
        clearFromNode(this->root);
    }
    else
    {
        throw EmptyTreeException();
    }
}

template <class T>
AVLTree<T>::Node<T> *AVLTree<T>::findMin(Node<T> *t) const // Returns pointer to the element with the smallest value.
{
    Node<T> *current = t;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

template <class T>
const T &AVLTree<T>::findMin() const // Returns the element with the smallest value.
{
    if (!isEmpty())
    {
        return this->findMin(this->root)->element;
    }
    else
    {
        throw EmptyTreeException();
    }
}

template <class T>
AVLTree<T>::Node<T> *AVLTree<T>::findMax(Node<T> *t) const // Returns pointer to the element with the biggest value.
{
    Node<T> *current = t;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current;
}

template <class T>
const T &AVLTree<T>::findMax() const // Returns the element with the biggest value.
{
    if (!isEmpty())
    {
        return this->findMax(this->root)->element;
    }
    else
    {
        throw EmptyTreeException();
    }
}

template <class T>
int AVLTree<T>::max(int a, int b)
{
    return (a > b) ? a : b;
}

template <class T>
int AVLTree<T>::getHeight(const Node<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

template <class T>
int AVLTree<T>::getBalance(Node<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <class T>
AVLTree<T>::Node<T> *AVLTree<T>::insert(Node<T> *node, const T &x)
{
    if (node == nullptr)
    {
        return new Node<T>(x);
    }
    if (x < node->element)
    {
        node->left = insert(node->left, x);
    }
    else if (x > node->element)
    {
        node->right = insert(node->right, x);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && x < node->left->element)
    {
        return rightRotate(node);
    }
    if (balance > 1 && x > node->left->element)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && x > node->left->element)
    {
        return leftRotate(node);
    }
    if (balance < -1 && x < node->right->element)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

template <class T>
void AVLTree<T>::insert(const T &x)
{
    this->root = insert(this->root, x);
}

template <class T>
AVLTree<T>::Node<T> *AVLTree<T>::remove(Node<T> *node, const T &x)
{
    if (node == nullptr)
    {
        return node;
    }
    if (x < node->element)
    {
        node->left = remove(node->left, x);
    }
    else if (x > node->element)
    {
        node->right = remove(node->right, x);
    }
    else
    {
        if ((node->left == nullptr) || (node->right == nullptr))
        {
            Node<T> *temp = node->left ? node->right : node->right;

            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                *node = *temp;
            }
            free(temp);
        }
        else
        {
            Node<T> *temp = findMin(node->right);
            node->element = temp->element;
            node->right = remove(node->right, temp->element);
        }
    }

    if (node == nullptr)
    {
        return node;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    if (balance > 1 && getBalance(node->left) >= 0)
    {
        return rightRotate(node);
    }
    if (balance > 1 && getBalance(node->left) < 0)
    {
        root->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
    {
        return leftRotate(node);
    }
    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

template <class T>
void AVLTree<T>::remove(const T &x)
{
    if (!isEmpty())
    {
        this->remove(this->root, x);
    }
    else
    {
        throw EmptyTreeException();
    }
}

template <class T>
bool AVLTree<T>::contains(const T &x, Node<T> *node) const
{
    while (node != nullptr)
    {
        if (node->element == x)
        {
            return true;
        }
        if (x < node->element)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return false;
}

template <class T>
bool AVLTree<T>::contains(const T &x) const
{
    if (!isEmpty())
    {
        return contains(x, this->root);
    }
    else
    {
        throw EmptyTreeException();
    }
}

template <class T>
AVLTree<T>::Node<T> *AVLTree<T>::rightRotate(Node<T> *t)
{
    Node<T> *t1 = t->left;
    Node<T> *t2 = t1->right;
    t1->right = t;
    t->left = t2;

    t->height = max(getHeight(t->left), getHeight(t->right));
    t1->height = max(getHeight(t1->left), getHeight(t1->left));
    return t1;
}

template <class T>
AVLTree<T>::Node<T> *AVLTree<T>::leftRotate(Node<T> *t)
{
    Node<T> *t1 = t->right;
    Node<T> *t2 = t1->left;
    t1->left = t;
    t->right = t2;

    t->height = max(getHeight(t->left), getHeight(t->right));
    t1->height = max(getHeight(t1->left), getHeight(t1->right));
    return t1;
}

template <class T>
void AVLTree<T>::printInOrder(const Node<T> *node) const
{
    if (node == nullptr)
    {
        return;
    }
    printInOrder(node->left);
    std::cout << node->element << " ";
    printInOrder(node->right);
}

template <class T>
void AVLTree<T>::printPreOrder(const Node<T> *node) const
{
    if (node == nullptr)
    {
        return;
    }
    std::cout << node->element << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

template <class T>
void AVLTree<T>::printPostOrder(const Node<T> *node) const
{
    if (node == nullptr)
    {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->element << " ";
}

template <class T>
void AVLTree<T>::printInOrder() const
{
    if (!isEmpty())
    {
        printInOrder(this->root);
    }
    else
    {
        throw EmptyTreeException();
    }
}

template <class T>
void AVLTree<T>::printPreOrder() const
{
    if (!isEmpty())
    {
        printPreOrder(this->root);
    }
    else
    {
        throw EmptyTreeException();
    }
}

template <class T>
void AVLTree<T>::printPostOrder() const
{
    if (!isEmpty())
    {
        printPostOrder(this->root);
    }
    else
    {
        throw EmptyTreeException();
    }
}

template <class T>
void AVLTree<T>::copyTree(const Node<T> *node)
{
    if (node != nullptr)
    {
        this->insert(node->element);
        copyTree(node->left);
        copyTree(node->right);
    }
}

template <class T>
AVLTree<T>::Node<T> *AVLTree<T>::clone(Node<T> *t) const
{
    Node<T> newTree;
    newTree = t;
    return newTree;
}

#endif // AVLTREE_HPP