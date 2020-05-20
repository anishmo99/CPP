//
//  StacksArray.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 13/10/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;
int top=-1;
int size=5;
int st[5];
void push(int value)
{
    if(top==(size-1))
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        st[++top]=value;
    }
}
void pop()
{
    if(top==-1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        cout<<"Popped Element : "<<st[top--]<<endl;
    }
}
void peek()
{
    if(top==-1)
        cout<<"Stack Underflow"<<endl;
    else
        cout<<"Element at the top of stack : "<<st[top]<<endl;
}
void display()
{
    cout<<"Current Stack: "<<endl;
    if(top==-1)
        cout<<"Stack Underflow"<<endl;
    else
    {
        for(int i=top;i>=0;i--)
        {
            cout<<st[i]<<endl;
        }
    }
}
int main()
{
    int x,value;
    do
    {
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. EXIT"<<endl;
        cin>>x;
        switch(x)
        {
            case 1 :
                cout<<"enter the value you want to push : "<<endl;
                cin>>value;
                push(value);
                break;
            case 2 :
                pop();
                break;
            case 3 :
                peek();
                break;
            case 4 :
                display();
                break;
            case 5 :
                cout<<"EXIT"<<endl;
                break;
            default :
                cout<<"Invalid Choice"<<endl;
        }
    }while(x!=5);
    return 0;
}
