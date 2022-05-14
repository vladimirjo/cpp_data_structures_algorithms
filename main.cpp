#include <iostream>
#include "singly_linked_list.h"

int main () {
    // Node<int> node1 = Node<int> (10);
    // Node<int> node2 = Node<int> (20);
    // node1.setNext(&node2);

    {
        SinglyLinkedList<int> list = SinglyLinkedList<int>();
        list.addToTail(10);
        list.addToTail(20);
        std::cout << list.deleteFromHead() << std::endl;
        std::cout << list.deleteFromHead() << std::endl;
    }

    // std::cout << list;

    return 0;
}