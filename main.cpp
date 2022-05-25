#include <iostream>
#include <stdbool.h>
// #include "utils.h"
// #include "singly_linked_list.h"
// #include "insert_sort.h"
// #include "merge_sort.h"
#include "doubly_linked_list.h"

int main () {
    DoublyLinkedList list = DoublyLinkedList<int>();
    list.addToTail(10);
    list.addToTail(20);
    list.addToTail(30);
    list.addToTail(40);
    list.addToTail(50);
    DoublyLinkedList newList = DoublyLinkedList<int>();
    newList = list;
    newList.insertNodeBeforeIndex(2, 1000);
    // std::cout << list << std::endl;
    list.print();
    list.deleteFromHead();
    list.deleteFromTail();
    // DoublyLinkedList newList2 {list};
    std::cout << "---" << std::endl;
    std::cout << list << std::endl;
    std::cout << "---" << std::endl;
    std::cout << newList << std::endl;
    // std::cout << "---" << std::endl;
    // std::cout << newList2 << std::endl;

    

    // std::cout << "---" << std::endl;
    // list.deleteFromTail();
    // list.removeNodeWithIndex(2);
    // list.reverse();
    // std::cout << list.isValueInList(100) << std::endl;
    // list.print();


    return 0;
}