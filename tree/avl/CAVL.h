#pragma once
#include <iostream>
#include <queue>


template <class T>
class CAVLTreeNode {
public:
    CAVLTreeNode<T>* m_Left;
    CAVLTreeNode<T>* m_Right;
    CAVLTreeNode<T>* m_Father;
    T m_Value;
    bool m_IsEmpty;

    CAVLTreeNode(CAVLTreeNode<T>* father = NULL)
        : m_Left(NULL)
        , m_Right(NULL)
        , m_Father(father)
        , m_Value()
        , m_IsEmpty(true) {};
    ~CAVLTreeNode() {};
};

enum RotationType {
    LL, LR, RR, RL
};

template <class T>
class CAVL {
private:
    CAVLTreeNode<T>* m_Root;

    void DeleteTree(CAVLTreeNode<T>* root);
    CAVLTreeNode<T>* GetEmptyNode(CAVLTreeNode<T>* root, T value);
    CAVLTreeNode<T>* GetDeleteNode(CAVLTreeNode<T>* root, T value);
    bool SetNode(CAVLTreeNode<T>* node, T value);
    bool DeleteNode(CAVLTreeNode<T>* node);
    void TraceBalancePath(CAVLTreeNode<T>* root);
    int GetBalanceFactor(CAVLTreeNode<T>* node);
    int GetTreeHeight(CAVLTreeNode<T>* node);
    void TreeRotation(CAVLTreeNode<T>* node, RotationType type);
    CAVLTreeNode<T>* GetMaxInLeftTree(CAVLTreeNode<T>* root);

public:
    CAVL() {
        m_Root = new CAVLTreeNode<T>;
    };
    ~CAVL() {
        DeleteTree(m_Root);
    };
    void Inorder(CAVLTreeNode<T>* root = NULL);
    void Preorder(CAVLTreeNode<T>* root = NULL);
    void Posorder(CAVLTreeNode<T>* root = NULL);
    void Levelorder(CAVLTreeNode<T>* root = NULL);
    void ShowOrders();
    bool Insert(T value);
    bool Remove(T value);

};

template <class T>
inline void CAVL<T>::Inorder(CAVLTreeNode<T>* root)
{
    if (root == NULL) root = m_Root;
    if (root->m_IsEmpty) return;
    Inorder(root->m_Left);
    std::cout << root->m_Value << ", ";
    Inorder(root->m_Right);
}

template <class T>
inline void CAVL<T>::Preorder(CAVLTreeNode<T>* root)
{
    if (root == NULL) root = m_Root;
    if (root->m_IsEmpty) return;
    std::cout << root->m_Value << ", ";
    Preorder(root->m_Left);
    Preorder(root->m_Right);
}

template <class T>
inline void CAVL<T>::Posorder(CAVLTreeNode<T>* root)
{
    if (root == NULL) root = m_Root;
    if (root->m_IsEmpty) return;
    Posorder(root->m_Left);
    Posorder(root->m_Right);
    std::cout << root->m_Value << ", ";
}

template <class T>
inline void CAVL<T>::Levelorder(CAVLTreeNode<T>* root)
{
    if (root == NULL) root = m_Root;
    if (root->m_IsEmpty) return;
    std::queue< CAVLTreeNode<T>* > q;
    q.push(root);
    while (!q.empty())
    {
        CAVLTreeNode<T>* current = q.front();
        q.pop();
        std::cout << current->m_Value << ", ";
        if (!current->m_Left->m_IsEmpty) q.push(current->m_Left);
        if (!current->m_Right->m_IsEmpty) q.push(current->m_Right);
    }
}

template <class T>
inline void CAVL<T>::ShowOrders()
{
    std::cout << "\nInorder" << "\n[ ";
    Inorder(NULL);
    std::cout << " ]\n" << std::endl;

    std::cout << "\nPreorder" << "\n[ ";
    Preorder(NULL);
    std::cout << " ]\n" << std::endl;

    std::cout << "\nPosorder" << "\n[ ";
    Posorder(NULL);
    std::cout << " ]\n" << std::endl;

    std::cout << "\nLevelorder" << "\n[ ";
    Levelorder(NULL);
    std::cout << " ]\n" << std::endl;
}

template <class T>
inline void CAVL<T>::DeleteTree(CAVLTreeNode<T>* root)
{
    if (root == nullptr) return;
    DeleteTree(root->m_Left);
    DeleteTree(root->m_Right);
    delete root;
    
}


template <class T>
inline bool CAVL<T>::Insert(T value)
{
    CAVLTreeNode<T>* insertNode = GetEmptyNode(m_Root, value);
    if (!insertNode)
        return false;
    if (!SetNode(insertNode, value))
    {
        std::cout << "Insert " << value << " failure" << std::endl;
        return false;
    }
    TraceBalancePath(insertNode);
    return true;
}

template <class T>
inline CAVLTreeNode<T>* CAVL<T>::GetEmptyNode(CAVLTreeNode<T>* root, T value)
{
    if (root->m_IsEmpty)
        return root;
    if (root->m_IsEmpty == false && root->m_Value == value)
    {
        std::cout << "Replace Value: " << value << std::endl;
        return NULL;
    }
    else if (root->m_Value > value)
    {
        if (root->m_Left->m_IsEmpty)
            return root->m_Left;
        else
            return GetEmptyNode(root->m_Left, value);
    }
    else if (root->m_Value < value)
    {
        if (root->m_Right->m_IsEmpty)
            return root->m_Right;
        else
            return GetEmptyNode(root->m_Right, value);
    }
    else
        return NULL;
}

template <class T>
inline bool CAVL<T>::SetNode(CAVLTreeNode<T>* node, T value)
{
    if (!node)
        return false;
    node->m_Left = new CAVLTreeNode<T>(node);    
    if (!node->m_Left) 
        return false;
    node->m_Right = new CAVLTreeNode<T>(node);
    if (!node->m_Right)
    {
        delete node->m_Left;
        return false;
    }
    node->m_Value = value;
    node->m_IsEmpty = false;
    return true;
}

template <class T>
inline void CAVL<T>::TraceBalancePath(CAVLTreeNode<T>* node)
{
    int balanceFactor;
    CAVLTreeNode<T>* current = node;
    while (current)
    {
        balanceFactor = GetBalanceFactor(current);
        if (abs(balanceFactor) >= 2)
            break;
        current = current->m_Father;
    }
    if (current == NULL) return;
    RotationType type;
    if (balanceFactor >= 2 && GetBalanceFactor(current->m_Left) >= 0)
        type = LL;
    else if (balanceFactor >= 2 && GetBalanceFactor(current->m_Left) < 0)
        type = LR;
    else if (balanceFactor <= -2 && GetBalanceFactor(current->m_Right) > 0)
        type = RL;
    else if (balanceFactor <= -2 && GetBalanceFactor(current->m_Right) <= 0)
        type = RR;
    TreeRotation(current, type);
}

template <class T>
inline int CAVL<T>::GetBalanceFactor(CAVLTreeNode<T>* node)
{
    if (!node) 
        return 0;
    return GetTreeHeight(node->m_Left) - GetTreeHeight(node->m_Right);
}

template <class T>
inline int CAVL<T>::GetTreeHeight(CAVLTreeNode<T>* node)
{
    if (node == NULL)
        return 0;
    int leftTreeHeight = GetTreeHeight(node->m_Left);
    int rightTreeHeight = GetTreeHeight(node->m_Right);
    if (leftTreeHeight >= rightTreeHeight)
        return leftTreeHeight + 1;
    else
        return rightTreeHeight + 1;
}

template <class T>
inline void CAVL<T>::TreeRotation (CAVLTreeNode<T>* node, RotationType type)
{
    CAVLTreeNode<T> *reg, *A, *B, *C, *CL, *CR;
    A = node;
    switch (type)
    {
        case LL:
            std::cout << "Run LL" << std::endl;
            B = A->m_Left;
            if (!A->m_Father)
                m_Root = B;
            else
                A->m_Father->m_Left == A ?
                A->m_Father->m_Left = B : A->m_Father->m_Right = B;
            
            reg = B->m_Right;
            B->m_Right = A;
            A->m_Left = reg;
            B->m_Father = A->m_Father;
            A->m_Father = B;
            if (reg)
                reg->m_Father = A;
            break;
        
        case LR:
            std::cout << "Run LR" << std::endl;
            B = A->m_Left;
            C = B->m_Right;
            if (!A->m_Father)
                m_Root = C;
            else
                A->m_Father->m_Left == A ?
                A->m_Father->m_Left = C : A->m_Father->m_Right = C;
            
            CL = C->m_Left;
            CR = C->m_Right;
            C->m_Left = B;
            C->m_Right = A;
            A->m_Left = CR;
            B->m_Right = CL;
            C->m_Father = A->m_Father;
            A->m_Father = C;
            B->m_Father = C;
            if (CL) CL->m_Father = B;
            if (CR) CR->m_Father = A;
            break;
        
        case RL:
            std::cout << "Run RL" << std::endl;
            B = A->m_Right;
            C = B->m_Left;
            if (!A->m_Father)
                m_Root = C;
            else
                A->m_Father->m_Left == A ?
                A->m_Father->m_Left = C : A->m_Father->m_Right = C;

            CL = C->m_Left;
            CR = C->m_Right;
            C->m_Left = A;
            C->m_Right = B;
            A->m_Right = CL;
            B->m_Left = CR;
            C->m_Father = A->m_Father;
            A->m_Father = C;
            B->m_Father = C;
            if (CL) CL->m_Father = A;
            if (CR) CR->m_Father = B;
            break;

        case RR:
            std::cout << "Run RR" << std::endl;
            B = A->m_Right;
            if (!A->m_Father)
                m_Root = B;
            else
                A->m_Father->m_Left == A ?
                A->m_Father->m_Left = B : A->m_Father->m_Right = B;
            
            reg = B->m_Left;
            B->m_Left = A;
            // B->m_Right = C;
            A->m_Right = reg;
            B->m_Father = A->m_Father;
            A->m_Father = B;
            if (reg) reg->m_Father = A;
            break;
    }
}

template <class T>
inline bool CAVL<T>::Remove(T value)
{
    CAVLTreeNode<T>* deleteNode = GetDeleteNode(m_Root, value);
    if (!deleteNode) return false;
    if (!DeleteNode(deleteNode)) return false;
    return true;
}

template <class T>
inline CAVLTreeNode<T>* CAVL<T>::GetDeleteNode(CAVLTreeNode<T>* node, T value)
{
    if (node->m_IsEmpty) return NULL;
    if (node->m_Value == value)
        return node;
    else if (node->m_Value > value)
        return GetDeleteNode(node->m_Left, value);
    else if (node->m_Value < value)
        return GetDeleteNode(node->m_Right, value);
    else
        return NULL;
}

template <class T>
inline bool CAVL<T>::DeleteNode(CAVLTreeNode<T>* node)
{
    // if (node->m_IsEmpty) return false;
    if (node->m_Left->m_IsEmpty && node->m_Right->m_IsEmpty)
    {
        delete node->m_Left;
        node->m_Left = NULL;
        delete node->m_Right;
        node->m_Right = NULL;
        node->m_IsEmpty = true;
        TraceBalancePath(node->m_Father);
    }
    else if (!node->m_Left->m_IsEmpty && node->m_Right->m_IsEmpty)
    {
        node->m_Value = node->m_Left->m_Value;
        delete node->m_Left->m_Left;
        node->m_Left->m_Left = NULL;
        delete node->m_Left->m_Right;
        node->m_Left->m_Right = NULL;
        node->m_Left->m_IsEmpty = true;
        TraceBalancePath(node);
    }
    else if (node->m_Left->m_IsEmpty && !node->m_Right->m_IsEmpty)
    {
        node->m_Value = node->m_Right->m_Value;
        delete node->m_Right->m_Left;
        node->m_Right->m_Left = NULL;
        delete node->m_Right->m_Right;
        node->m_Right->m_Right = NULL;
        node->m_Right->m_IsEmpty = true;
        TraceBalancePath(node);
    }
    else
    {
        CAVLTreeNode<T>* current = GetMaxInLeftTree(node->m_Left);
        node->m_Value = current->m_Value;
        delete current->m_Left;
        current->m_Left = NULL;
        delete current->m_Right;
        current->m_Right = NULL;
        current->m_IsEmpty = true;
        TraceBalancePath(current->m_Father);
    }
    return true;
} 

template <class T>
inline CAVLTreeNode<T>* CAVL<T>::GetMaxInLeftTree(CAVLTreeNode<T>* root)
{
    CAVLTreeNode<T>* current = root;
    while (!current->m_Right->m_IsEmpty)
        current = current->m_Right;
    return current;
}