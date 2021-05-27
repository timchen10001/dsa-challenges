#include <iostream>
#include "CStackDoubleLinkedList.h"

int main (void) {
    CStackDoubleLinkedList<int> stack;

    stack.push(50);
    stack.show();

    stack.push(40);
    stack.show();

    std::cout << "TOP: " << stack.top(-1) << "\n";

    stack.pop();
    stack.show();

    stack.push(4);
    stack.show();

};