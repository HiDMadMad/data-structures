#include <iostream>

struct CircularDoublyLinkedList
{
    double data;
    CircularDoublyLinkedList *prev, *next;
};

CircularDoublyLinkedList *CreateNodeCD(double NodeData) // CD : Circular Doubly
{
    CircularDoublyLinkedList *LL = new CircularDoublyLinkedList{NodeData, nullptr, nullptr};
    // LL->data = NodeData;  // == *(LL.data)=NodeData;
    // LL->next = nullptr;  // == *(LL.next)=nullptr;
    // LL->prev = nullptr;  // == *(LL.prev)=nullptr;
    return LL;
}

void InsertAtBegin(CircularDoublyLinkedList *(&StarterNode), double data)
{
    CircularDoublyLinkedList *NewNode = CreateNodeCD(data);

    if(StarterNode == nullptr)
    {
        StarterNode = NewNode;
        StarterNode->prev = NewNode;
        NewNode->next = StarterNode;
        return;
    }

    NewNode->next = StarterNode;
    NewNode->prev = StarterNode->prev;
    StarterNode->prev->next = NewNode;
    StarterNode->prev = NewNode;
    StarterNode = NewNode;
}

void InsertAtEnd(CircularDoublyLinkedList *(&StarterNode), double data)
{
    CircularDoublyLinkedList *NewNode = CreateNodeCD(data);

    if(StarterNode == nullptr)
    {
        StarterNode = NewNode;
        StarterNode->prev = NewNode;
        NewNode->next = StarterNode;
        return;      
    }

    NewNode->next = StarterNode;
    NewNode->prev = StarterNode->prev;
    StarterNode->prev->next = NewNode;
    StarterNode->prev = NewNode;
}

void InsertInMid(CircularDoublyLinkedList *(&StarterNode), unsigned index, double data)
{   // inserts at index 
    CircularDoublyLinkedList *NewNode = CreateNodeCD(data);
    
    if(index == 0 || StarterNode == nullptr)
    {
        InsertAtBegin(StarterNode, data);
        return;
    }
    
    CircularDoublyLinkedList *tmp = StarterNode;
    for(unsigned i=0; i<index-1; i++)
    {
        if(tmp->next == StarterNode)
            break;  // if index is out-of-range it will add at the end
        tmp = tmp->next;
    }

    NewNode->next = tmp->next;
    NewNode->prev = tmp;
    tmp->next->prev = NewNode;
    tmp->next = NewNode;
}

void DelFromBegin(CircularDoublyLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    if(StarterNode->next == StarterNode)
    {
        delete StarterNode;
        StarterNode = nullptr;
        return;
    }

    CircularDoublyLinkedList *tmp = StarterNode;
    StarterNode->prev->next = StarterNode->next;
    StarterNode->next->prev = StarterNode->prev;
    StarterNode = StarterNode->next;
    delete tmp;
}

void DelFromEnd(CircularDoublyLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    if(StarterNode->next == StarterNode)
    {
        delete StarterNode;
        StarterNode = nullptr;
        return;
    }

    CircularDoublyLinkedList *tmp = StarterNode->prev;
    tmp->prev->next = StarterNode;
    StarterNode->prev = tmp->prev;
    delete tmp;
}

void DelFromMid(CircularDoublyLinkedList *(&StarterNode), unsigned index)
{   // deletes data at index
    if(StarterNode == nullptr)
        return;
    
    if(index == 0)
    {
        DelFromBegin(StarterNode);
        return;
    }

    CircularDoublyLinkedList *tmp = StarterNode;
    for(unsigned i=0; i<index; i++)
    {
        if(tmp->next == StarterNode)
            return;  // out of range
        tmp = tmp->next;
    }

    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    delete tmp;
}


void DisplayCD(CircularDoublyLinkedList *StarterNode)
{
    std::cout<<"\nStartOfList -> ";
    if(StarterNode == nullptr)
        return;
    CircularDoublyLinkedList *tmp = StarterNode;
    unsigned count=0;
    do
    {
        if(count==0)
        {
            std::cout<<tmp->data;
            count++;
        }
        else
            std::cout<<" <-> "<<tmp->data;
        tmp = tmp->next;
    }while(tmp != StarterNode);
    std::cout<<" -> "<<StarterNode->data<<"(Starter Node)\n";
}

void FreeMemoryCD(CircularDoublyLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    CircularDoublyLinkedList *tmp = StarterNode->next;
    while (tmp != StarterNode)
    {
        CircularDoublyLinkedList *next = tmp->next;
        delete tmp;
        tmp = next;
    }
    delete StarterNode;
    StarterNode = nullptr;
}

//MadMad_178