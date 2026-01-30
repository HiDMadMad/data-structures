#include "../binary_tree.h"

BinTree *BSTInsert(BinTree *(&root), double key)
{
    if (root == nullptr)
    {
        root = NewBinTreeNode(key);
        return root;
    }

    if (key < root->data)
        return BSTInsert(root->left, key);
    else
        return BSTInsert(root->right, key);
}

BinTree *BSTSearch(BinTree *root, double key)
{
    if((root == nullptr) || (root->data == key))
        return root;

    if (key < root->data)
        return BSTSearch(root->left, key);
    else
        return BSTSearch(root->right, key);
}

BinTree *BSTParentOfTarget(BinTree *root, BinTree *target)
{
    if((root == nullptr) || (root == target))
        return nullptr;
    
    if((root->left == target) || (root->right == target))
        return root;
    
    if(target->data < root->data)
        return BSTParentOfTarget(root->left, target);
    else
        return BSTParentOfTarget(root->right, target);
}

BinTree *BSTParentOfTargetByKey(BinTree *root, double TargetKey)
{
    if((root == nullptr) || (root->data == TargetKey))
        return nullptr;
    
    if(((root->left != nullptr)  &&  (root->left->data == TargetKey))
                                 ||
       ((root->right != nullptr) && (root->right->data == TargetKey)))
        return root;
    
    if(TargetKey < root->data)
        return BSTParentOfTargetByKey(root->left, TargetKey);
    else
        return BSTParentOfTargetByKey(root->right, TargetKey);
}

bool BSTIsIn(BinTree *root, double key)
{
    if(root == nullptr)
        return false;
    if(root->data == key)
        return true;

    if (key < root->data)
        return BSTIsIn(root->left, key);
    else
        return BSTIsIn(root->right, key);
}

BinTree *BSTMin(BinTree *root)
{
    if((root == nullptr) || (root->left == nullptr))
        return root;
    return BSTMin(root->left);
}

BinTree *BSTMax(BinTree *root)
{
    if((root == nullptr) || (root->right == nullptr))
        return root;
    return BSTMax(root->right);
}

BinTree *BSTPredecessor(BinTree *root)
{
    if(root == nullptr)
        return nullptr;
    return BSTMax(root->left);
}

BinTree *BSTSuccessor(BinTree *root)
{
    if(root == nullptr)
        return nullptr;
    return BSTMin(root->right);
}

void BSTRemoveByKey(BinTree *(&root), double key)
{
    if(root == nullptr)
        return;

    BinTree *ToDel = BSTSearch(root, key);
    if(ToDel == nullptr)
        return;

    BinTree *ParentOfToDel = BSTParentOfTarget(root, ToDel);


    if((ToDel->right != nullptr) && (ToDel->left != nullptr))  // if ToDel have two child
    {
        BinTree *successor = BSTSuccessor(ToDel);
        ToDel->data = successor->data;

        BinTree *ParentOfSuccessor = BSTParentOfTarget(root, successor);
        BinTree *ChildOfSuccessor = nullptr;
        if(successor->right != nullptr)
            ChildOfSuccessor = successor->right;

        if(ParentOfSuccessor == nullptr)
            root = ChildOfSuccessor;
        else if(ParentOfSuccessor->left == successor)
            ParentOfSuccessor->left = ChildOfSuccessor;
        else
            ParentOfSuccessor->right = ChildOfSuccessor;

        delete successor;
        return;
    }

    else if((ToDel->right == nullptr) || (ToDel->left == nullptr))  // if ToDel have zero or one child
    {
        BinTree *ChildOfToDel = ToDel->left;
        if(ChildOfToDel == nullptr)
            ChildOfToDel = ToDel->right;

        if(ParentOfToDel == nullptr)
            root = ChildOfToDel;
        else
        {
            if (ParentOfToDel->left == ToDel)
                ParentOfToDel->left = ChildOfToDel;
            else
                ParentOfToDel->right = ChildOfToDel;
        }

        delete ToDel;
    }
}

//MadMad_152