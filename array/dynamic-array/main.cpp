#include <iostream>
#include <time.h>
#define ArrNum 6
#define InsertNum 3
#include "CBasicArray.h"

int main() 
{
    // i 為迭代index , val 為存pop_back回傳參考值，position為插入位置
    int val;
    unsigned int i, position;
    int arr[ArrNum] = {}; // 暫存亂數用

    // 為產生隨機數，先給予亂數種子
    srand( time(NULL) );

    // 將寫好的Class物件化
    CBasicArray<int> array; 

    // push_back 方法
    std::cout << "\n---push_back method---\n";
    for (i = 0; i < ArrNum; i++)
    {
        val = rand() % 100;
        arr[i] = val;
        if ( array.push_back(val) )
        {
            std::cout << "\n推入: " 
                      << val
                      << std::endl;
            array.show();
        }
    }

    // pop_back 方法
    std::cout << "\n---pop_back method---\n";
    for (i = 0; i < ArrNum; i++)
    {
        if ( array.pop_back(val) ) 
        {
            std::cout << "\n移出: "
                  << val
                  << std::endl;
            array.show();
        }
    }

    // 此時為空的堆疊，將input重新推進去
    std::cout << "\n將上面pop_back值重新推入堆疊中 ...\n";
    for (i = 0; i < ArrNum; i++)
    {
        val = arr[i];
        array.push_back( val );
    }

    // Insert 方法
    std::cout << "\n---Insert method---\n";
    std::cout << "\n目前堆疊狀態\n";
    array.show();
    for (i = 0; i < InsertNum; i++)
    {
        val = rand() % 100; // val 為 0 ~ 99 的隨機數
        position = rand() % 17; // 自訂插入引索值，在 0 ~ 16之間 
        if ( array.insert( position, val ) )
        {
            std::cout << "\n在引索 " 
                      << position
                      << " 插入亂數 "
                      << val
                      << std::endl;
            array.show();
        }
    }

    // Remove 方法
    unsigned int RemoveNum = ArrNum + InsertNum;
    std::cout << "\n---Remove method---\n";
    std::cout << "\n目前堆疊狀態\n";
    array.show();
    for (i = 0; i < RemoveNum; i++)
    {
        position = rand() % (RemoveNum - i);
        if ( array.remove( position, val) )
        {
            std::cout << "\n刪除引索 "
                      << position
                      << " 的 "
                      << val
                      << std::endl;
            array.show();
        }
    }

    return 0;
};