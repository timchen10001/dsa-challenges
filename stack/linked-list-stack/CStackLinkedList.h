#pragma once
#include <iostream>

template <class T>
class CListNode
{
public:
    CListNode<T> *m_Next;
    T m_Value;

    CListNode() : m_Next(NULL), m_Value(){};
    ~CListNode(){};
};

template <class T>
class CStackLinkedList
{
private:
    CListNode<T> *m_First;
    CListNode<T> *m_Tail;
    unsigned int m_Number;

public:
    CStackLinkedList();
    ~CStackLinkedList();
    void Show();
    bool Push(T value);
    bool Pop(T &val);
    bool Insert(unsigned int position, T value);
    bool Remove(unsigned int position, T& value);
    void Clear();
    void ShowNumber();
};

template <class T>
inline CStackLinkedList<T>::CStackLinkedList()
    : m_Number(0)
{
    m_First = new CListNode<T>;
}

template <class T>
inline CStackLinkedList<T>::~CStackLinkedList()
{
    CListNode<T>* current = m_First;
    while (current->m_Next)
    {
        delete current;
        current = current->m_Next;
    }
}

template <class T>
inline void CStackLinkedList<T>::Show()
{
    unsigned int i;
    CListNode<T>* current = m_First;
    std::cout << "[ ";
    for (i = 0; i < m_Number; i++)
    {
        std::cout << current->m_Value;
        if (current->m_Next)
            std::cout << ", ";
        current = current->m_Next;
    }
    std::cout << " ]\n";
}

template <class T>
inline bool CStackLinkedList<T>::Push(T value)
{

    if (m_First == NULL && m_Number == 0)
    {
        m_First = new CListNode<T>;
        m_First->m_Value = value;
    }
    else
    {
        CListNode<T> *current = m_First;
        CListNode<T> *newNode = new CListNode<T>;
        if (!newNode)
            return false;
        newNode->m_Value = value;
        while (current->m_Next)
            current = current->m_Next;
        current->m_Next = newNode;
    }
    m_Number++;
    return true;
}

template <class T>
inline bool CStackLinkedList<T>::Pop(T &val)
{
    if (--m_Number == 0)
        return false;
    CListNode<T> *current = m_First;
    CListNode<T> *deleteNode;
    if (m_First->m_Next == NULL)
    {
        delete m_First;
        m_First = m_First->m_Next;
        return true;
    }
    unsigned int i;
    for (i = 0; i < m_Number -1; i++)
    {
        // if (current->m_Next == NULL)
            // return false;
        current = current->m_Next;
    }
    deleteNode = current->m_Next ? current->m_Next : current;
    val = deleteNode->m_Value;
    delete deleteNode;
    current->m_Next = NULL;
    // m_Number--;
    // deleteNode = current->m_Next;
    // val = deleteNode->m_Value;
    // delete deleteNode;
    // current->m_Next = NULL;
    // m_Number--;
    return true;
}

template <class T>
inline bool CStackLinkedList<T>::Remove(unsigned int position, T& val)
{
    if (m_Number == 0)
        return false;
    unsigned int i;
    CListNode<T> *deleteNode;
    CListNode<T> *current = m_First;
    if (position == 0)
    {
        deleteNode = m_First;
        val = m_First->m_Value;
        if (m_First->m_Next)
            m_First = m_First->m_Next;
    }
    else
    {
        for (i = 0; i < position - 1; i++)
            current = current->m_Next;
        deleteNode = current->m_Next;
        val = deleteNode->m_Value;
        current->m_Next = deleteNode->m_Next;
    }

    delete deleteNode;
    m_Number--;
    return true;
}

template <class T>
inline bool CStackLinkedList<T>::Insert(unsigned int position, T value)
{
    if (!m_First)
        return false;
    CListNode<T> *insertNode = new CListNode<T>;
    if (!insertNode)
        return false;
    insertNode->m_Value = value;
    if (position == 0)
    {
        insertNode->m_Next = m_First;
        m_First = insertNode;
        m_Number++;
        return true;
    }
    if (position + 1 > m_Number)
        return Push(value);

    unsigned int i;
    CListNode<T> *current = m_First;
    for (i = 0; i < position - 1; i++)
        current = current->m_Next;

    insertNode->m_Next = current->m_Next;
    current->m_Next = insertNode;
    m_Number++;
    return true;
}

template <class T>
inline void CStackLinkedList<T>::Clear()
{
    if (m_Number == 0) return;
    unsigned int num = m_Number;
    int val;
    for (unsigned int i = 0; i < num; i++)
        Remove(0, val);
}

template <class T>
inline void CStackLinkedList<T>::ShowNumber()
{
    std::cout << m_Number << " ";
}