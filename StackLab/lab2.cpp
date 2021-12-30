#include<iostream>
#define MAXSIZE 10

using namespace std;

class Stack{
public:
    int Top;
    int Arr[MAXSIZE];

    Stack()
    {
        Top = -1;
        for(int i=0;i<MAXSIZE-1;i++)
        {
            Arr[i] = 0;
        }
        cout<<"the constructor is running"<<endl;
    }
    bool isFull();
    bool isEmpty();
    void Push(int value);
    int Pop();
};

bool Stack::isFull()
{
    if(Top == MAXSIZE-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

bool Stack::isEmpty()
{
    if(Top == -1)
    {
        return 1;
    }
    else
    return 0;
}

void Stack::Push(int value){
    if(isFull() == 1)
    {
        cout<<"The stack is full and items cant be pushed"<<endl;
    }
    else{
        Top++;
        Arr[Top] = value;
    }
}

int Stack::Pop()
{
    if(isEmpty() == 1)
    {
        cout<<"The stack is empty and stack is not popped"<<endl;
        return 0;
    }
    else{
        int item = Arr[Top];
        Top--;
        return item;
    }
}

void Traverse(Stack s)
{
    int i;
    cout<<"The Stack looks like..."<<endl;
    for(i=s.Top;i>=0;i--)
    {
        cout<<s.Arr[i]<<"\n";
    }
}

int main()
{
    int choice, value, user;
    Stack s1;
    cout<<"********Stack*********"<<endl;
    cout<<"Enter 1 for Push"<<endl;
    cout<<"Enter 2 for Pop"<<endl;
    cout<<"Enter 3 for Traverse"<<endl;
    cin>>choice;
    while(1)
    {
        cout<<"Enter choice item"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter value to be entered"<<endl;
                cin>>value;
                s1.Push(value);
                break;

            case 2:
                s1.Pop();
                break;

            case 3:
                Traverse(s1);
                break;

            default:
                cout<<"The entered value is invalid"<<endl;
                break;
        }
    }
}

//********Stack*********    
//Enter 1 for Push
//Enter 2 for Pop
//Enter 3 for Traverse      
//1
//Enter choice item
//34
//The entered value is invalid
//Enter choice item
//1
//Enter value to be entered
//34
//Enter choice item
//1
//Enter value to be entered
//34
//Enter choice item
//1
//Enter value to be entered
//34
//Enter choice item
//1
//Enter value to be entered
//34
//Enter choice item
//2
//Enter choice item
//3
//The Stack looks like...
//34
//34
//34