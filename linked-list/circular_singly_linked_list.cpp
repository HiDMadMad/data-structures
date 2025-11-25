#include <iostream>

struct CircularLinkedList
{
    double data;
    CircularLinkedList *next;
};

CircularLinkedList *CreateNode(double NodeData)
{
    CircularLinkedList *LL = new CircularLinkedList;
    LL->data = NodeData;  // == *(LL.data)=NodeData;
    LL->next = nullptr;  // == *(LL.next)=nullptr;
    return LL;
}

void InsertAtBegin(CircularLinkedList *(&StarterNode), double data)
{
    CircularLinkedList *NewNode = CreateNode(data);

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
    CircularLinkedList *NewNode = CreateNode(data);

    if(StarterNode == nullptr)
    {
        NewNode->next = NewNode;
        StarterNode = NewNode;
        return;       
    }

    CircularLinkedList *tmp = StarterNode;
    while(tmp->next != StarterNode)
    {
        tmp = tmp->next;
    }
    NewNode->next = StarterNode;
    tmp->next = NewNode;
    // or :
    // tmp->next = NewNode;
    // NewNode->next = StarterNode;
}

void InsertInMid(CircularLinkedList *(&StarterNode), unsigned index, double data)
{   // inserts at index
    
    CircularLinkedList *NewNode = CreateNode(data);
    
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
    {
        tmp = tmp->next;
    }
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


void display(CircularLinkedList *StarterNode)
{
    if(StarterNode == nullptr)
        return;

    CircularLinkedList *tmp = StarterNode;
    std::cout<<"\nStartOfList";
    do
    {
        std::cout<<" -> "<<tmp->data;
        tmp = tmp->next;
    }while(tmp != StarterNode);
}

void FreeMemory(CircularLinkedList *(&StarterNode))
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

int main()
{
    CircularLinkedList *StartOfList = nullptr;
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
//MadMad_233