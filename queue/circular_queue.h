#include <iostream>

struct CircularQueue
{
    unsigned ItemsSize;
    double *items;
    int rear=0, front=0;
};

bool CqIsFull(struct CircularQueue &CQue)
{
    return ((CQue.rear+1) % CQue.ItemsSize == CQue.front);
}

bool CqIsEmpty(struct CircularQueue &CQue)
{
    return CQue.front == CQue.rear;
}

bool CqInsert(struct CircularQueue &CQue, double item)
{
    if(CqIsFull(CQue))
        return false;
    CQue.rear = (CQue.rear+1) % CQue.ItemsSize;
    CQue.items[CQue.rear] = item;
    return true;
}

double CqRemove(struct CircularQueue &CQue)
{
    if(CqIsEmpty(CQue))
        return -404;
    CQue.front = (CQue.front+1) % CQue.ItemsSize;
    double value = CQue.items[CQue.front];
    return value;
}

void CqShowItems(struct CircularQueue CQue)
{
    std::cout<<"\n\nin Circular Queue :";
    int i = (CQue.front+1) % CQue.ItemsSize;
    while(i != (CQue.rear+1) % CQue.ItemsSize)
    {
        std::cout<<'\n'<< CQue.items[i];
        i = (i+1) % CQue.ItemsSize;
    }
    std::cout<<'\n';
}

//MadMad_50