#include <iostream>
#include <stdlib.h>
#include <vector>
#include "heap.h"
#define gt >
#define lt <

int main(void) 
{
    int a[] = {5, 61, 77, 15, 19 , 59, 11 };
    int b[] = {10, 20 , 30, 25, 5, 40, 35 };
    CHeap<int> heap1(a, sizeof(a)/sizeof(int)+1);
    CHeap<int> heap2(b, sizeof(b)/sizeof(int)+1);

    std::cout << "----- array-A -----" << std::endl;
    heap1.show();

    std::cout << "\n" << "Min Heapping ..." << std::endl;
    heap1.min_heapify();
    heap1.show();

    std::cout << "Sorting ..." << std::endl;
    heap1.sort();
    heap1.show();

    std::cout << "\n" << "Max Heapping ..." << std::endl;
    heap1.max_heapify();
    heap1.show();

    std::cout << "Sorting ..." << std::endl;
    heap1.sort();
    heap1.show();

    std::cout << "\n";

    std::cout << "----- array-B -----" << std::endl;
    heap2.show();

    std::cout << "\n" << "Min Heapping ..." << std::endl;
    heap2.min_heapify();
    heap2.show();

    std::cout << "Sorting ..." << std::endl;
    heap2.sort();
    heap2.show();

    std::cout << "\n" << "Max Heapping ..." << std::endl;
    heap2.max_heapify();
    heap2.show();

    std::cout << "Sorting ..." << std::endl;
    heap2.sort();
    heap2.show();

};
