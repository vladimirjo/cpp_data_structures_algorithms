#ifndef SIGNLY_LINKED_LIST
#define SIGNLY_LINKED_LIST

#include <iostream>

template <class T>
class Node {
public:
    Node ()
        : value{0}, next {0} {}
    
    Node (T value)
        : value {value}, next {0} {}

    inline T getValue() const {
        return value;
    }

    inline Node *getNext() const {
        return next;
    }

    inline void setValue(T value) {
        this->value = value;
        return;
    }

    inline void setNext(Node *next) {
        this->next = next;
        return;
    }

private:
    T value;
    Node<T> *next;
};

template <class T>
class SinglyLinkedList {
public:
    SinglyLinkedList ()
    : head {0}, tail {0}, length {0} {}
    
    ~SinglyLinkedList() {
        if (isEmpty()) return;

        Node<T> *node = head;
        while (node != nullptr) {
            if ( node == tail) {
                delete node;
                tail = nullptr;
                head = nullptr;
                length = 0;
                break;
            }

            head = head->getNext();
            delete node;
            node = head;
            length--;
        }
        return;
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

    // T deleteFromHead(T value);
    // T deleteFromTail(T value);
    // Node *getNodeWithIndex(int index);
    // void setNodeWithIndex(int index, T value);
    // bool insertNodeAfterIndex (int index, T value);
    // Node *removeNodeWithIndex(int index);
    // SinglyLinkedList& reverse();
    // bool isValueInList(int) const;
    // void print();

private:
    Node<T> *head;
    Node<T> *tail;
    int length;
};

#endif