#ifndef STACK_H_
#define STACK_H_

#include "doubly_linked_list.h"

template <class T>
class Stack {
public:
    Stack() {}

    void clear() {list.clearList();}

    bool isEmpty() {return list.isEmpty();}

    void push(T value) {list.addToTail(value);}

    T pop(void) {return list.deleteFromTail();}

    T topValue(void) {return list.getTail()->getValue();}

    void print(void) const {
        list.print();
    }

    template <class G>
    friend std::ostream& operator<< (std::ostream& out, const Stack<G>& stack) {
        stack.print();
        return out;
    }

private:
    DoublyLinkedList<T> list;
};

#endif