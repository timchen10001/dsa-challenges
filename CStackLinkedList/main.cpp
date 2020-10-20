#include <iostream>
#include "CStackLL.h"
#include <time.h>

int main ()
{
    int i, val;
    srand(time(NULL));
    CStackLL<int> stack;

    for (i = 0; i < 20; i++)
    {
        val = rand() % 100;
        stack.Push(val);
        stack.Show();
    }

    for (i = 0; i < 10; i++)
    {
        stack.Pop(val);
        stack.Show();
    }

    stack.Remove(4);
    stack.Show();

    std::cout << "After Inserting " << 1000 << " in position " << 0 << std::endl;
    stack.Insert(0, 1000);
    stack.Show();

    std::cout << "After Clearing:" << std::endl;
    stack.Clear();
    stack.Show();

    return 0;
}