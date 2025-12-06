#include "../d-s-lib/messages.h"
#include "linear_queue.h"
#include "circular_queue.h"

int main()
{
    unsigned UserReq;
    double data=0;
    bool exit;
    
    while (true)
    {
        std::cout<<QueueMenu;
        std::cin>>UserReq;
        if(UserReq == 1)
        {
            exit=false;
            LinearQueue LQue;
            std::cout<<"\nkeep in your mind, it's one-time use.\n";
            std::cout<<GetSize;
            std::cin>>LQue.ItemsSize;
            LQue.items = new double[LQue.ItemsSize];
            while(true)
            {
                if(exit)
                    break;
                std::cout<<QueAppMenu;
                std::cin>>UserReq;
                switch(UserReq)
                {
                    case 1:
                        std::cout<<GetData;
                        std::cin>>data;
                        LqInsert(LQue, data);
                        LqShowItems(LQue);
                        break;
                    case 2:
                        std::cout<<LqRemove(LQue);
                        LqShowItems(LQue);
                        break;
                    case 0:
                        delete[] LQue.items;
                        exit=true;
                        break;
                    default:
                        std::cout<<"wrong input..!";
                        break;
                }
            }
        }
        else if (UserReq == 2)
        {
            exit=false;
            CircularQueue CQue;
            std::cout<<"\nif you want capacity for 'n' items, enter 'n+1'.\n";
            std::cout<<GetSize;
            std::cin>>CQue.ItemsSize;
            CQue.items = new double[CQue.ItemsSize];
            while(true)
            {
                if(exit)
                    break;
                std::cout<<QueAppMenu;
                std::cin>>UserReq;
                switch(UserReq)
                {
                    case 1:
                        std::cout<<GetData;
                        std::cin>>data;
                        CqInsert(CQue, data);
                        CqShowItems(CQue);
                        break;
                    case 2:
                        std::cout<<CqRemove(CQue);
                        CqShowItems(CQue);
                        break;
                    case 0:
                        delete[] CQue.items;
                        exit=true;
                        break;
                    default:
                        std::cout<<"wrong input..!";
                        break;
                }
            }
        }
        else if (UserReq == 0)
            break;
        else
            std::cout<<"wrong input..!";
    }

    return 0;
}
//MadMad_95