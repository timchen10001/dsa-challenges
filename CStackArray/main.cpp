#include "CStack.h"
#include <iostream>
#include <time.h>

int main() 
{
    int i, val, randNum;
    srand(time(NULL));
    CStack<int> stack;

    randNum = 11;

    std::cout << "Push method" << std::endl;
    for (i = 0; i < randNum; i++)
    {
        val = rand() % 100;
        stack.Push(val);
        stack.Show();
    }

    std::cout << "Pop method" << std::endl;
    for (i = 0; i < randNum; i++)
    {
        stack.Pop(val);
        stack.Show();
    }

    std::cout << "Insert method" << std::endl;
    stack.Insert(2, 40);
    stack.Insert(2, 400);
    stack.Insert(2, 4000);

    stack.Insert(0, 1000);
    stack.Insert(30, 10000);
    stack.Show();


    std::cout << "Remove method" << std::endl;
    for (i = 0; i < 5; i++)
    {
        stack.Remove(100, val);
        stack.Show();
    }

    return 0;
};