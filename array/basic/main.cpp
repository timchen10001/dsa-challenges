#include <iostream>

void printArr(int arr[], int size);
void printArrMemo(int arr[], int size);

int main(void) {

    int arr[3] = { 1, 2, 3 };
    int size = sizeof(arr)/sizeof(int);

    std::cout << "\n陣列元素\n";
    printArr(arr, size);

    std::cout << "\n陣列記憶體位址\n";
    printArrMemo(arr, size);

    std::cout << "\n陣列指標 arr 會記得第一個起始的記憶體位址\n";
    std::cout << &arr << std::endl;

    std::cout << "\n當你要查詢該陣列 index 為 1 的值時\n";
    std::cout << "電腦可以直接推算出 起始點 + (index * 數值類型的 bytes) 的記憶體位址\n";
    std::cout << &arr[1] << std::endl;
    std::cout << "可以馬上取得存於該記憶體位址的數值 -> O(1)\n";
    std::cout << arr[1] << std::endl;
    std::cout << " (此例子中， int 的基本大小為 4 bytes，會根據不同作業系統和語言有所不同。)\n";
    
};

void printArr(int arr[], int size) {
    std::cout << "[ ";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i != size-1)
            std::cout << ", ";
    };
    std::cout << " ]" << std::endl;
};

void printArrMemo(int arr[], int size) {
    std::cout << "[ ";
    for(int i = 0; i < size; i++) {
        std::cout << &arr[i];
        if (i != size-1)
            std::cout << ", ";
    };
    std::cout << " ]" << std::endl;
};