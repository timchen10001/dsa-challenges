#pragma once
#include <iostream>

template <class T>
class CDoubleListNode {
public:
    CDoubleListNode<T>* m_Prev;
    CDoubleListNode<T>* m_Next;
    T m_Value;

    CDoubleListNode() : m_Prev(NULL), m_Next(NULL) {};
    CDoubleListNode(T value) : m_Prev(NULL), m_Next(NULL), m_Value(value) {};
    CDoubleListNode(T value, CDoubleListNode<T>* prev, CDoubleListNode<T>* next) : m_Prev(prev), m_Next(next), m_Value(value) {};
    ~CDoubleListNode() {};
};