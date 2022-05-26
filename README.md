# Data Structures and Algorithms in C++

This my implementation of the most used data structures and algorithms.
In this repository you can find following:

## Linked List
  
Flexible list of values that can dynamically grow/shrink. It can be implemented as **Singly Linked List** or **Doubly Linked List**. Difference is in the nodes that holds generic values. Singly Linked List contains nodes that points only to the next node. Doubly Linked List contains nodes that points to both next and previous nodes. Doubly Linked List can remove node from tail in *(O)n*. Also Singly Linked List have method **SinglyLinkedList& reverse(void)** that reverses all nodes in the list while this is not necessary for Doubly Linked List.

  - Properties: 
    - Node<T> *head - Pointer to first node.
    - Node<T> *tail - Pointer to last node.
    - int length - Number of nodes.
  
  - Methods:
    - bool isEmpty(void) - Return true if list is empty.
    - void clearList(void) - Delete all the nodes and free theirs memory.
    - Node<T> *getHead(void) - Return head.
    - Node<T> *getTail(void) - Return tail.
    - addToHead(T value) - Add a node with T value to head.
    - void addToTail(T value) - Add a node with T value to tail.
    - T deleteFromHead() - Delete a node from head and returns its value.
    - T deleteFromTail() - Delete a node from tail and returns its value.
    - Node<T> *getNodeWithIndex(int index) - Return a pointer to a node with given index, throw exception if index is out of range or if list is empty.
    - T getValueWithIndex(int index) - Return a value of the node with given index.
    - void setValueWithIndex(int index, T value) - Set a new value to the node with given index.
    - bool insertNodeAfterIndex (int index, T value) - Insert a new node with given value after the node with given index, and it handles exception and returns true if insertion succeeds.
    - bool insertNodeBeforeIndex (int index, T value) - Insert a new node with given value before the node with given index, and it handles exception and returns true if insertion succeeds.
    - T removeNodeWithIndex(int index) - Delete the node with given index and returns its value.
    - bool isValueInList(int value) - Returns true if a given value is in the list.
    - void print(void) - Prints all nodes with their indexes and values.
  
## Stack

A stack is LIFO structure (last in, first out) and is very useful in situations when data have to be stored and then retrieved in reverse order. For the stack implementation I used Doubly Linked List defined in this repository, though one can use vector or list from STD.

    - clear() - Clear the stack.
    - isEmpty() - Check to see if the stack is empty.
    - push(el) - Put the element el on the top of the stack.
    - pop() - Take the topmost element from the stack.
    - topEl() - Return the topmost element in the stack without removing it.

- Queue
- Trees


Sorting algorithms:
