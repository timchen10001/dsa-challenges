#include <iostream>
void InsertionSort(int *arr, int size);
void Show(int *arr, int size);
int main ()
{
    int i;
    int array[11] = {70, 30, 40, 10, 80, 20, 90, 100, 75, 60, 45};
    std::cout << "origin array: " << std::endl;
    Show(array, 11);

    InsertionSort(array, 11);

    std::cout << "\nsorted array: " << std::endl;
    Show(array, 11);

    return 0;
}

void InsertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void Show(int *arr, int size)
{
    int i;
    std::cout << "[ ";
    for (i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size-1) std::cout << ", ";
        else std::cout << " ]";
    }
}