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

    SinglyLinkedList(const SinglyLinkedList& list) : head {0}, tail {0}, length {0} {
        Node<T> *traverseNode = list.getHead();

        while (traverseNode != nullptr) {
            T value = traverseNode->getValue();
            addToTail(value);
            traverseNode = traverseNode->getNext();
        }
    }

    SinglyLinkedList& operator=(const SinglyLinkedList& list) {
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
    
    ~SinglyLinkedList() {
        clearList();
    }
    
    inline int isEmpty () {
        return head == nullptr;
    }

    friend std::ostream& operator<< (std::ostream& out, const SinglyLinkedList& list) {
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

    void clearList(void) {
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

    Node<T> *getHead(void) const {
        return head;
    }

    Node<T> *getTail(void) {
        return tail;
    }

    void addToHead(T value) {
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

    void addToTail(T value) {
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

    T deleteFromHead() {
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

    T deleteFromTail() {
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

    Node<T> *getNodeWithIndex(int index) {
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

    T getValueWithIndex(int index){
        Node<T> *node = getNodeWithIndex(index);
        return node->getValue();
    }

    void setValueWithIndex(int index, T value){
        Node<T> *node = getNodeWithIndex(index);
        node->setValue(value);
    }

    bool insertNodeAfterIndex (int index, T value) {
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

    bool insertNodeBeforeIndex (int index, T value) {
        if (index >= length) {
            return false;
        }
        if (index == 0 || head == tail) {
            addToHead(value);
            return true;
        }
        return insertNodeAfterIndex(index-1, value);
    }

    T removeNodeWithIndex(int index) {
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

    SinglyLinkedList& reverse() {
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

    bool isValueInList(int value) {
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

    void print(void){
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

private:
    Node<T> *head;
    Node<T> *tail;
    int length;
};

#endif