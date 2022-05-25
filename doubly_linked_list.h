#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include <iostream>
#include <exception>

/*
 *
 * Node class - it holds a generic value, it has pointer to the next node and a pointer to the previous node
 * Copy constructor, Move constructor and assignment operator is not applicable for this class
 * 
 */
template <class T>
class Node {
public:
    Node () : value{0}, next {nullptr}, previous{nullptr} {}
    
    Node (T value, Node *next = nullptr, Node *previous = nullptr) 
        : value {value}, next {next}, previous{previous} {}

    inline T getValue() const {return value;}

    inline void setValue(T value) {this->value = value;}

    inline Node<T> *getNext() const {return next;}

    inline void setNext(Node *next) {this->next = next;}

    inline Node<T> *getPrevious() const {return previous;}

    inline void setPrevious(Node *previous) {this->previous = previous;}

private:
    T value;
    Node<T> *next;
    Node<T> *previous;
};

/*
 *
 * Doubly Linked List class
 * 
 */
template <class T>
class DoublyLinkedList {
public:
    DoublyLinkedList() : head {0}, tail {0}, length {0} {}

    DoublyLinkedList(const DoublyLinkedList& list);

    DoublyLinkedList<T>& operator=(const DoublyLinkedList& list);
    
    ~DoublyLinkedList() {clearList();}
    
    inline int isEmpty () {return head == nullptr;}

    void clearList(void);

    template <class G>
    friend std::ostream& operator<< (std::ostream& out, const DoublyLinkedList<G>& list);

    inline Node<T> *getHead(void) const {return head;}

    inline Node<T> *getTail(void) const {return tail;}

    void addToHead(T value);

    void addToTail(T value);

    T deleteFromHead();

    T deleteFromTail();

    Node<T> *getNodeWithIndex(int index);

    T getValueWithIndex(int index);

    void setValueWithIndex(int index, T value);

    bool insertNodeAfterIndex (int index, T value);

    bool insertNodeBeforeIndex (int index, T value);

    T removeNodeWithIndex(int index);

    bool isValueInList(int value);

    void print(void);

private:
    Node<T> *head;
    Node<T> *tail;
    int length;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& list): head {0}, tail {0}, length {0} {
    Node<T> *traverseNode = list.getHead();

    while (traverseNode != nullptr) {
        T value = traverseNode->getValue();
        addToTail(value);
        traverseNode = traverseNode->getNext();
    }
}

template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& list) {
    if (this == &list) {
        return *this;
    }
    
    clearList();

    Node<T> *traverseNode = list.getHead();

    while (traverseNode != nullptr) {
        T value = traverseNode->getValue();
        addToTail(value);
        traverseNode = traverseNode->getNext();
    }

    return *this;
}

template <class T>
void DoublyLinkedList<T>::clearList(void) {
        if (isEmpty()) return;

        Node<T> *node = head;

        if (node == tail) {
            delete node;
            tail = nullptr;
            head = nullptr;
            length = 0;
            return;
        }

        while (node != nullptr) {
            head = head->getNext();
            delete node;
            node = head;
            length--;
        }

        tail = nullptr;
        head = nullptr;
        length = 0;
        return;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const DoublyLinkedList<T>& list) {
        if (list.head == nullptr) {
            std::cout << "Doubly Linked list is empty" << std::endl;
            return out;
        }
        Node<T> *node = list.head;
        int index = 0;
        if (list.head == list.tail) {
            std::cout << "[" << index <<"]: \"" << node->getValue() << "\"" << std::endl;
            return out;
        }
        while(node != nullptr) {
            std::cout << "[" << index <<"]: \"" << node->getValue() << "\"" << std::endl;
            node = node->getNext();
            index++;
        }
        return out;
    }

template <class T>
void DoublyLinkedList<T>::addToHead(T value) {
    Node<T> *node = new Node(value);

    if (isEmpty()) {
        head = node;
        tail = node;
        length++;
        return;
    }

    node->setNext(head);
    head->setPrevious(node);
    head = node;
    length++;
}

template <class T>
void DoublyLinkedList<T>::addToTail(T value) {
    if(isEmpty()){
        addToHead(value);
        return;
    }

    Node<T> *node = new Node(value);
    tail->setNext(node);
    node->setPrevious(tail);
    tail = node;
    length++;
    return;
}

template <class T>
T DoublyLinkedList<T>::deleteFromHead() {
    if(isEmpty()){
        throw std::out_of_range("Cannot delete node from an empty list!");
    }

    T value = head->getValue();
    if ( head == tail) {
        delete head;
        tail = nullptr;
        head = nullptr;
        length = 0;
        return value;
    }

    Node<T> *oldHead = head;
    head = head->getNext();
    head->setPrevious(nullptr);

    delete oldHead;
    
    length--;
    return value;
}

template <class T>
T DoublyLinkedList<T>::deleteFromTail() {
    if(isEmpty()){
        throw std::out_of_range("Cannot delete node from an empty list.");
    }

    T value = tail->getValue();

    if (tail == head) {
        delete tail;
        tail = nullptr;
        head = nullptr;
        length = 0;
        return value;
    }

    Node<T> *node = tail;
    tail = tail->getPrevious();
    tail->setNext(nullptr);
    delete node;

    length--;
    return value;
}

template <class T>
Node<T> *DoublyLinkedList<T>::getNodeWithIndex(int index) {
    if(isEmpty()){
        throw std::out_of_range("List is empty.");
    }
    if (index >= length || index < 0) {
        throw std::out_of_range("Index is out of range.");
    }

    Node<T> *node = nullptr;

    if (index <= length/2) {
        node = head;
        int counter = 0;
        while (node != nullptr) {
            if (counter == index) {
                break;
            }
            node = node->getNext();
            counter++;
        }
    } else {
        node = tail;
        int counter = length - 1;
        while (node != nullptr) {
            if (counter == index) {
                break;
            }
            node = node->getPrevious();
            counter--;
        }
    }

    return node;
}

template <class T>
T DoublyLinkedList<T>::getValueWithIndex(int index) {
    Node<T> *node = getNodeWithIndex(index);
    return node->getValue();
}

template <class T>
void DoublyLinkedList<T>::setValueWithIndex(int index, T value) {
    Node<T> *node = getNodeWithIndex(index);
    node->setValue(value);
}

template <class T>
bool DoublyLinkedList<T>::insertNodeAfterIndex (int index, T value) {
    Node<T> *node = nullptr;
    
    try {
        node = getNodeWithIndex(index);
    } catch (...) {
        return false;
    }

    Node<T> *newNode = new Node(value);
    newNode->setNext(node->getNext());
    node->setNext(newNode);
    length++;
    return true;
}

template <class T>
void DoublyLinkedList<T>::print(void) {
    if(isEmpty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node<T> *node = getHead();
    int index = 0;

    while (node != nullptr) {
        std::cout << "[" << index <<"]: \"" << node->getValue() << "\"" << std::endl;
        node = node->getNext();
    }
    
    return;
}

template <class T>
bool DoublyLinkedList<T>::insertNodeBeforeIndex (int index, T value) {
    if (index == 0) {
        addToHead(value);
        return true;
    }

    return insertNodeAfterIndex(index-1, value);
}

template <class T>
T DoublyLinkedList<T>::removeNodeWithIndex(int index) {
    if (index == 0) {
        return deleteFromHead();
    }

    Node<T> *node = getNodeWithIndex(index);
    Node<T> *previous = node->getPrevious();

    if (node == tail) {
        return deleteFromTail();
    }

    T value = node->getValue();
    previous->setNext(node->getNext());
    node->getNext()->setPrevious(previous);
    previous = nullptr;
    delete node;
    length--;

    return value;
}

template <class T>
bool DoublyLinkedList<T>::isValueInList(int value) {
    if (isEmpty()) {
        return false;
    }
    Node<T> *node = head;
    while (node != nullptr) {
        if (node->getValue() == value) {
            return true;
        }
        node = node->getNext();
    }
    return false;
}

#endif