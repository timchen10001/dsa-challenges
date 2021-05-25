#pragma once
#include "/Users/chenyiting/Codes/dsa-challenges/array/dynamic-array/CBasicArray.h"
#include <iostream>
#include <iomanip>

template <class T>
class CStackArray {
private:
    CBasicArray<T> m_Array;

public:
    CStackArray() {};
    ~CStackArray() {};
    unsigned int size();
    T top();
    bool push(T value);
    bool pop(T& val);
    void show();
};

template <class T>
inline unsigned int CStackArray<T>::size() {
    unsigned int result = m_Array->m_Number;
    return result;
};

template <class T>
inline T CStackArray<T>::top() {
    unsigned int size = m_Array->m_Number;
    if (size == 0) {
        return NULL;
    }
    
    return m_Array[size-1];
};

template <class T>
inline bool CStackArray<T>::push(T value) {
    return m_Array.push_back(value);
};

template <class T>
inline bool CStackArray<T>::pop(T& val) {
    return m_Array.pop_back(val);
};

template <class T>
inline void CStackArray<T>::show() {
    m_Array.show();
};
