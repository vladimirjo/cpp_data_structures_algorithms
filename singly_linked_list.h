#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>
#include <exception>

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

        Node<T> *oldTail = tail;
        Node<T> *beforeTail = head;
        while(beforeTail != tail) {
            beforeTail = beforeTail->getNext();
        }

        tail = beforeTail;
        delete oldTail;
        oldTail = beforeTail = nullptr;
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

    // Node *removeNodeWithIndex(int index);
    // SinglyLinkedList& reverse();
    // bool isValueInList(int) const;
    void print(void){
        if(isEmpty()) {
            std::cout << "List is empty" << std::endl;
        } else {
            Node<T> *node = getNodeWithIndex(0);
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

template <class T>
void print_out (SinglyLinkedList<T> list) {

}

#endif