#pragma once
#include "/Users/chenyiting/Codes/dsa-challenges/array/dynamic-array/CBasicArray.h"
#include <iostream>
#include <iomanip>

template <class T>
class CStackArray {
private:
    CBasicArray<T> m_Array;

public:
    bool push(T value);
    bool pop(T& val);
    unsigned int size();
    T top();

};

template <class T>
inline unsigned int CStackArray<T>::size() {
    unsigned int result = this->m_Number;
    return result;
};

template <class T>
inline T CStackArray<T>::top() {
    if (this->m_Number == 0) {
        return NULL;
    }
    
    return this->m_Array[this->m_Number-1];
};

template <class T>
inline bool CStackArray<T>::push(T value) {
    return this->push_back(value);
};

template <class T>
inline bool CStackArray<T>::pop(T& val) {
    return this->pop_back(val);
};
