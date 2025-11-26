#include "../../linked-list/circular_doubly_linked_list.h"

unsigned NumOfNodes(CircularDoublyLinkedList *(&StarterNode))
{
    CircularDoublyLinkedList *tmp = StarterNode;
    unsigned count = 1;
    while(tmp->next != StarterNode)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

int main()
{
    CircularDoublyLinkedList *StartOfList = nullptr;
    InsertAtBegin(StartOfList, 80);
    InsertAtBegin(StartOfList, 70);
    InsertAtBegin(StartOfList, 60);
    InsertAtBegin(StartOfList, 50);
    InsertAtBegin(StartOfList, 40);
    InsertAtBegin(StartOfList, 30);
    InsertAtBegin(StartOfList, 20);
    InsertAtBegin(StartOfList, 10);
    DisplayCD(StartOfList);

    std::cout<<"\nnumber of nodes : "<<NumOfNodes(StartOfList)<<'\n';

    return 0;
}
//MadMad_32