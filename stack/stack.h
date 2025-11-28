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

// MadMad_49