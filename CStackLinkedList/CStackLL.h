#pragma once
#include <iostream>

template <class T>
class CNode
{
public:
    CNode<T> *m_Next;
    T m_Value;

    CNode() : m_Next(NULL), m_Value(){};
    ~CNode(){};
};

template <class T>
class CStackLL
{
private:
    CNode<T> *m_First;
    unsigned int m_Number;

public:
    CStackLL();
    ~CStackLL();
    void Show();
    bool Push(T value);
    bool Pop(T &val);
    bool Insert(unsigned int position, T value);
    bool Remove(unsigned int position);
    void Clear();
    void ShowNumber();
};

template <class T>
inline CStackLL<T>::CStackLL()
    : m_Number(0)
{
    m_First = new CNode<T>;
}

template <class T>
inline CStackLL<T>::~CStackLL()
{
    CNode<T>* current = m_First;
    while (current)
    {
        delete current;
        current = current->m_Next;
    }
}

template <class T>
inline void CStackLL<T>::Show()
{
    CNode<T> *current = m_First;
    std::cout << "[ ";
    while (current)
    {
        std::cout << current->m_Value;
        current = current->m_Next;
        if (current)
            std::cout << ", ";
    }
    std::cout << " ]\n";
}

template <class T>
inline bool CStackLL<T>::Push(T value)
{
    if (!m_First)
        return false;
    if (m_Number == 0)
        m_First->m_Value = value;
    else
    {
        CNode<T> *current = m_First;
        CNode<T> *newNode = new CNode<T>;
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
inline bool CStackLL<T>::Pop(T &val)
{
    if (!m_First)
        return false;
    unsigned int i;
    CNode<T> *current = m_First;
    CNode<T> *deleteNode;
    for (i = 0; i < m_Number - 2; i++)
        current = current->m_Next;

    deleteNode = current->m_Next;
    val = deleteNode->m_Value;
    delete deleteNode;
    current->m_Next = NULL;
    m_Number--;
    return true;
}

template <class T>
inline bool CStackLL<T>::Remove(unsigned int position)
{
    if (m_Number == 0)
        return false;
    unsigned int i;
    CNode<T> *deleteNode;
    CNode<T> *current = m_First;
    if (position == 0)
    {
        deleteNode = m_First;
        m_First = m_First->m_Next;
    }
    else
    {
        for (i = 0; i < position - 1; i++)
            current = current->m_Next;
        deleteNode = current->m_Next;
        current->m_Next = deleteNode->m_Next;
    }

    delete deleteNode;
    m_Number--;
    return true;
}

template <class T>
inline bool CStackLL<T>::Insert(unsigned int position, T value)
{
    if (!m_First)
        return false;
    CNode<T> *insertNode = new CNode<T>;
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
    CNode<T> *current = m_First;
    for (i = 0; i < position - 1; i++)
        current = current->m_Next;

    insertNode->m_Next = current->m_Next;
    current->m_Next = insertNode;
    m_Number++;
    return true;
}

template <class T>
inline void CStackLL<T>::Clear()
{
    if (m_Number == 0) return;
    unsigned int num = m_Number;
    for (unsigned int i = 0; i < num; i++)
        Remove(0);
}

template <class T>
inline void CStackLL<T>::ShowNumber()
{
    std::cout << m_Number << " ";
}