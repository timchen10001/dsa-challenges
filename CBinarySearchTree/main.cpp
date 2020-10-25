#include <iostream>
#include "CBinarySearchTree.h"

int main (void)
{
    CBST<int> bst;
    bst.Insert(10);
    bst.Insert(30);
    bst.Insert(1);
    bst.Insert(40);
    bst.Insert(70);

    std::cout << "Ineorder: ";
    bst.Inorder(NULL);
    std::cout << "\n";
    std::cout << "Preorder: ";
    bst.Preorder(NULL);
    std::cout << "\n";
    std::cout << "Posorder: ";
    bst.Posorder(NULL);
    std::cout << "\n";
    std::cout << "Levelorder: ";
    bst.Levelorder(NULL);
    std::cout << "\n";
    std::cout << std::endl;

    std::cout << "Remove: " << 10;
    bst.Remove(10);
    std::cout << "\n";
    std::cout << "Ineorder: ";
    bst.Inorder(NULL);
    std::cout << "\n";
    std::cout << "Preorder: ";
    bst.Preorder(NULL);
    std::cout << "\n";
    std::cout << "Posorder: ";
    bst.Posorder(NULL);
    std::cout << "\n";
    std::cout << "Levelorder: ";
    bst.Levelorder(NULL);
    std::cout << "\n";
    std::cout << std::endl;

    std::cout << "Remove: " << 40;
    std::cout << "\n";
    bst.Remove(40);
    std::cout << "Ineorder: ";
    bst.Inorder(NULL);
    std::cout << "\n";
    std::cout << "Preorder: ";
    bst.Preorder(NULL);
    std::cout << "\n";
    std::cout << "Posorder: ";
    bst.Posorder(NULL);
    std::cout << "\n";
    std::cout << "Levelorder: ";
    bst.Levelorder(NULL);
    std::cout << "\n";
    std::cout << std::endl;
}