#include <iostream>
#include "stack.h"
#include "../d-s-lib/messages.h"

int main()
{
    stack stk;
    std::cout<<GetSize;
    std::cin>>stk.ItemsSize;
    stk.items = new double[stk.ItemsSize];
    unsigned UserReq, exit=0;
    while(true)
    {
        if(exit == 1)
            break;
        std::cout<<StackMenu;
        std::cin>>UserReq;
        switch(UserReq)
        {
            case 1:
                double itm;
                std::cout<<GetData;
                std::cin>>itm;
                push(stk, itm);
                ShowItems(stk);
                break;
            case 2:
                std::cout<<pop(stk);
                ShowItems(stk);
                break;
            case 0:
                exit = 1;
                break;
            default:
                std::cout<<"wrong input..!";
                break;
        }
    }
    delete[] stk.items;

    return 0;
}
//MadMad_43