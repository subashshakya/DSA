//implementation of linear queue

#include<iostream>
#include<stdlib.h>
#define MAXQUEUE 10

using namespace std;

class Queue{
public:
    int front;
    int rear;
    int item[MAXQUEUE];

    Queue()
    {
        rear = -1;
        front = 0;
        for(int i=0;i<MAXQUEUE-1;i++)
        {
            item[i] = 0;
        }
    }


    bool isEmpty()
    {
        if(rear < front)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }

    bool isFull()
    {
        if(rear == MAXQUEUE -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void Enqueue(int newitem)
    {
        if(isFull())
        {
            cout<<"The Queue is full and new items cant be added"<<endl;
            exit(1);
        }
        else{
            rear++;
            item[rear] = newitem;
        }
    }

    int Dequeue()
    {
        if(isEmpty())
        {
            cout<<"The queue is empty and elements cant be removed"<<endl;
            exit(1);
            return 0;
        }
        else{
            int ret;
            ret = item[front];
            front++;
            return ret;
        }
    }

    void Traverse()
    {
        int i;
        for(i=0;i<=rear;i++)
        {
            cout<<item[i]<<endl;

        }
    }

};
int main()
{
    int choice, newitem, ret;
    Queue q;
    cout<<"*********QUEUE**********"<<endl;
    cout<<"Enter 1. for Enqueue"<<endl;
    cout<<"Enter 2. for Dequeue"<<endl;
    cout<<"Enter 3. for Traverse"<<endl;
    while(1)
    {
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter item to be entered.."<<endl;
            cin>>newitem;
            q.Enqueue(newitem);
            break;
        
        case 2:
            cout<<"Dequeue operation is being used"<<endl;
            ret = q.Dequeue();
            cout<<"The item removed from the queue is: "<<ret<<endl;
            break;

        case 3:
            cout<<"The queue is:"<<endl;
            q.Traverse();
            break;

        default:
            break;
        }
    }
}


// *********QUEUE**********
// Enter 1. for Enqueue
// Enter 2. for Dequeue
// Enter 3. for Traverse
// 1
// Enter item to be entered..
// 34
// 1
// Enter item to be entered..
// 45
// 1
// Enter item to be entered..
// 56
// 1
//Enter item to be entered..
//67
//2
//Dequeue operation is being used
//The item removed from the queue is: 34
//3
//The queue is:
//45
//56
//67