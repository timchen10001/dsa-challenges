#include <iostream>
#include "CDoubleLinkedList.h"

int main(void) {
    CDoubleLinkedList<int> list;

    list.push_back(5);
    list.show();

    list.push_back(10);
    list.show();

    list.push_back(15);
    list.show();

    list.pop_back();
    list.show();

    list.push_front(50);
    list.show();

    list.push_front(20);
    list.show();

    list.pop_front();
    list.show();


    list.insert(1, 100);
    list.show();

    list.insert(2, 50);
    list.show();

    list.remove(2);
    list.show();

    list.remove(0);
    list.show();
};