#include <iostream>
#include "../../linked-list/linear_doubly_linked_list.h"

LinearDoublyLinkedList *skipper(LinearDoublyLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr || StarterNode->next == nullptr)
        return StarterNode;

    LinearDoublyLinkedList *OddTmp = StarterNode;    
    LinearDoublyLinkedList *StartOfEvens = StarterNode->next;
    LinearDoublyLinkedList *EvenTmp = StartOfEvens;
    while((OddTmp!=nullptr && OddTmp->next!=nullptr) && (EvenTmp!=nullptr && EvenTmp->next!=nullptr))
    {
        OddTmp->next = OddTmp->next->next;
        EvenTmp->next = EvenTmp->next->next;

        OddTmp = OddTmp->next;
        EvenTmp = EvenTmp->next;
    }
    if (OddTmp != nullptr)
        OddTmp->next = nullptr;

    return StartOfEvens;
}

void DisplaySkipper(LinearDoublyLinkedList* StarterNode)
{
    LinearDoublyLinkedList *tmp = StarterNode;
    while (tmp != nullptr)
    {
        if (tmp->next != nullptr)
            std::cout << tmp->data << " -> " << tmp->next->data << "\n";
        else
            std::cout << tmp->data << " -> null\n";
        tmp = tmp->next;
    }
    std::cout << "\n";
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
    DisplaySkipper(StartOfList);

    LinearDoublyLinkedList *EvenLL = skipper(StartOfList);
    
    DisplaySkipper(StartOfList);
    DisplaySkipper(EvenLL);

    return 0;
}
//MadMad_60