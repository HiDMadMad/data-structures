#include "../trees.h"

bool BinInsertFlag=false;
BinTree *BTInsert(BinTree *(&root), double data)
{
    if(root == nullptr)
    {
        root = NewBinTreeNode(data);
        std::cout<<root->data<<" inserted\n\n";
        return root;
    }

    //  ========== level-first ==========  //
    else if(root->left == nullptr)
    {
        std::cout<<"inserting to left child\n";
        return BTInsert(root->left, data);
    }
    
    else if(root->right == nullptr)
    {
        BinInsertFlag=!BinInsertFlag;
        std::cout<<"inserting to right child | flag = "<<BinInsertFlag<<"\n";
        return BTInsert(root->right, data);

    }

    else
    {
        if(BinInsertFlag)
        {
            std::cout<<"flag is true -> going left\n";
            return BTInsert(root->left, data);
        }
        else
        {
            std::cout<<"flag is false -> going right\n";
            return BTInsert(root->right, data);
        }
    }
}

void BinPreOrderDisplay(BinTree *root)  // root->left->right
{
    if(root == nullptr)
        return;
    std::cout<<root->data<<"  ";
    BinPreOrderDisplay(root->left);
    BinPreOrderDisplay(root->right);
}

void BinInOrderDisplay(BinTree *root)  // left->root->right
{
    if(root == nullptr)
        return;    
    BinInOrderDisplay(root->left);
    std::cout<<root->data<<"  ";
    BinInOrderDisplay(root->right);
}

void BinPostOrderDisplay(BinTree *root)  // left->right->root
{
    if(root == nullptr)
        return;
    BinPostOrderDisplay(root->left);
    BinPostOrderDisplay(root->right);
    std::cout<<root->data<<"  ";
}

void BinTruthDisplay(BinTree *root)
{
    if(root == nullptr)
        return;
    
}

unsigned NodeCounter = 0;
unsigned NumOfNodes(BinTree *root)
{
    if(root == nullptr)
        return 0;
    
    NumOfNodes(root->left);
    NumOfNodes(root->right);
    NodeCounter++;
    return NodeCounter;

    // OR
    // return (1 + NumOfNodes(root->left) + NumOfNodes(root->right));
}

unsigned LeafCounter = 0;
unsigned NumOfLeafs(BinTree *root)
{
    if(root == nullptr)
        return 0;
    
    NumOfLeafs(root->left);
    if((root->left == nullptr) && (root->right == nullptr))
        LeafCounter++;
    NumOfLeafs(root->right);
    return LeafCounter;

    // OR
    // return (NumOfLeafs(root->left) + NumOfLeafs(root->right));
}


//MadMad_109