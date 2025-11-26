#include <iostream>

struct CircularLinkedList
{
    double data;
    CircularLinkedList *next;
};

CircularLinkedList *CreateNodeCS(double NodeData) // CS : Circular Singly
{
    CircularLinkedList *LL = new CircularLinkedList;
    LL->data = NodeData;  // == *(LL.data)=NodeData;
    LL->next = nullptr;  // == *(LL.next)=nullptr;
    return LL;
}

void InsertAtBegin(CircularLinkedList *(&StarterNode), double data)
{
    CircularLinkedList *NewNode = CreateNodeCS(data);

    if(StarterNode == nullptr)
    {
        NewNode->next = NewNode;
        StarterNode = NewNode;
        return;
    }

    CircularLinkedList *tmp = StarterNode;
    while(tmp->next != StarterNode)
        tmp = tmp->next;

    NewNode->next = tmp->next;
    StarterNode = NewNode;
    tmp->next = StarterNode;
}

void InsertAtEnd(CircularLinkedList *(&StarterNode), double data)
{
    CircularLinkedList *NewNode = CreateNodeCS(data);

    if(StarterNode == nullptr)
    {
        NewNode->next = NewNode;
        StarterNode = NewNode;
        return;       
    }

    CircularLinkedList *tmp = StarterNode;
    while(tmp->next != StarterNode)
        tmp = tmp->next;

    NewNode->next = StarterNode;
    tmp->next = NewNode;
    // or :
    // tmp->next = NewNode;
    // NewNode->next = StarterNode;
}

void InsertInMid(CircularLinkedList *(&StarterNode), unsigned index, double data)
{   // inserts at index
    CircularLinkedList *NewNode = CreateNodeCS(data);
    
    if(index == 0 || StarterNode == nullptr)
    {
        InsertAtBegin(StarterNode, data);
        return;
    }
    
    CircularLinkedList *tmp = StarterNode;
    for(unsigned i=0; i<index-1; i++)
    {
        if(tmp->next == StarterNode)
            break;  // if index is out-of-range it will add at the end
        tmp = tmp->next;
    }

    NewNode->next = tmp->next;
    tmp->next = NewNode;
}

void DelFromBegin(CircularLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;
    
    if(StarterNode->next == StarterNode)
    {
        delete StarterNode;
        StarterNode = nullptr;
        return;
    }

    CircularLinkedList *LastNode = StarterNode;
    while(LastNode->next != StarterNode)
        LastNode = LastNode->next;

    CircularLinkedList *tmp = StarterNode;
    StarterNode = StarterNode->next;
    LastNode->next = StarterNode;
    delete tmp;
}

void DelFromEnd(CircularLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    if(StarterNode->next == StarterNode)
    {
        delete StarterNode;
        StarterNode = nullptr;
        return;
    }

    CircularLinkedList *tmp = StarterNode;
    while (tmp->next->next != StarterNode)
        tmp = tmp->next;

    delete tmp->next;
    tmp->next = StarterNode;
}

void DelFromMid(CircularLinkedList *(&StarterNode), unsigned index)
{   // deletes data at index
    if(StarterNode == nullptr)
        return;
    
    if(index == 0)
    {
        DelFromBegin(StarterNode);
        return;
    }

    CircularLinkedList *tmp = StarterNode;
    for(unsigned i=0; i<index-1; i++)
    {
        if(tmp->next == StarterNode)
            return;  // out of range
        tmp = tmp->next;
    }

    CircularLinkedList *ToDel = tmp->next;
    tmp->next = ToDel->next;
    delete ToDel;
}


void DisplayCS(CircularLinkedList *StarterNode)
{
    std::cout<<"\nStartOfList";
    if(StarterNode == nullptr)
        return;
    CircularLinkedList *tmp = StarterNode;
    do
    {
        std::cout<<" -> "<<tmp->data;
        tmp = tmp->next;
    }while(tmp != StarterNode);
    std::cout<<" -> "<<StarterNode->data<<"(Starter Node)\n";
}

void FreeMemoryCS(CircularLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    CircularLinkedList *tmp = StarterNode->next;
    while (tmp != StarterNode)
    {
        CircularLinkedList *next = tmp->next;
        delete tmp;
        tmp = next;
    }
    delete StarterNode;
    StarterNode = nullptr;
}

//MadMad_178