#pragma once
#include <iostream>
#include "CDoubleListNode.h"

template <class T>
class CDoubleLinkedList {
private:
    CDoubleListNode<T>* m_Head;
    CDoubleListNode<T>* m_Tail;

    unsigned int m_Size;

public:
    CDoubleLinkedList() : m_Size(0) {
        m_Head = new CDoubleListNode<T>();
        m_Tail = new CDoubleListNode<T>();
    };

    ~CDoubleLinkedList() {
        CDoubleListNode<T>* current = m_Head->m_Next;
        while (m_Size && current) {
            delete current;
            m_Size--;
            current = current->m_Next;
        }
        delete m_Head;
        delete m_Tail;
        current = NULL;
        m_Head = NULL;
        m_Tail = NULL;
    };

    bool push_back(T value);
    bool pop_back();
    bool push_front(T value);
    bool pop_front();
    bool insert(unsigned int position, T value);
    bool remove(unsigned int position);
    T search(unsigned int position, T fallback);
    void show();
    unsigned int size();
};

template <class T>
inline void CDoubleLinkedList<T>::show() {
    CDoubleListNode<T>* current = m_Head->m_Next;
    unsigned int i = m_Size;

    std::cout << "\n[ ";
    while(i && current) {
        std::cout << current->m_Value;
        current = current->m_Next;

        if (--i > 0) {
            std::cout << ", ";
        }
    }
    std::cout << " ]\n";
};

template <class T>
inline bool CDoubleLinkedList<T>::push_back(T value) {
    CDoubleListNode<T>* insertNode = new CDoubleListNode<T>(value);
    if (!insertNode)
        return false;

    if (m_Size == 0) {
        insertNode->m_Prev = m_Head;
        insertNode->m_Next = m_Tail;
        m_Head->m_Next = insertNode;
        m_Tail->m_Prev = insertNode;
    } else {
        insertNode->m_Prev = m_Tail->m_Prev;
        insertNode->m_Next = m_Tail;
        m_Tail->m_Prev->m_Next = insertNode;
        m_Tail->m_Prev = insertNode;
    }

    m_Size++;
    return true;
};

template <class T>
inline bool CDoubleLinkedList<T>::pop_back() {
    if (m_Size == 0) {
        return true;
    }

    CDoubleListNode<T>* deleteNode = m_Tail->m_Prev;

    if (deleteNode->m_Prev != m_Head) {
        deleteNode->m_Prev->m_Next = m_Tail;
        m_Tail->m_Prev = deleteNode->m_Prev;
    }

    delete deleteNode;
    deleteNode = NULL;
    m_Size--;

    return true;
};

template <class T>
inline bool CDoubleLinkedList<T>::push_front(T value) {
    CDoubleListNode<T>* insertNode = new CDoubleListNode<T>(value);
    if (!insertNode)
        return false;

    if (m_Size == 0) {
        insertNode->m_Prev = m_Head;
        insertNode->m_Next = m_Tail;
        m_Head->m_Next = insertNode;
        m_Tail->m_Prev = insertNode;
    } else {
        insertNode->m_Prev = m_Head;
        insertNode->m_Next = m_Head->m_Next;
        m_Head->m_Next->m_Prev = insertNode;
        m_Head->m_Next = insertNode;
    }

    m_Size++;
    return true;
};

template <class T>
inline bool CDoubleLinkedList<T>::pop_front() {
    if (m_Size == 0) {
        return false;
    }

    CDoubleListNode<T>* deleteNode = m_Head->m_Next;

    if (deleteNode->m_Next != m_Tail) {
        deleteNode->m_Next->m_Prev = m_Head;
        m_Head->m_Next = deleteNode->m_Next;
    }

    delete deleteNode;
    deleteNode = NULL;
    m_Size--;

    return true;
};

template  <class T>
inline bool CDoubleLinkedList<T>::insert(unsigned int position, T value) {

    if (position == 0 || m_Size == 0) {
        return push_front(value);
    }

    if (position >= m_Size-1) {
        return push_back(value);
    }

    CDoubleListNode<T>* current = m_Head;
    for (unsigned int i = 0; i <= position; i++) {
        current = current->m_Next;
    }

    CDoubleListNode<T>* insertNode = new CDoubleListNode<T>(value);
    if (!insertNode)
        return false;
    
    insertNode->m_Prev = current->m_Prev;
    insertNode->m_Next = current;

    current->m_Prev->m_Next = insertNode;
    current->m_Prev = insertNode;
    m_Size++;

    current = NULL;
    return true;
};

template <class T>
inline bool CDoubleLinkedList<T>::remove(unsigned int position) {
    if (m_Size == 0)
        return false;

    if (position == 0) {
        return pop_front();
    }

    if (position >= m_Size-1) {
        return pop_back();
    }

    CDoubleListNode<T>* current = m_Head;
    for (unsigned int i = 0; i <= position; i++) {
        current = current->m_Next;
    }

    CDoubleListNode<T>* deleteNode = current;
    deleteNode->m_Prev->m_Next = deleteNode->m_Next;
    deleteNode->m_Next->m_Prev = deleteNode->m_Prev;

    delete deleteNode;
    deleteNode = NULL;
    current = NULL;
    m_Size--;

    return true;
}

template <class T>
inline unsigned int CDoubleLinkedList<T>::size() {
    unsigned int result = m_Size;
    return result;
};

template <class T>
inline T CDoubleLinkedList<T>::search(unsigned int position, T fallback) {
    if (m_Size != 0) {
        CDoubleListNode<T>* current = m_Head;
        for (unsigned int i = 0; i <= position; i++) {
            current = current->m_Next;
        }
        return current->m_Value;
    }

    return fallback;
};