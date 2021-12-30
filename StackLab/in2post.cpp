#include<iostream>
#include<string.h>
#define MAXSIZE 20


using namespace std;

class Stack{
public:
    int top;
    char arr[MAXSIZE];
    Stack()
    {
        top = -1;
    }

    bool isFull()
    {
        if(top == MAXSIZE - 1)
        {
            return 1;
        }
        else{
            return 0;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }

    void push(char c)
    {
        if(isFull())
        {
            cout<<"The Stack is full"<<endl;
        }
        else{
            top++;
            arr[top] = c;
        }
    }

    char pop()
    {
        if(isEmpty())
        {
            cout<<"The stack is empty"<<endl;
            return '0';
        }
        else{
            char c = arr[top];
            top--;
            return c;
        }
    }

    char tos()
    {
        char c = arr[top];
        return c;
    }
};


int precedence(char c)
{
    if(c == '$')
    {
        return 3;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else{
        return -1;
    }
}

string Infix2Postfix(Stack s, string infix)
{
    string postfix;
    int i;
    for(i=0;i<infix.length();i++)
    {
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) 
        {
            postfix += infix[i];
        }
        else if(infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while((s.tos() != '(') && (!s.isEmpty()))
            {
                char temp = s.tos();
                postfix += temp;
                s.pop();                
            }
        }
        else
        {
            if(s.isEmpty())
            {
                s.push(infix[i]);
            }
            else{
                if(precedence(infix[i]) > precedence(s.tos()))
                {
                    s.push(infix[i]);
                }
                else if(precedence(infix[i]) == precedence(s.tos()) && (infix[i] == '$'))
                {
                    s.push(infix[i]);
                }
                else{
                    while((!s.isEmpty()) && (precedence(infix[i]) <= precedence(s.tos())))
                    {
                        char temp = s.tos();
                        postfix += temp;
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.isEmpty())
    {
        if(s.tos() != '(')
        {
            postfix += s.tos();
        }
        s.pop();
    }
    return postfix;
}

int main()
{
    string infix, postfix;
    cout<<"Enter a Infix Expression"<<endl;
    cin>>infix;
    Stack s;
    postfix = Infix2Postfix(s, infix);
    cout<<"PostFix Expression is: "<<postfix;
    return 0;
}

//Enter a Infix Expression
//(((a-(b+c))*d)$(e+f))
//PostFix Expression is: abc+d*ef+$-