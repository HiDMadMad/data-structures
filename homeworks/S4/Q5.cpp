#include "../../linked-list/linear_singly_linked_list.h"

void ChangeLL(LinearLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr)
        return;

    LinearLinkedList *tmp = StarterNode;
    while(tmp != nullptr && tmp->next != nullptr)
    {
        LinearLinkedList *ToDel = tmp->next;
        tmp->next = tmp->next->next;
        delete ToDel;
        tmp = tmp->next;
    }
}

int main()
{
    LinearLinkedList *StartOfList = nullptr;
    InsertAtBegin(StartOfList, 80);
    InsertAtBegin(StartOfList, 70);
    InsertAtBegin(StartOfList, 60);
    InsertAtBegin(StartOfList, 50);
    InsertAtBegin(StartOfList, 40);
    InsertAtBegin(StartOfList, 30);
    InsertAtBegin(StartOfList, 20);
    InsertAtBegin(StartOfList, 10);
    DisplayLS(StartOfList);

    ChangeLL(StartOfList);

    DisplayLS(StartOfList);

    return 0;
}
//MadMad_37