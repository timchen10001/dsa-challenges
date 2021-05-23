#pragma once

template <class T>
class CListNode {
public:
    T m_Value;
    CListNode* m_Next;

    CListNode() : m_Next(NULL) {};
    CListNode(T value) : m_Value(value) {};
    CListNode(CListNode* next) : m_Next(next) {};
    CListNode(T value, CListNode* next) : m_Value(value), m_Next(next) {};

    ~CListNode() {};
};