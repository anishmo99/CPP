//
//  Stacks.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 13/10/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *newNode, *top, *temp;
int size=0;
//class Stacks
//{
//public:
    void push(int value)
    {
        size++;
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=value;
        if(top==NULL)
        {
            newNode->next=NULL;
            top=newNode;
        ;
        }
        else
        {
            newNode->next=top;
            top=newNode;
        }
    }
    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            cout<<"Popped Element is : "<<top->data<<endl;
            size--;
            temp=top;
            top=top->next;
            temp->next=NULL;
        }
    }
    void display()
    {
        cout<<"Displaying Stack"<<endl;
        if(top==NULL)
        {
            cout<<"Stack Empty"<<endl;
        }
        else
        {
            temp=top;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }
void Size()
{
    cout<<"Size of the Stack is : "<<size<<endl;
}
//};
int main()
{
    int value,x;
    do
    {
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Display size of stack"<<endl;
    cout<<"5) Exit"<<endl;
    cin>>x;
        switch(x)
        {
            case 1 : cout<<"Enter value to be pushed."<<endl;
                cin>>value;
                push(value);
                //display();
                break;
            case 2 : pop();
                //display();
                break;
            case 3 : display();
                break;
            case 4 : Size();
                break;
            case 5 : cout<<"Exit"<<endl;
                break;
            default : cout<<"Invalid Choice"<<endl;
        }
    }while(x!=5);
}
