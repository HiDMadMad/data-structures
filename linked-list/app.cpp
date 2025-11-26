#include <iostream>
#include "../d-s-lib/messages.h"
#include "linear_singly_linked_list.h"
#include "circular_singly_linked_list.h"
#include "linear_doubly_linked_list.h"
#include "circular_doubly_linked_list.h"

int main()
{
    unsigned UserReq, index, LLExit=0;
    double data;

    LinearLinkedList *StartOfLinearSingly = nullptr;
    CircularLinkedList *StartOfCircularSingly = nullptr;
    LinearDoublyLinkedList *StartOfLinearDoubly = nullptr;
    CircularDoublyLinkedList *StartOfCircularDoubly = nullptr;
    
    enum ListTypes
    {
        NONE=0,
        LinearSingly,
        CircularSingly,
        LinearDoubly,
        CircularDoubly
    };
    ListTypes ActiveListType = NONE;

    while (true)
    {
        std::cout<<LinkedListMenu;
        std::cin>>UserReq;
        if(UserReq == 0)
            break;
        else if(UserReq == 1)
        {
            ActiveListType = LinearSingly;
        }
        else if(UserReq == 2)
        {
            ActiveListType = CircularSingly;
        }
        else if(UserReq == 3)
        {
            ActiveListType = LinearDoubly;
        }
        else if(UserReq == 4)
        {
            ActiveListType = CircularDoubly;
        }
        else
        {
            std::cout<<"wrong input..!"<<std::endl;
            continue;
        }
        
        LLExit = 0;
        while(true)
        {
            if(LLExit == 1)
                break;

            std::cout<<AppMenu;
            std::cin>>UserReq;
            switch(UserReq)
            {
                case 1:
                    std::cout<<GetData;
                    std::cin>>data;
                    if(ActiveListType == LinearSingly)
                    {
                        InsertAtBegin(StartOfLinearSingly, data);
                        DisplayLS(StartOfLinearSingly);
                    }
                    else if(ActiveListType == CircularSingly)
                    {
                        InsertAtBegin(StartOfCircularSingly, data);
                        DisplayCS(StartOfCircularSingly);
                    }
                    else if(ActiveListType == LinearDoubly)
                    {
                        InsertAtBegin(StartOfLinearDoubly, data);
                        DisplayLD(StartOfLinearDoubly);
                    }
                    else if(ActiveListType == CircularDoubly)
                    {
                        InsertAtBegin(StartOfCircularDoubly, data);
                        DisplayCD(StartOfCircularDoubly);
                    }
                    break;
                case 2:
                    std::cout<<GetData;
                    std::cin>>data;
                    std::cout<<GetIndex;
                    std::cin>>index;
                    if(ActiveListType == LinearSingly)
                    {
                        InsertInMid(StartOfLinearSingly, index, data);
                        DisplayLS(StartOfLinearSingly);
                    }
                    else if(ActiveListType == CircularSingly)
                    {
                        InsertInMid(StartOfCircularSingly, index, data);
                        DisplayCS(StartOfCircularSingly);
                    }
                    else if(ActiveListType == LinearDoubly)
                    {
                        InsertInMid(StartOfLinearDoubly, index, data);
                        DisplayLD(StartOfLinearDoubly);
                    }
                    else if(ActiveListType == CircularDoubly)
                    {
                        InsertInMid(StartOfCircularDoubly, index, data);
                        DisplayCD(StartOfCircularDoubly);
                    }
                    break;
                case 3:
                    std::cout<<GetData;
                    std::cin>>data;
                    if(ActiveListType == LinearSingly)
                    {
                        InsertAtEnd(StartOfLinearSingly, data);
                        DisplayLS(StartOfLinearSingly);
                    }
                    else if(ActiveListType == CircularSingly)
                    {
                        InsertAtEnd(StartOfCircularSingly, data);
                        DisplayCS(StartOfCircularSingly);
                    }
                    else if(ActiveListType == LinearDoubly)
                    {
                        InsertAtEnd(StartOfLinearDoubly, data);
                        DisplayLD(StartOfLinearDoubly);
                    }
                    else if(ActiveListType == CircularDoubly)
                    {
                        InsertAtEnd(StartOfCircularDoubly, data);
                        DisplayCD(StartOfCircularDoubly);
                    }
                    break;
                case 4:
                    if(ActiveListType == LinearSingly)
                    {
                        DelFromBegin(StartOfLinearSingly);
                        DisplayLS(StartOfLinearSingly);
                    }
                    else if(ActiveListType == CircularSingly)
                    {
                        DelFromBegin(StartOfCircularSingly);
                        DisplayCS(StartOfCircularSingly);
                    }
                    else if(ActiveListType == LinearDoubly)
                    {
                        DelFromBegin(StartOfLinearDoubly);
                        DisplayLD(StartOfLinearDoubly);
                    }
                    else if(ActiveListType == CircularDoubly)
                    {
                        DelFromBegin(StartOfCircularDoubly);
                        DisplayCD(StartOfCircularDoubly);
                    }
                    break;
                case 5:
                    std::cout<<GetIndex;
                    std::cin>>index;
                    if(ActiveListType == LinearSingly)
                    {
                        DelFromMid(StartOfLinearSingly, index);
                        DisplayLS(StartOfLinearSingly);
                    }
                    else if(ActiveListType == CircularSingly)
                    {
                        DelFromMid(StartOfCircularSingly, index);
                        DisplayCS(StartOfCircularSingly);
                    }
                    else if(ActiveListType == LinearDoubly)
                    {
                        DelFromMid(StartOfLinearDoubly, index);
                        DisplayLD(StartOfLinearDoubly);
                    }
                    else if(ActiveListType == CircularDoubly)
                    {
                        DelFromMid(StartOfCircularDoubly, index);
                        DisplayCD(StartOfCircularDoubly);
                    }
                    break;
                case 6:
                    if(ActiveListType == LinearSingly)
                    {
                        DelFromEnd(StartOfLinearSingly);
                        DisplayLS(StartOfLinearSingly);
                    }
                    else if(ActiveListType == CircularSingly)
                    {
                        DelFromEnd(StartOfCircularSingly);
                        DisplayCS(StartOfCircularSingly);
                    }
                    else if(ActiveListType == LinearDoubly)
                    {
                        DelFromEnd(StartOfLinearDoubly);
                        DisplayLD(StartOfLinearDoubly);
                    }
                    else if(ActiveListType == CircularDoubly)
                    {
                        DelFromEnd(StartOfCircularDoubly);
                        DisplayCD(StartOfCircularDoubly);
                    }
                    break;
                case 0:
                    LLExit = 1;
                    break;
                default:
                    std::cout<<"wrong input..!";
                    break;
            }
        }
    }
    FreeMemory(StartOfLinearSingly);
    FreeMemory(StartOfCircularSingly);
    FreeMemory(StartOfLinearDoubly);
    FreeMemory(StartOfCircularDoubly);

    return 0;
}
//MadMad_224