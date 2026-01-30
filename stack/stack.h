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

//------------------------------------------
struct ChStack
{
    unsigned ItemsSize;
    char *items;
    int top = -1;
};

bool ChIsFull(ChStack &ChStk)
{
    if(ChStk.top == ChStk.ItemsSize-1)
        return true;
    return false;
}

bool ChIsEmpty(ChStack &ChStk)
{
    if(ChStk.top == -1)
        return true;
    return false;
}
    
bool ChPush(ChStack &ChStk, char item)
{
    if(ChIsFull(ChStk))
        return false;
    ChStk.items[++ChStk.top] = item;
    return true;
}

char ChPop(ChStack &ChStk)
{
    if(ChIsEmpty(ChStk))
        return '\0';
    return ChStk.items[ChStk.top--];
}

char ChPeek(ChStack &ChStk)
{
    if(ChIsEmpty(ChStk))
        return '\0';
    return ChStk.items[ChStk.top];
}

void ChShowItems(ChStack &ChStk)
{
    std::cout<<"\n\nin stack :";
    for(int i=0; i<ChStk.top+1; i++)
    {
        std::cout<<"\n"<<ChStk.items[i];
    }
}

// MadMad_102