#include <iostream>
#include <queue>

template <class T>
class TreeNode {
public:
    TreeNode<T>* m_Father;
    TreeNode<T>* m_Left;
    TreeNode<T>* m_Right;
    T m_Value;
    bool m_IsEmpty;

    TreeNode(TreeNode<T>* father = NULL)
    : m_Father(father)
    , m_Left(NULL)
    , m_Right(NULL)
    , m_Value()
    , m_IsEmpty(true) {};
    ~TreeNode() {};
};

template <class T>
class CBST {
private:
    TreeNode<T>* m_Root;
    
    void DeleteTree(TreeNode<T>* root);
    bool SetNode(TreeNode<T>* node, T value);
    TreeNode<T>* GetEmptyNode(TreeNode<T>* root, T value);
    bool DeleteNode(TreeNode<T>* node);
    TreeNode<T>* GetDeleteNode(TreeNode<T>* root, T value);
    TreeNode<T>* GetMaxInLeftTree(TreeNode<T>* root);

public:
    CBST() {
        m_Root = new TreeNode<T>;
    };
    ~CBST() {
        DeleteTree(m_Root);
    };
    bool Insert(T value);
    bool Remove(T value);
    void Inorder(TreeNode<T>* root);
    void Preorder(TreeNode<T>* root);
    void Posorder(TreeNode<T>* root);
    void Levelorder(TreeNode<T>* root);
};
template <class T>
inline void CBST<T>::Inorder(TreeNode<T>* root)
{
    if (root == NULL)
        root = m_Root;
    if (root->m_IsEmpty)
        return;
    Inorder(root->m_Left);
    std::cout << root->m_Value << ", ";
    Inorder(root->m_Right);
}

template <class T>
inline void CBST<T>::Preorder(TreeNode<T>* root)
{
    if (root == NULL)
        root = m_Root;
    if (root->m_IsEmpty)
        return;
    std::cout << root->m_Value << ", ";
    Preorder(root->m_Left);
    Preorder(root->m_Right);
}

template <class T>
inline void CBST<T>::Posorder(TreeNode<T>* root)
{
    if (root == NULL)
        root = m_Root;
    if (root->m_IsEmpty)
        return;
    Posorder(root->m_Left);
    Posorder(root->m_Right);
    std::cout << root->m_Value << ", ";
}

template <class T>
inline void CBST<T>::Levelorder(TreeNode<T>* root)
{
    if (root == NULL)
    root = m_Root;
    std::queue< TreeNode<T>* > q;
    q.push(root);
    while ( !q.empty() )
    {
        TreeNode<T>* current = q.front();
        q.pop();
        std::cout << current->m_Value << ", ";
        if (!current->m_Left->m_IsEmpty) q.push(current->m_Left);
        if (!current->m_Right->m_IsEmpty) q.push(current->m_Right);
    }
}

template <class T>
inline void CBST<T>::DeleteTree(TreeNode<T>* root)
{
    TreeNode<T>* current = root;
    if (current->m_IsEmpty) return;
    DeleteTree(current->m_Left);
    DeleteTree(current->m_Right);
    delete current;
}

template <class T>
inline bool CBST<T>::Insert(T value)
{
    TreeNode<T>* insertNode = GetEmptyNode(m_Root, value);
    if (!insertNode)
        return false;
    return SetNode(insertNode, value);
}

template <class T>
inline TreeNode<T>* CBST<T>::GetEmptyNode(TreeNode<T>* root, T value)
{
    if (root->m_IsEmpty) return root;
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
    return NULL;
}

template <class T>
inline bool CBST<T>::SetNode(TreeNode<T>* node, T value)
{
    TreeNode<T>* current = node;
    if (!current) return false;
    current->m_Left = new TreeNode<T>(current);
    if (!node->m_Left)
        return false;
    current->m_Right = new TreeNode<T>(current);
    if (!current->m_Right)
    {
        delete current->m_Left;
        return false;
    }
    current->m_Value = value;
    current->m_IsEmpty = false;
    return true;
}

template <class T>
inline bool CBST<T>::Remove(T value)
{
    TreeNode<T>* deleteNode = GetDeleteNode(m_Root, value);
    if (!deleteNode) return false;
    return DeleteNode(deleteNode);
}

template <class T>
inline TreeNode<T>* CBST<T>::GetDeleteNode(TreeNode<T>* root, T value)
{
    if (root->m_Value == value) return root;
    else if (root->m_Value > value)
    {
        if (root->m_Left->m_Value == value)
            return root->m_Left;
        else
            return GetDeleteNode(root->m_Left, value);
    }
    else if (root->m_Value < value)
    {
        if (root->m_Right->m_Value == value)
            return root->m_Right;
        else
            return GetDeleteNode(root->m_Right, value);
    }
    return NULL;
}

template <class T>
inline TreeNode<T>* CBST<T>::GetMaxInLeftTree(TreeNode<T>* root)
{
    TreeNode<T>* current = root;
    while (!current->m_Right->m_IsEmpty)
        current = current->m_Right;
    return current;
}

template <class T>
inline bool CBST<T>::DeleteNode(TreeNode<T>* node)
{
    if (node == nullptr) return false;
    if (node->m_Left->m_IsEmpty && node->m_Right->m_IsEmpty)
    {
        delete node->m_Left;
        node->m_Left = NULL;
        delete node->m_Right;
        node->m_Right = NULL;
        node->m_IsEmpty = true;
        return true;
    }
    else if (!node->m_Left->m_IsEmpty && node->m_Right->m_IsEmpty)
    {
        T regValue = node->m_Value;
        node->m_Value = node->m_Left->m_Value;
        if ( !DeleteNode(node->m_Left) )
        {
            node->m_Value = regValue;
            return false;
        }
    }
    else if (node->m_Left->m_IsEmpty && !node->m_Right->m_IsEmpty)
    {
        T regValue = node->m_Value;
        node->m_Value = node->m_Right->m_Value;
        if ( !DeleteNode(node->m_Right) )
        {
            node->m_Value = regValue;
            return false;
        }
    }
    else
    {
        TreeNode<T>* current = GetMaxInLeftTree(node->m_Left);
        if (!current) return false;
        T regValue = node->m_Value;
        node->m_Value = current->m_Value;
        if (!DeleteNode(current))
        {
            node->m_Value = regValue;
            return false; 
        }
    }
    return true;
}