#include <iostream>
#include <math.h>

struct stack
{
    unsigned ItemsSize;
    double *items;
    int top = -1;
};

bool IsFull(stack &stk)
{
    if(stk.top == stk.ItemsSize-1)
        return true;
    return false;
}

bool IsEmpty(stack &stk)
{
    if(stk.top == -1)
        return true;
    return false;
}
    
bool push(stack &stk, double item)
{
    if(IsFull(stk))
        return false;
    stk.items[++stk.top] = item;
    return true;
}

double pop(stack &stk)
{
    if(IsEmpty(stk))
        return NAN;
    return stk.items[stk.top--];
}

void ShowItems(stack &stk)
{
    std::cout<<"\n\nin stack :";
    for(int i=0; i<stk.top+1; i++)
    {
        std::cout<<"\n"<<stk.items[i];
    }
}

int main()
{
    stack stk;
    std::cin>>stk.ItemsSize;
    stk.items = new double[stk.ItemsSize];
    unsigned UserReq, exit=0;
    while(true)
    {
        if(exit == 1)
            break;
        std::cout<<"\n\n1.push\n2.pop\n0.exit\n";
        std::cin>>UserReq;
        switch(UserReq)
        {
            case 1:
                double itm;
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
// MadMad_85