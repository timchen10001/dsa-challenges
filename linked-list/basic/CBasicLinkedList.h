#pragma once
#include <iostream>
#include "CListNode.h"

template <class T>
class CBasicLinkedList {
private:
    CListNode<T>* m_Head;

    unsigned int m_Size;

public:
    CBasicLinkedList()
        : m_Size(0)
    {
        m_Head = new CListNode<T>();
    };
    ~CBasicLinkedList() {
        CListNode<T>* current;
        current = m_Head->m_Next;
        while (current) {
            delete current;
            current = current->m_Next;
        }
        current = NULL;
        delete m_Head;
        m_Head = NULL;
    };

    bool push_back(T value);
    bool pop_back();
    bool push_front(T value);
    bool pop_front();
    void show();
    unsigned int size();

};

template <class T>
inline bool CBasicLinkedList<T>::push_back(T value) {
    CListNode<T>* current = m_Head;

    while(current->m_Next) {
        current = current->m_Next;
    }

    current->m_Next = new CListNode<T>(value);
    if (!current) return false;
    
    m_Size++;
    current = NULL;
    return true;
};

template <class T>
inline bool CBasicLinkedList<T>::pop_back() {
    if (m_Size == 0)
        return false;

    CListNode<T>* current = m_Head;

    while (current->m_Next && current->m_Next->m_Next) {
        current = current->m_Next;
    }

    if (!current->m_Next)
        return false;

    delete current->m_Next;
    current->m_Next = NULL;
    m_Size--;
    return true;
};

template <class T>
inline bool CBasicLinkedList<T>::push_front(T value) {

    if (m_Size == 0) {
        return this->push_back(value);
    };

    CListNode<T>* oldFirst = m_Head->m_Next;
    CListNode<T>* newFirst = new CListNode<T>(value);
    if (!newFirst)
        return false;

    m_Head->m_Next = newFirst;
    newFirst->m_Next = oldFirst;
    m_Size++;
    return true;
};

template <class T>
inline bool CBasicLinkedList<T>::pop_front() {
    if (m_Size == 0)
        return false;

    CListNode<T>* deleteNode = m_Head->m_Next;
    if (!deleteNode)
        return false;

    m_Head->m_Next = deleteNode->m_Next;
    delete deleteNode;
    deleteNode = NULL;
    m_Size--;
    return true;
};

template <class T>
inline void CBasicLinkedList<T>::show() {
    CListNode<T>* current = m_Head->m_Next;

    std::cout << "\n[ ";
    while (current) {
        std::cout << current->m_Value;
        if (current->m_Next) {
            std::cout << ", ";
        }
        current = current->m_Next;
    }
    std::cout << " ]\n";
};

template <class T>
inline unsigned int CBasicLinkedList<T>::size() {
    unsigned int result = m_Size;
    return result;
};