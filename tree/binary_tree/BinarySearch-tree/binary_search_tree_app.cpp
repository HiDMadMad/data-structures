#include "binary_search_tree.h"

int main()
{
    BinTree *bst = nullptr;
    BSTInsert(bst, 10);  // random numbers..
    BSTInsert(bst, 30);
    BSTInsert(bst, 50);
    BSTInsert(bst, 5);
    BSTInsert(bst, 21);
    BSTInsert(bst, 8);
    BSTInsert(bst, 9);
    
    std::cout<<"Binary Search Tree\nPRE :\n";
    BinPreOrderDisplay(bst);
    std::cout<<"\nIN :\n";
    BinInOrderDisplay(bst);
    std::cout<<"\nPOST :\n";
    BinPostOrderDisplay(bst);

    std::cout<<"\nMIN :\n"<<BSTMin(bst)->data;
    std::cout<<"\nMAX :\n"<<BSTMax(bst)->data;

    BSTRemoveByKey(bst, 50);
    std::cout<<"\nMAX AFTER REMOVE :\n"<<BSTMax(bst)->data;
}

//MadMad_28