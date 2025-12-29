#include <iostream>

struct LinearQueue
{
    unsigned ItemsSize;
    double *items;
    int rear=0, front=0;
};

bool LqIsFull(struct LinearQueue &LQue)
{
    return (LQue.rear == (LQue.ItemsSize));
}

bool LqIsEmpty(struct LinearQueue &LQue)
{
    return (LQue.front == LQue.rear);
}

bool LqInsert(struct LinearQueue &LQue, double item)
{
    if(LqIsFull(LQue))
        return false;
    LQue.items[LQue.rear++] = item;
    return true;
}

double LqRemove(struct LinearQueue &LQue)
{
    if(LqIsEmpty(LQue))
        return -404;
    return LQue.items[LQue.front++];
}

void LqShowItems(struct LinearQueue LQue)
{
    std::cout<<"\n\nin Linear Queue :";
    for(int i=LQue.front; i<LQue.rear; i++)
        std::cout<<'\n'<<LQue.items[i];
    std::cout<<'\n';
}

//MadMad_43