#include <iostream>
#include "CStackDoubleLinkedList.h"

int main (void) {
    CStackDoubleLinkedList<int> stack;

    stack.push(1);
    stack.show();

    stack.push(2);
    stack.show();

    std::cout << "TOP: " << stack.top(-1) << "\n";

    stack.pop();
    stack.show();

    stack.push(3);
    stack.show();

    stack.push(4);
    stack.show();

    stack.push(5);
    stack.show();

    std::cout << "TOP: " << stack.top(-1) << "\n";

    stack.pop();
    stack.show();

    stack.push(6);
    stack.show();

    std::cout << "TOP: " << stack.top(-1) << "\n";
};