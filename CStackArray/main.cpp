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
        if ( stack.Push(val) )
        {
            std::cout << "\n推入: " 
                      << val
                      << std::endl;
            stack.Show();
        }
    }

    // Pop 方法
    std::cout << "\n---Pop method---\n";
    for (i = 0; i < ArrNum; i++)
    {
        if ( stack.Pop(val) ) 
        {
            std::cout << "\n移出: "
                  << val
                  << std::endl;
            stack.Show();
        }
    }

    // 此時為空的堆疊，將input重新推進去
    std::cout << "\n將上面Pop值重新推入堆疊中 ...\n";
    for (i = 0; i < ArrNum; i++)
    {
        val = arr[i];
        stack.Push( val );
    }

    // Insert 方法
    std::cout << "\n---Insert method---\n";
    std::cout << "\n目前堆疊狀態\n";
    stack.Show();
    for (i = 0; i < InsertNum; i++)
    {
        val = rand() % 100; // val 為 0 ~ 99 的隨機數
        position = rand() % 17; // 自訂插入引索值，在 0 ~ 16之間 
        if ( stack.Insert( position, val ) )
        {
            std::cout << "\n在引索 " 
                      << position
                      << " 插入亂數 "
                      << val
                      << std::endl;
            stack.Show();
        }
    }

    // Remove 方法
    unsigned int RemoveNum = ArrNum + InsertNum;
    std::cout << "\n---Remove method---\n";
    std::cout << "\n目前堆疊狀態\n";
    stack.Show();
    for (i = 0; i < RemoveNum; i++)
    {
        position = rand() % (RemoveNum - i);
        if ( stack.Remove( position, val) )
        {
            std::cout << "\n刪除引索 "
                      << position
                      << " 的 "
                      << val
                      << std::endl;
            stack.Show();
        }
    }

    return 0;
};