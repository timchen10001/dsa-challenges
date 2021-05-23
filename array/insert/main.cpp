#include <iostream>

void printArr(int arr[], int size);
void printArrMemo(int arr[], int size);
void insertIntoArr(int arr[], int size, int value, int index);

int main(void) {
    int arr[5] = { 1, 2, 4, 5, -1 };

    std::cout << "\n原本 陣列\n";
    printArr(arr, 5);

    // 想要在 arr[2] 中插入 3，需要循序去搬移
    std::cout << "\nInsert 3  into arr[2]\n";
    
    insertIntoArr(arr, 5, 3, 2);

    std::cout << "\n操作後的 陣列\n";
    printArr(arr, 5);
    
};

void insertIntoArr(
    int arr[],
    int size,
    int value,
    int index
) {
    int current, next;
    current = arr[index];

    for (unsigned int i = index+1; i < size; i++) {
        next = arr[i];
        arr[i] = current;
        current = next;
    }
    arr[index] = value;
}

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