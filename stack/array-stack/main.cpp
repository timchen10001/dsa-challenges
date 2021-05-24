#include "CStackArray.h"
#include <iostream>
#include <time.h>
#define ArrNum 6
#define InsertNum 3

int main() 
{
    // i 為迭代index , val 為存Pop回傳參考值，position為插入位置
    int val;
    unsigned int i, position;
    int arr[ArrNum] = {}; // 暫存亂數用

    // 為產生隨機數，先給予亂數種子
    srand( time(NULL) );

    // 將寫好的Class物件化
    CStackArray<int> stack; 

    // Push 方法
    std::cout << "\n---Push method---\n";
    for (i = 0; i < ArrNum; i++)
    {
        val = rand() % 100;
        arr[i] = val;
        if ( stack.push(val) )
        {
            std::cout << "\n推入: " 
                      << val
                      << std::endl;
            stack.show();
        }
    }

    // Pop 方法
    std::cout << "\n---Pop method---\n";
    for (i = 0; i < ArrNum; i++)
    {
        if ( stack.pop(val) ) 
        {
            std::cout << "\n移出: "
                  << val
                  << std::endl;
            stack.show();
        }
    }

    return 0;
};