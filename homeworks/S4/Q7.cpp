#include "../../linked-list/linear_singly_linked_list.h"

LinearLinkedList *LLMerge(LinearLinkedList *StartOfList1, LinearLinkedList *StartOfList2)
{
    if(StartOfList1 == nullptr)
        return StartOfList2;
    if(StartOfList2 == nullptr)
        return StartOfList1;

    LinearLinkedList *tmp = StartOfList1;
    while(tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = StartOfList2;
    
    return StartOfList1;
}

int main()
{
    LinearLinkedList *StartOfList1=nullptr;
    InsertAtBegin(StartOfList1, 40);
    InsertAtBegin(StartOfList1, 30);
    InsertAtBegin(StartOfList1, 20);
    InsertAtBegin(StartOfList1, 10);
    DisplayLS(StartOfList1);

    LinearLinkedList *StartOfList2=nullptr;
    InsertAtBegin(StartOfList2, 80);
    InsertAtBegin(StartOfList2, 70);
    InsertAtBegin(StartOfList2, 60);
    DisplayLS(StartOfList2);

    LLMerge(StartOfList1, StartOfList2);

    std::cout<<'\n';
    DisplayLS(StartOfList1);
    DisplayLS(StartOfList2);

    return 0;
}
//MadMad_42