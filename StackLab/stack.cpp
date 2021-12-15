#include<iostream>
#define MAXSIZE 10
using namespace std;

class Stack{
public:
    int Top;
    int arr[MAXSIZE];

    Stack()
    {
        Top = -1;
        for(int i=0;i<MAXSIZE-1;i++)
        {
            arr[i]=0;
        }
    }

    bool isEmpty();
    bool isFull();
    void Insertion(int var);
    int Deletion();
    void Traverse();
    void Update(int pos, int item);
};

bool Stack::isEmpty(){
    if(Top == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

bool Stack::isFull(){
    if(Top >= MAXSIZE - 1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void Stack::Insertion(int var){
    if(isFull())
    {
        cout<<"The stack is full, insertion operation can't be performed"<<endl;
    }
    else{
        Top++;
        arr[Top] = var;
    }
}

int Stack::Deletion()
{
    if(isEmpty())
    {
        cout<<"The stack is empty and deletion operation cant proceed"<<endl;
    }
    else{
        Top--;
        return arr[Top];
    }
}

void Stack::Traverse()
{
    int i;
    cout<<"The stack looks like: "<<endl;
    for(i=MAXSIZE-1;i<=0;i--)
    {
        cout<<arr[i]<<"\n";
    }
}

void Stack::Update(int pos, int item)
{
    if(pos>=0 && pos<=MAXSIZE-1)
    {
        arr[pos] = item;
    }
    else{
        cout<<"The position entered is invalid"<<endl;
    }
}

void Merge(Stack s1, Stack s2)
{
    int mergedArr[20];
    int i , j, k;
    for(i=0;i<MAXSIZE-1;i++)
    {
        mergedArr[i] = s1.arr[i];
    }
    for(j=0;j<MAXSIZE-1;j++)
    {
        mergedArr[j+10] = s2.arr[j];
    }
    cout<<"The merged Stack looks like: "<<endl;
    for(k=0;k<20;k++)
    {
        cout<<mergedArr[k]<<"\n";
    }
}

int main()
{
    int choice, ins, pos, val;
    Stack s1, s2;
    cout<<"**********Static Stack Operations************"<<endl;
    cout<<"1. Insertion"<<endl;
    cout<<"2. Deletion"<<endl;
    cout<<"3. Traverse"<<endl;
    cout<<"4. Update"<<endl;
    cout<<"5. Merge"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;

    while(1)
    {
        switch(choice)
        {
            case 1:
                cout<<"Enter the item you want to enter in the stack"<<endl;
                cin>>ins;
                s1.Insertion(ins);
                break;
            
            case 2:
                cout<<"The item is popped"<<endl;
                s1.Deletion();
                break;

            case 3:
                s1.Traverse();
                break;

            case 4:
                cout<<"Enter the postion in which you want to update the stack?"<<endl;
                cin>>pos;
                cout<<"Enter the value to be updated with.."<<endl;
                cin>>val;
                s1.Update(pos, val);
                break;

            case 5:
                Merge(s1, s2);
                break;
        }
    }
}