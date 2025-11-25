#include <iostream>

struct LinearLinkedList
{
    double data;
    LinearLinkedList *next;
};

LinearLinkedList *CreateNode(double NodeData)
{
    LinearLinkedList *LL = new LinearLinkedList;
    LL->data = NodeData;  // == *(LL.data)=NodeData;
    LL->next = nullptr;  // == *(LL.next)=nullptr;
    return LL;
}

void InsertAtBegin(LinearLinkedList *(&StarterNode), double data)
{
    LinearLinkedList *NewNode = CreateNode(data);
    NewNode->next = StarterNode;
    StarterNode = NewNode;
}

void InsertAtEnd(LinearLinkedList *(&StarterNode), double data)
{
    LinearLinkedList *NewNode = CreateNode(data);

    if(StarterNode == nullptr)
    {
        StarterNode = NewNode;
        return;       
    }

    LinearLinkedList *tmp = StarterNode;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = NewNode;
}

void InsertInMid(LinearLinkedList *(&StarterNode), unsigned index, double data)
{   // inserts at index
    
    LinearLinkedList *NewNode = CreateNode(data);
    
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
    {
        tmp = tmp->next;
    }
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
    LinearLinkedList *tmp = StarterNode;
    std::cout<<"\nStartOfList";
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

int main()
{
    LinearLinkedList *StartOfList = nullptr;
    unsigned UserReq, index, exit=0;
    double data;
    while(true)
    {
        if(exit == 1)
            break;
        std::cout<<"\n\n1.InsertAtBegin\n2.InsertInMid\n3.InsertAtEnd\n4.DelFromBegin\n5.DelFromMid\n6.DelFromEnd\n0.Exit\n>> ";
        std::cin>>UserReq;
        switch(UserReq)
        {
            case 1:
                std::cin>>data;
                InsertAtBegin(StartOfList, data);
                display(StartOfList);
                break;
            case 2:
                std::cin>>data;
                std::cin>>index;
                InsertInMid(StartOfList, index, data);
                display(StartOfList);
                break;
            case 3:
                std::cin>>data;
                InsertAtEnd(StartOfList, data);
                display(StartOfList);
                break;
            case 4:
                DelFromBegin(StartOfList);
                display(StartOfList);
                break;
            case 5:
                std::cin>>index;
                DelFromMid(StartOfList, index);
                display(StartOfList);
                break;
            case 6:
                DelFromEnd(StartOfList);
                display(StartOfList);
                break;
            case 0:
                exit = 1;
                break;
            default:
                std::cout<<"wrong input..!";
                break;
        }
    }
    FreeMemory(StartOfList);

    return 0;
}
//MadMad_195