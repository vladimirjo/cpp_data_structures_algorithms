#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>
#include <exception>

/*
 *
 * Node class - it holds a generic value and it has a pointer to the next node
 * Copy or Move constructor is not applicable
 * 
 */
template <class T>
class Node {
public:
    Node () : value{0}, next {nullptr} {}
    
    Node (T value, Node *next = nullptr) : value {value}, next {next} {}

    inline T getValue() const {return value;}

    inline Node *getNext() const {return next;}

    inline void setValue(T value) {this->value = value;}

    inline void setNext(Node *next) {this->next = next;}

private:
    T value;
    Node<T> *next;
};

/*
 *
 * Singly Linked List class
 * Move constructor is not applicable (cannot make a list with contents as right value)
 * 
 */
template <class T>
class SinglyLinkedList {
public:
    SinglyLinkedList () : head {0}, tail {0}, length {0} {}

    SinglyLinkedList(const SinglyLinkedList& list);

    SinglyLinkedList& operator=(const SinglyLinkedList& list);
    
    ~SinglyLinkedList();
    
    inline bool isEmpty () {return head == nullptr;}

    template <class G>
    friend std::ostream& operator<< (std::ostream& out, const SinglyLinkedList<G>& list);

    void clearList(void);

    inline Node<T> *getHead(void) const {return head;}

    inline Node<T> *getTail(void) {return tail;}

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

    SinglyLinkedList& reverse();

    bool isValueInList(int value);

    void print(void);

private:
    Node<T> *head;
    Node<T> *tail;
    int length;
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& list) : head {0}, tail {0}, length {0} {
    Node<T> *traverseNode = list.getHead();

    while (traverseNode != nullptr) {
        T value = traverseNode->getValue();
        addToTail(value);
        traverseNode = traverseNode->getNext();
    }
}

template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList& list) {
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
SinglyLinkedList<T>::~SinglyLinkedList() {
    clearList();
}

template <class T>
std::ostream& operator<< (std::ostream& out, const SinglyLinkedList<T>& list) {
    if (list.head == nullptr) {
        std::cout << "Linked list is empty" << std::endl;
        return out;
    }
    Node<T> *node = list.head;
    int index = 1;
    if (list.head == list.tail) {
        std::cout << "Index " << index <<": \"" << node->getValue() << "\"" << std::endl;
        return out;
    }
    while(node != nullptr) {
        std::cout << "Index " << index <<": \"" << node->getValue() << "\"" << std::endl;
        node = node->getNext();
        index++;
    }
    return out;
}

template <class T>
void SinglyLinkedList<T>::clearList(void) {
    if (isEmpty()) return;

    if (head == tail) {
        delete head;
        tail = nullptr;
        head = nullptr;
        length = 0;
        return;
    }

    Node<T> *node = head;
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
void SinglyLinkedList<T>::addToHead(T value) {
    Node<T> *node = new Node(value);
    if (head == nullptr) {
        head = node;
        tail = node;
        length++;
        return;
    }
    node->setNext(head);
    head = node;
    length++;
}

template <class T>
void SinglyLinkedList<T>::addToTail(T value) {
    if(isEmpty()){
        addToHead(value);
        return;
    }
    Node<T> *node = new Node(value);
    tail->setNext(node);
    tail = node;
    length++;
    return;
}

template <class T>
T SinglyLinkedList<T>::deleteFromHead() {
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
    delete oldHead;
    oldHead = nullptr;
    length--;
    return value;
}

template <class T>
T SinglyLinkedList<T>::deleteFromTail() {
    if(isEmpty()){
        throw std::out_of_range("Cannot delete node from an empty list.");
    }

    T value = tail->getValue();
    if ( tail == head) {
        delete tail;
        tail = nullptr;
        head = nullptr;
        length = 0;
        return value;
    }

    Node<T> *node = head;
    Node<T> *previous = node;

    while(node != tail) {
        previous = node;
        node = node->getNext();
    }

    tail = previous;
    tail->setNext(nullptr);
    delete node;
    previous = node = nullptr;
    length--;
    
    return value;
}

template <class T>
Node<T> *SinglyLinkedList<T>::getNodeWithIndex(int index) {
    if(isEmpty()){
        throw std::out_of_range("List is empty.");
    }
    if (index >= length || index < 0) {
        throw std::out_of_range("Index is out of range.");
    }

    Node<T> *node = head;
    int counter = 0;
    while (node != nullptr) {
        if (counter == index) {
            break;
        }
        node = node->getNext();
        counter++;
    }
    return node;
}

template <class T>
T SinglyLinkedList<T>::getValueWithIndex(int index){
    Node<T> *node = getNodeWithIndex(index);
    return node->getValue();
}

template <class T>
void SinglyLinkedList<T>::setValueWithIndex(int index, T value){
    Node<T> *node = getNodeWithIndex(index);
    node->setValue(value);
}

template <class T>
bool SinglyLinkedList<T>::insertNodeAfterIndex (int index, T value) {
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
bool SinglyLinkedList<T>::insertNodeBeforeIndex (int index, T value) {
    if (index >= length) {
        return false;
    }
    if (index == 0 || head == tail) {
        addToHead(value);
        return true;
    }
    return insertNodeAfterIndex(index-1, value);
}

template <class T>
T SinglyLinkedList<T>::removeNodeWithIndex(int index) {
    if (index == 0) {
        return deleteFromHead();
    }

    Node<T> *previous = getNodeWithIndex(index-1);
    Node<T> *node = previous->getNext();

    if (node == tail) {
        return deleteFromTail();
    }

    T value = node->getValue();
    previous->setNext(node->getNext());
    previous = nullptr;
    delete node;
    length--;

    return value;
}

template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::reverse() {
    if (isEmpty() || head == tail) {
        return *this;
    }

    Node<T> *node = head;
    head = tail;
    tail = node;

    Node<T> *next = nullptr;
    Node<T> *previous = nullptr;

    while (node != nullptr) {
        next = node->getNext();
        node->setNext(previous);
        previous = node;
        node = next;
    }

    return *this;
}

template <class T>
bool SinglyLinkedList<T>::isValueInList(int value) {
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

template <class T>
void SinglyLinkedList<T>::print(void){
    if(isEmpty()) {
        std::cout << "List is empty" << std::endl;
    } else {
        Node<T> *node = getHead();
        while (node != nullptr) {
            std::cout << node->getValue() << std::endl;
            node = node->getNext();
        }
    }
}

#endif