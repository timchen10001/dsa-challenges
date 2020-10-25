#include <iostream>
#include <vector>
#include <time.h>
#include "CMergeSort.h"
#define arrNum 20

int main (void) {
    srand( time(NULL) );
    int arr[arrNum];
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
        arr[i] = rand() % 100;
    std::vector<int> Array( arr, arr+sizeof(arr)/sizeof(int) );

    MergeSort ms(Array);

    std::cout << "Unsorted Array:\n";
    ms.Show(Array);

    std::cout << "\nSorted Array:\n";
    ms.Show(ms.m_Array);
}