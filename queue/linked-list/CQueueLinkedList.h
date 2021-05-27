#pragma once
#include <iostream>
#include "../../linked-list/double/CDoubleLinkedList.h"

template <class T>
class CQueueLinkedList {
private:
    CDoubleLinkedList<T> m_List;

public:
    CQueueLinkedList() {};
    ~CQueueLinkedList() {};

    bool push(T value);
    bool pop();
    T peek(T fallback);
    bool isEmpty();
    void show();
};

template <class T>
inline bool CQueueLinkedList<T>::push(T value) {
  return m_List.push_back(value);
};

template <class T>
inline bool CQueueLinkedList<T>::pop() {
  return m_List.pop_front();
};

template <class T>
inline T CQueueLinkedList<T>::peek(T fallback) {
  return m_List.search(0, fallback);
};

template <class T>
inline bool CQueueLinkedList<T>::isEmpty() {
  return m_List.size() == 0;
};

template <class T>
inline void CQueueLinkedList<T>::show() {
  m_List.show();
};
