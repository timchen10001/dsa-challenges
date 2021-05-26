#pragma once
#include "../../array/dynamic-array/CBasicArray.h"
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
    T top(T fallback);
    bool push(T value);
    bool pop();
    bool pop(T& val);
    void show();
};

template <class T>
inline unsigned int CStackArray<T>::size() {
    return m_Array.size();
};

template <class T>
inline T CStackArray<T>::top(T fallback) {
    unsigned int size = m_Array.size();

    if (size == 0) {
        return fallback;
    }
    
    return m_Array.find(size-1);
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
inline bool CStackArray<T>::pop() {
    return m_Array.pop_back();
};

template <class T>
inline void CStackArray<T>::show() {
    m_Array.show();
};
