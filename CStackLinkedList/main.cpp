#include <iostream>
#include "CStackLinkedList.h"
#include <time.h>
#define ArrNum 6
#define InsertNum 5

int main ()
{
    unsigned int i, position;
    int val;
    int arr[ArrNum] = {};
    srand(time(NULL));
    CStackLinkedList<int> stack;

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



    std::cout << "After Inserting " << 1000 << " in position " << 0 << std::endl;
    stack.Insert(0, 1000);
    stack.Show();

    std::cout << "After Clearing:" << std::endl;
    stack.Clear();
    stack.Show();

    return 0;
}