#pragma once
#include <iostream>
#include <iomanip>

template <class T>
class CStack {
private:
    unsigned int m_StepSize;
    unsigned int m_Number;
    unsigned int m_RealSize;
    T* m_Array;

public:
    CStack();
    ~CStack();
    void Show();
    bool Push(T value);
    bool Pop(T& val);
    bool Insert(unsigned int position, T value);
    bool Remove(unsigned int position, T& val);
};

template <class T>
inline CStack<T>::CStack()
    : m_StepSize(5)
    , m_Number(0)
    , m_RealSize(5)
{
    m_Array = new T[m_RealSize];
}

template <class T>
inline CStack<T>::~CStack()
{
    delete m_Array;
}

template <class T>
inline void CStack<T>::Show()
{
    int i;
    std::cout<< "[ ";
    if (!m_Number) 
    {
        std::cout << " ]\n";
        return;
    };
    for (i = 0; i < m_Number; i++)
    {
        std::cout << m_Array[i];
        if (i != m_Number-1) std::cout << ", ";
        else std::cout << " ]" << std::endl;
    }
}

template <class T>
inline bool CStack<T>::Push(T value)
{
    if (!m_Array) return false;
    if (m_Number == m_RealSize)
    {
        T* array = new T[m_RealSize + m_StepSize];
        if (!array) return false;
        memcpy(array, m_Array, sizeof(T) * m_Number);
        delete m_Array;
        m_Array = array;
        m_Array[m_Number++] = value;
        m_RealSize += m_StepSize;
        std::cout << "陣列空間不足，動態配置大小為 " << m_RealSize << " 之陣列\n";
    }
    else
    {
        m_Array[m_Number++] = value;
    }
    return true;
}

template <class T>
inline bool CStack<T>::Pop(T& val)
{
    if (m_Number == 0) return false;
    val = m_Array[--m_Number];
    return true;
}

template <class T>
inline bool CStack<T>::Insert(unsigned int position, T value)
{
    if (position+1 > m_Number) 
        return Push(value);
    else if (m_Number+1 <= m_RealSize)
    {
        T current = m_Array[position];
        T next;
        unsigned int i;
        for (i = position+1; i < m_Number+1; i++)
        {
            next = m_Array[i];
            m_Array[i] = current;
            current = next;
        }
        m_Array[position] = value;
        m_Number++;
    }
    else
    {
        T* array = new T[m_RealSize + m_StepSize];
        if (!array)
            return false;
        memcpy(array, m_Array, sizeof(T) * m_Number);
        delete m_Array;
        m_Array = array;
        m_RealSize += m_StepSize;
        return Insert(position, value);
    }
    return true;
}

template <class T>
inline bool CStack<T>::Remove(unsigned int position, T& val)
{
    if (!m_Number) return false;
    if (position+1 >= m_Number) return Pop(val);
    val = m_Array[position];
    unsigned int i;
    for (i = position; i < m_Number-1; i++)
    {
        m_Array[i] = m_Array[i+1];
    }
    m_Number--;
    return true;

    
}