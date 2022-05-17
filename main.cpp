#include <iostream>
// #include "singly_linked_list.h"
#include "insert_sort.h"

int main () {
    int array[] = {5, 2, 4, 6, 1, 3};
    int length = sizeof(array) / sizeof(array[0]);

    printArray(array, length);
    insertSort(array, length);
    printArray(array, length); 

    return 0;
}