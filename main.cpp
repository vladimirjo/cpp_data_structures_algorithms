#include <iostream>
#include <stdbool.h>
#include "stack.h"

int main () {
    Stack list = Stack<int>();
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    list.push(50);

    std::cout << list << std::endl;
    std::cout << "---" << std::endl;

    list.pop();
    list.pop();
    std::cout << list << std::endl;
    std::cout << "---" << std::endl;

    std::cout << list.topValue() << std::endl;

    return 0;
}