#include <iostream>

struct BinTree
{
    double data;
    BinTree *left, *right;
};

// constructor of BinTree
BinTree *NewBinTreeNode(double data)
{
    BinTree *bt = new BinTree{data, nullptr, nullptr};
    return bt;
}

//MadMad_16