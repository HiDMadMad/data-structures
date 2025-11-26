#include <iostream>

struct LinearDoublyLinkedList
{
    double data;
    LinearDoublyLinkedList *prev, *next;
};

LinearDoublyLinkedList *CreateNodeLD(double NodeData) // LD : Linear Doubly
{
    LinearDoublyLinkedList *LL = new LinearDoublyLinkedList{NodeData, nullptr, nullptr};
    // LL->data = NodeData;  // == *(LL.data)=NodeData;
    // LL->next = nullptr;  // == *(LL.next)=nullptr;
    // LL->prev = nullptr;  // == *(LL.prev)=nullptr;
    return LL;
}

void InsertAtBegin(LinearDoublyLinkedList *(&StarterNode), double data)
{
    LinearDoublyLinkedList *NewNode = CreateNodeLD(data);
    
    if(StarterNode != nullptr)
        StarterNode->prev = NewNode;
    NewNode->next = StarterNode;
    StarterNode = NewNode;
}

void InsertAtEnd(LinearDoublyLinkedList *(&StarterNode), double data)
{
    LinearDoublyLinkedList *NewNode = CreateNodeLD(data);

    if(StarterNode == nullptr)
    {
        StarterNode = NewNode;
        return;       
    }

    LinearDoublyLinkedList *tmp = StarterNode;
    while(tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = NewNode;
    NewNode->prev = tmp;
}

void InsertInMid(LinearDoublyLinkedList *(&StarterNode), unsigned index, double data)
{   // inserts at index
    LinearDoublyLinkedList *NewNode = CreateNodeLD(data);
    
    if(index == 0 || StarterNode == nullptr)
    {
        InsertAtBegin(StarterNode, data);
        return;
    }
    
    LinearDoublyLinkedList *tmp = StarterNode;
    for(unsigned i=0; i<index-1; i++)
    {
        if(tmp->next == nullptr)
            break;  // if index is out-of-range it will add at the end
        tmp = tmp->next;
    }

    NewNode->next = tmp->next;
    NewNode->prev = tmp;
    if(tmp->next != nullptr)
        tmp->next->prev = NewNode;
    tmp->next = NewNode;
}

void DelFromBegin(LinearDoublyLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    LinearDoublyLinkedList *tmp = StarterNode;
    if(StarterNode->next != nullptr)
        StarterNode->next->prev = nullptr;
    StarterNode = StarterNode->next;
    delete tmp;
}

void DelFromEnd(LinearDoublyLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    if(StarterNode->next == nullptr)
    {
        delete StarterNode;
        StarterNode = nullptr;
        return;
    }

    LinearDoublyLinkedList *tmp = StarterNode;
    while (tmp->next != nullptr)
        tmp = tmp->next;

    tmp->prev->next = nullptr;
    delete tmp;
}

void DelFromMid(LinearDoublyLinkedList *(&StarterNode), unsigned index)
{   // deletes data at index
    if(StarterNode == nullptr)
        return;
    
    if(index == 0)
    {
        DelFromBegin(StarterNode);
        return;
    }

    LinearDoublyLinkedList *tmp = StarterNode;
    for(unsigned i=0; i<index; i++)
    {
        if(tmp->next == nullptr)
            return;  // out of range
        tmp = tmp->next;
    }

    if(tmp->next != nullptr)
        tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    delete tmp;
}


void DisplayLD(LinearDoublyLinkedList *StarterNode)
{
    std::cout<<"\nStartOfList -> ";
    LinearDoublyLinkedList *tmp = StarterNode;
    unsigned count=0;
    while(tmp != nullptr)
    {
        if(count==0)
        {
            std::cout<<tmp->data;
            count++;
        }
        else
            std::cout<<" <-> "<<tmp->data;
        tmp = tmp->next;
    }
}

void FreeMemory(LinearDoublyLinkedList *(&StarterNode))
{
    LinearDoublyLinkedList *tmp;
    while (StarterNode != nullptr)
    {
        tmp = StarterNode;
        StarterNode = StarterNode->next;
        delete tmp;
    }
}

//MadMad_158