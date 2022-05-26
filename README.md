# Data Structures and Algorithms in C++

This my implementation of the most used data structures and algorithms.
In this repository you can find following:

## Linked List
  
Flexible list of values that can dynamically grow/shrink. It can be implemented as **Singly Linked List** or **Doubly Linked List**. Difference is in the nodes that holds generic values. Singly Linked List contains nodes that points only to the next node. Doubly Linked List contains nodes that points to both next and previous nodes. Doubly Linked List can remove node from tail in *(O)n*. Also Singly Linked List have method **SinglyLinkedList& reverse(void)** that reverses all nodes in the list while this is not necessary for Doubly Linked List.

  - Properties: 
    - Node<T> *head : pointer to first node
    - Node<T> *tail : pointer to last node
    - int length : number of nodes
  
  - Methods:
    - bool isEmpty(void) : returns true if list is empty
    - void clearList(void) : deletes all the nodes and free theirs memory
    - Node<T> *getHead(void) : returns head
    - Node<T> *getTail(void) : returns tail
    - addToHead(T value) : adds a node with T value to head
    - void addToTail(T value) : adds a node with T value to tail
    - T deleteFromHead() : deletes a node from head and returns its value
    - T deleteFromTail() : deletes a node from tail and returns its value
    - Node<T> *getNodeWithIndex(int index) : return a pointer to a node with given index, throw exception if index is out of range or if list is empty
    - T getValueWithIndex(int index) : return a value of the node with given index
    - void setValueWithIndex(int index, T value) : sets new value to the node with given index
    - bool insertNodeAfterIndex (int index, T value) : inserts a new node with given value after the node with given index, and it handles exception and returns true if insertion succeeds
    - bool insertNodeBeforeIndex (int index, T value) : inserts a new node with given value before the node with given index, and it handles exception and returns true if insertion succeeds
    - T removeNodeWithIndex(int index) : deletes the node with given index and returns its value
    - bool isValueInList(int value) - returns true if a given value is in the list
    - void print(void) - prints all nodes with their indexes and values
  
## Stack
- Queue
- Trees


Sorting algorithms:
