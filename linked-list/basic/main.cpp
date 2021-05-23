#include <iostream>
#include "CBasicLinkedList.h"

int main(void) {

    CBasicLinkedList<int> list;

    std::cout << "\n[Mutation] push_back 1, 2, 3, 4, 5 至鏈結串列中";
    list.push_back(1);
    list.show();
    list.push_back(2);
    list.show();
    list.push_back(3);
    list.show();
    list.push_back(4);
    list.show();
    list.push_back(5);
    list.show();
    std::cout << "目前鏈結串列的長度： " <<  list.size() << std::endl;

    std::cout << "\n[Mutation] pop back 3次";
    list.pop_back();
    list.show();
    list.pop_back();
    list.show();
    list.pop_back();
    list.show();
    std::cout << "目前鏈結串列的長度： " <<  list.size() << std::endl;

    std::cout << "\n[Mutation] push_front 6, 7, 8 至鏈結串列中";
    list.push_front(6);
    list.show();
    list.push_front(7);
    list.show();
    list.push_front(8);
    list.show();
    std::cout << "目前鏈結串列的長度： " <<  list.size() << std::endl;

    std::cout << "\n[Mutation] pop front 2次";
    list.pop_front();
    list.show();
    list.pop_front();
    list.show();
    std::cout << "目前鏈結串列的長度： " <<  list.size() << std::endl;

};