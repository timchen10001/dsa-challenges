#pragma once
#include <iostream>
#define I INT_MAX

template <class T>
class CKruskal {
private:
    T** adj;
    int* set;
    int* included;
    int** time;
    int edges;
    T find(int u);
    void Union(int u, int v);
    void unite();

public:
    CKruskal(T** E, int n) 
        : adj(E)
        , edges(n)
    {
        int i, j;

        // construct adjacent metrix
        for (i=0; i<3; i++)
        {
            adj[i] = E[i];
            for (j=0; j<edges; j++)
                adj[i][j] = E[i][j];
        };  

        // construct disjoined-set
        set = new int[edges-1];
        for (i=0; i<edges-1; i++)
            set[i] = -1;

        // construct included connected-components
        included = new int[edges];
        for (i=0; i<edges; i++)
            included[i] = 0;

        // construct time of component-connecting ...
        time = new int* [2];
        for (i=0; i<2; i++)
            time[i] = new int[edges-2];

    };
    ~CKruskal() 
    {
        int i, j;

        // destruct adj metrix
        for (i=0; i<3; i++)
        {
            delete[] adj[i];
            adj[i] = NULL;
        };
        delete[] adj;
        adj = NULL;

         // destruct disjoined-set
         delete[] set;
         set = NULL;

        // destruct included
        delete[] included;
        included = NULL;
         
        // destruct time
        for(i=0; i<2; i++) {
            delete[] time[i];
            time[i] = NULL;
        };
        delete[] time;
        time = NULL;

    };
    void show();
};

template <class T>
inline void CKruskal<T>::show()
{
    int i, j;

    std:: cout << "\ntesting adj:\n";
    for (i=0; i<3; i++)
    {
        for(j=0; j<edges; j++)
            std::cout << " " << adj[i][j];
        std::cout << "\n";
    };

    std:: cout << "\ntesting set:\n";
    for(i=0; i<edges-1; i++)
        std::cout << " " << set[i]; 

    std:: cout << "\ntesting included:\n";
    for (i=0; i<edges; i++)
        std::cout << " " << included[i];

    std:: cout << "\ntesting time:\n";
    for(i=0; i<2; i++)
    {
        for(j=0; j<edges-2; j++)
            std::cout << " " << time[i][j];
        std::cout << "\n";
    };
        
    std::cout << "\n\nafter unite\n";

    unite();

        std:: cout << "\ntesting adj:\n";
    for (i=0; i<3; i++)
    {
        for(j=0; j<edges; j++)
            std::cout << " " << adj[i][j];
        std::cout << "\n";
    };

    std:: cout << "\ntesting set:\n";
    for(i=0; i<edges-1; i++)
        std::cout << " " << set[i]; 

    std:: cout << "\ntesting included:\n";
    for (i=0; i<edges; i++)
        std::cout << " " << included[i];

    std:: cout << "\ntesting time:\n";
    for(i=0; i<2; i++)
    {
        for(j=0; j<edges-2; j++)
            std::cout << " " << time[i][j];
        std::cout << "\n";
    };

};

template <class T>
inline T CKruskal<T>::find(int u)
{
    int x = u, v = 0;
    while(set[x] > 0)
        x = set[x];
    while(u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    };
    return x;
};

template <class T>
inline void CKruskal<T>::Union(int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] += set[v];
        set[v] = u;
    }
    else 
    {
        set[v] += set[u];
        set[u] = v;
    };
};

template <class T>
inline void CKruskal<T>::unite()
{
    int i, j, k, u, v, min=I, n=7, e=9;
    
    i = 0;
    while(i<n-1)
    {
        min = I;
        
        // find minimum-wieght among possible edges;
        for(j=0; j<e; j++)
        {
            if (included[j] == 0 && adj[2][j]< min) 
            {
                min = adj[2][j];
                u = adj[0][j];
                v = adj[1][j];
                k = j;
            };
        };
        
        if (find(u) != find(v))
        {
            time[0][i] = u;
            time[1][i] = v;
            
            // Union the latest edges
            Union(find(u), find(v));
            i++;
        };
        included[k] = 1;
    };
};

