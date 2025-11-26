#include "../../linked-list/linear_doubly_linked_list.h"

void ChangeLL(LinearDoublyLinkedList *(&StarterNode))
{
    double SumOfPrev=0;
    LinearDoublyLinkedList *tmp = StarterNode;
    while(tmp != nullptr)
    {
        SumOfPrev+=tmp->data;
        tmp->data=SumOfPrev;
        tmp = tmp->next;
    }
}

int main()
{
    LinearDoublyLinkedList *StartOfList = nullptr;
    InsertAtBegin(StartOfList, 80);
    InsertAtBegin(StartOfList, 70);
    InsertAtBegin(StartOfList, 60);
    InsertAtBegin(StartOfList, 50);
    InsertAtBegin(StartOfList, 40);
    InsertAtBegin(StartOfList, 30);
    InsertAtBegin(StartOfList, 20);
    InsertAtBegin(StartOfList, 10);
    DisplayLD(StartOfList);

    ChangeLL(StartOfList);

    DisplayLD(StartOfList);

    return 0;
}
//MadMad_34