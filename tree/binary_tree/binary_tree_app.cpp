#include "binary_tree.h"

int main()
{
    BinTree *bt = nullptr;
    BTInsert(bt, 10);  // random numbers..
    BTInsert(bt, 30);
    BTInsert(bt, 50);
    BTInsert(bt, 5);
    BTInsert(bt, 21);
    BTInsert(bt, 8);
    BTInsert(bt, 9);

    std::cout<<"\nnum of nodes : "<< NumOfNodes(bt);
    std::cout<<"\nnum of leafs : "<< NumOfLeafs(bt);

    std::cout<<"\n\npre-order :  ";
    BinPreOrderDisplay(bt);
    std::cout<<"\n\nin-order :  ";
    BinInOrderDisplay(bt);
    std::cout<<"\n\npost-order :  ";
    BinPostOrderDisplay(bt);
    std::cout<<"\n\n";
}

//MadMad_26