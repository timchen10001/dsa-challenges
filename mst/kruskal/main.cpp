#include <iostream>
#include "kruskal.h"
#define rowNum 3
#define columnNum 9
#define I INT_MAX

// Question : find MST


// inputs reference
// 9
// 1 1 2 2 3 4 4 5 5
// 2 6 3 7 4 5 7 6 7
// 25 5 12 10 8 16 14 20 18

void MyUnion(int u, int v);
int find(int u);

int main(void)
{
    int i, j, e;
    std::cout << "\nInput Edges:" << std::endl;
    std::cin >> e;
    int** a = new int* [3];
    for (i=0; i<3; i++) {
        a[i] = new int[e];
        for(j=0; j<e; j++)
            std::cin >> a[i][j];
    };

    CKruskal<int> kruskal(a, 9);
    kruskal.show();

    for(i=0; i<3; i++)
        a[i] = NULL;
    a = NULL;
};
