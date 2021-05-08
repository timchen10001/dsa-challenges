#pragma once
#include <iostream>
#include <vector>
#define l <
#define g >


template <class T>
class CHeap
{
private:
    int m_Size;
    T *m_Array;
    char m_Type;

    void Insert(int n);
    void Delete(int n);

    bool compareFun(T a, T b);
    bool compareFun(T a, T b, char type);
    void swap(T& a, T& b);
    

public:
    CHeap(T A[], int size)
        : m_Size(size)
    {
        int i;
        this->m_Array = new T[m_Size + 1];
        this->m_Array[0] = 0;
        for (i = 0; i < m_Size; i++)
            this->m_Array[i + 1] = A[i];
    };
    ~CHeap()
    {
        delete[] m_Array;
    };
    void max_heapify();
    void min_heapify();
    void show();
    void sort();
};

template <class T>
inline bool CHeap<T>::compareFun(T a, T b, char type)
{
    switch (type) {
        case 'X':
            return a > b;
        case 'M':
            return a < b;
    };
    return a == b;
};
template <class T>
inline bool CHeap<T>::compareFun(T a, T b)
{
    return compareFun(a, b, m_Type);
};

template <class T>
inline void CHeap<T>::swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
};

template <class T>
inline void CHeap<T>::Insert(int n)
{
    int i = n;
    T temp = m_Array[n];

    while( i>1 && compareFun(temp, m_Array[i/2]) )
    {
        m_Array[i] = m_Array[i/2];
        i /= 2;
    };
    m_Array[i] = temp;
};

template <class T>
inline void CHeap<T>::Delete(int n)
{
    // swapping head tail
    swap(m_Array[1], m_Array[n]);

    int i = 1;
    int j = i * 2;
    // reheap
    while( compareFun(j, n-1, 'M') )
    {
        if (m_Array[j+1] > m_Array[j])
            j++;
        if (m_Array[j] > m_Array[i])
            swap(m_Array[j], m_Array[i]);
        else
            break;
    };
};



template <class T>
inline void CHeap<T>::max_heapify()
{
    int i;
    m_Type = 'X';
    for (i = 2; i <= m_Size + 1; i++)
        Insert(i);
};

template <class T>
inline void CHeap<T>::min_heapify()
{
    int i;
    m_Type = 'M';
    for (i = 2; i < m_Size; i++)
        Insert(i);
};

template <class T>
inline void CHeap<T>::show()
{
    int i;
    for (i = 1; i < m_Size; i++)
        std::cout << " " << m_Array[i];
    std::cout << "\n";
};

template <class T>
inline void CHeap<T>::sort()
{
    int i;
    if (m_Type == 'M')
        this->max_heapify();
    for (i = m_Size - 1; i >= 2; i--)
        Delete(i);
};