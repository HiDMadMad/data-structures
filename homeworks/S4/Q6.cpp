#include "../../linked-list/linear_singly_linked_list.h"
#include "../../stack/stack.h"

void LLInverter(LinearLinkedList *(&StarterNode))
{
    if(StarterNode == nullptr || StarterNode->next == nullptr)
        return;
    
    LinearLinkedList *tmp = StarterNode;
    unsigned ListSize = 1;
    while(tmp != nullptr)
    {
        tmp = tmp->next;
        ListSize++;
    }
    
    stack stk {ListSize, new double[ListSize], -1};
    tmp = StarterNode;
    while(tmp != nullptr)
    {
        push(stk, tmp->data);
        tmp = tmp->next;
    }

    tmp = StarterNode;
    while(tmp != nullptr)
    {
        tmp->data = pop(stk);
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
    
    LLInverter(StartOfList);

    DisplayLS(StartOfList);

    return 0;
}
//MadMad_52