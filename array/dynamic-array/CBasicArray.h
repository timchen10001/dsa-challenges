#pragma once
#include <iostream>
#include <iomanip>

template <class T>
class CBasicArray {
private:
    unsigned int m_StepSize;
    unsigned int m_Number;
    unsigned int m_RealSize;
    T* m_Array;

public:
    CBasicArray();
    ~CBasicArray();
    void show();
    bool push_back(T value);
    bool pop_back(T& val);
    
    bool insert(unsigned int position, T value);
    bool remove(unsigned int position, T& val);
};

template <class T>
inline CBasicArray<T>::CBasicArray()
    : m_StepSize(5)
    , m_Number(0)
    , m_RealSize(5)
{
    m_Array = new T[m_RealSize];
}

template <class T>
inline CBasicArray<T>::~CBasicArray()
{
    delete m_Array;
    m_Array = NULL;
}

template <class T>
inline void CBasicArray<T>::show()
{
    std::cout<< "[ ";

    if (!m_Number) {
        std::cout << " ]\n";
        return;
    };

    for (unsigned int i = 0; i < m_Number; i++) {
        std::cout << m_Array[i];

        if (i != m_Number-1)
            std::cout << ", ";
        else
            std::cout << " ]" << std::endl;
    }
}

template <class T>
inline bool CBasicArray<T>::push_back(T value)
{
    if (!m_Array)
        return false;

    if (m_Number == m_RealSize)
    {
        T* array = new T[m_RealSize + m_StepSize];
        if (!array)
            return false;

        memcpy(array, m_Array, sizeof(T) * m_Number);

        delete m_Array;
        m_Array = array;
        m_Array[m_Number++] = value;
        m_RealSize += m_StepSize;

        std::cout << "\n陣列空間不足，動態配置大小為 "
                  << m_RealSize
                  << " 之陣列\n";
    }
    else
    {
        m_Array[m_Number++] = value;
    }
    return true;
}


// 傳參考
template <class T>
inline bool CBasicArray<T>::pop_back(T& val)
{
    if (m_Number == 0)
        return false;

    val = m_Array[--m_Number];

    return true;
}

template <class T>
inline bool CBasicArray<T>::insert(unsigned int position, T value)
{
    // 插入位置 超過實際資料數量，等同Push
    if (position+1 > m_Number)
        return this->push_back(value);
    // 
    else if (m_Number+1 <= m_RealSize)
    {
        // e.g. Insert(1, 10)
        // [ 1, 2, 3, 4, 5 ]
        // -> insert 10 in 1
        // [ 1, 2, 2, 3, 4, 5 ]
        // [ 1, 10, 2, 3, 4, 5 ] 
        // done.

        // 以current, next 分別暫存 當前與下一 位置之數值
        // 先把起點數值存在current
        // 循序將下一位置數值換成當前數值
        // 將起點數值換成input值
        
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

        std::cout << "\n陣列空間不足，動態配置大小為 "
                  << m_RealSize
                  << " 之陣列\n";

        return this->insert(position, value);
    }
    return true;
}

template <class T>
inline bool CBasicArray<T>::remove(unsigned int position, T& val)
{
    if (!m_Number) return false;
    if (position+1 >= m_Number)
        return this->pop_back(val);

    val = m_Array[position];

    for (unsigned int i = position; i < m_Number-1; i++) {
        m_Array[i] = m_Array[i+1];
    }

    m_Number--;
    return true;
}