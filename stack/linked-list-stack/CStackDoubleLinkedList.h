#pragma once
#include <iostream>
#include "../../linked-list/double/CDoubleLinkedList.h"

template <class T>
class CStackDoubleLinkedList {
private:
    CDoubleLinkedList<T> m_List;

public:
    CStackDoubleLinkedList() {};
    ~CStackDoubleLinkedList() {};

    bool push(T value);
    bool pop();
    bool isEmpty();
    T top(T fallback);
    void show();

};

template <class T>
inline void CStackDoubleLinkedList<T>::show() {
    m_List.show();
};

template <class T>
inline bool CStackDoubleLinkedList<T>::push(T value) {
    return m_List.push_back(value);
};

template <class T>
inline bool CStackDoubleLinkedList<T>::pop() {
    return m_List.pop_back();
};

template <class T>
inline bool CStackDoubleLinkedList<T>::isEmpty() {
    return m_List.size() == 0;
};


template <class T>
inline T CStackDoubleLinkedList<T>::top(T fallback) {
    return m_List.search(m_List.size()-1, fallback);
};
