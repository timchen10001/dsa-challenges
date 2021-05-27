#include <iostream>
#include "CQueueLinkedList.h"

int main(void) {
    CQueueLinkedList<int> queue;

    queue.push(1);
    queue.show();

    queue.push(2);
    queue.show();

    std::cout << "Peek: " << queue.peek(-1) << "\n";
    
    queue.push(3);
    queue.show();

    queue.pop();
    queue.show();

    queue.push(4);
    queue.show();

    std::cout << "Peek: " << queue.peek(-1) << "\n";

    queue.push(5);
    queue.show();

    queue.pop();
    queue.show();

    std::cout << "Peek: " << queue.peek(-1) << "\n";
    
    queue.pop();
    queue.show();
    std::cout << "Peek: " << queue.peek(-1) << "\n";


    queue.push(6);
    queue.show();
    std::cout << "Peek: " << queue.peek(-1) << "\n";
};