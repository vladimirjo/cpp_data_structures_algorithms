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
    list.print();
    std::cout << std::boolalpha << list.insertNodeBeforeIndex(0, 50) << std::endl;
    list.print();


    return 0;
}