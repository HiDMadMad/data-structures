#include <iostream>

struct LinearLinkedList
{
    double data;
    LinearLinkedList *next;
};

LinearLinkedList *CreateNodeLS(double NodeData) // LS : LinearSingly
{
    LinearLinkedList *LL = new LinearLinkedList;
    LL->data = NodeData;  // == *(LL.data)=NodeData;
    LL->next = nullptr;  // == *(LL.next)=nullptr;
    return LL;
}

void InsertAtBegin(LinearLinkedList *(&StarterNode), double data)
{
    LinearLinkedList *NewNode = CreateNodeLS(data);

    NewNode->next = StarterNode;
    StarterNode = NewNode;
}

void InsertAtEnd(LinearLinkedList *(&StarterNode), double data)
{
    LinearLinkedList *NewNode = CreateNodeLS(data);

    if(StarterNode == nullptr)
    {
        StarterNode = NewNode;
        return;       
    }

    LinearLinkedList *tmp = StarterNode;
    while(tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = NewNode;
}

void InsertInMid(LinearLinkedList *(&StarterNode), unsigned index, double data)
{   // inserts at index  
    LinearLinkedList *NewNode = CreateNodeLS(data);
    
    if(index == 0 || StarterNode == nullptr)
    {
        InsertAtBegin(StarterNode, data);
        return;
    }
    
    LinearLinkedList *tmp = StarterNode;
    for(unsigned i=0; i<index-1; i++)
    {
        if(tmp->next == nullptr)
            break;  // if index is out-of-range it will add at the end
        tmp = tmp->next;
    }

    NewNode->next = tmp->next;
    tmp->next = NewNode;
}

void DelFromBegin(LinearLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    LinearLinkedList *tmp = StarterNode;
    StarterNode = StarterNode->next;
    delete tmp;
}

void DelFromEnd(LinearLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    if(StarterNode->next == nullptr)
    {
        delete StarterNode;
        StarterNode = nullptr;
        return;
    }

    LinearLinkedList *tmp = StarterNode;
    while (tmp->next->next != nullptr)
        tmp = tmp->next;
    
    delete tmp->next;
    tmp->next = nullptr;
}

void DelFromMid(LinearLinkedList *(&StarterNode), unsigned index)
{   // deletes data at index
    
    if(StarterNode == nullptr)
        return;
    
    if(index == 0)
    {
        DelFromBegin(StarterNode);
        return;
    }

    LinearLinkedList *tmp = StarterNode;
    for(unsigned i=0; i<index-1; i++)
    {
        if(tmp->next == nullptr)
            return;  // out of range
        tmp = tmp->next;
    }

    LinearLinkedList *ToDel = tmp->next;
    tmp->next = ToDel->next;
    delete ToDel;
}


void display(LinearLinkedList *StarterNode)
{
    std::cout<<"\nStartOfList";
    LinearLinkedList *tmp = StarterNode;
    while(tmp != nullptr)
    {
        std::cout<<" -> "<<tmp->data;
        tmp = tmp->next;
    }
}

void FreeMemory(LinearLinkedList *(&StarterNode))
{
    LinearLinkedList *tmp;
    while (StarterNode != nullptr)
    {
        tmp = StarterNode;
        StarterNode = StarterNode->next;
        delete tmp;
    }
}

//MadMad_142