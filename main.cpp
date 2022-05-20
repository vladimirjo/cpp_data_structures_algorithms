#include <iostream>
#include <stdbool.h>
// #include "utils.h"
#include "singly_linked_list.h"
// #include "insert_sort.h"
// #include "merge_sort.h"

int main () {
    SinglyLinkedList list = SinglyLinkedList<int>();
    list.addToTail(10);
    list.addToTail(20);
    list.addToTail(30);
    list.addToTail(40);
    list.addToTail(50);
    list.print();
    std::cout << "---" << std::endl;
    // list.deleteFromTail();
    // list.removeNodeWithIndex(2);
    list.reverse();
    list.print();


    return 0;
}