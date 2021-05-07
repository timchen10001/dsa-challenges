#include <iostream>
#include "CAVL.h"
#include <time.h>

int main()
{
    int i, val;
    srand(time(NULL));
    int random[20] = {6, 66, 48, 86, 20, 19, 62, 92, 72, 33, 81, 50, 32, 69, 73, 0, 59, 35, 3, 60};
    CAVL<int> avl;

    for (i = 0; i < 20; i++)
    {
        if (!avl.Insert(random[i]))
            std::cout << "Inserting:" << random[i] << " failue" << std::endl;
    }

    avl.ShowOrders();

    std::cout << "\nRemove: 62" << std::endl;
    avl.Remove(62);

    avl.ShowOrders();
    return 0;
}