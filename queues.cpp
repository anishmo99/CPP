//
//  Queues.cpp
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
}*newNode, *front, *rear, *temp;
int size=0;
void enqueue(int value)
{
    size++;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    if(rear==NULL)
    {
        front=newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}
void dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue Underflow"<<endl;
    }
    else
    {
        cout<<"Dequeued Element : "<<front->data<<endl;
        size--;
        temp=front;
        front=front->next;
        temp->next=NULL;
    }
}
void display()
{
    cout<<"Displaying Queue"<<endl;
    if(front==NULL)
        cout<<"Queue Empty"<<endl;
    else
    {
        temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
}
void Size()
{
    cout<<"Size of the queue is : "<<size<<endl;
}
int main()
{
    int value,x;
    do
    {
        cout<<"1) Enqueue"<<endl;
        cout<<"2) Dequeue"<<endl;
        cout<<"3) Display Queue"<<endl;
        cout<<"4) Size of Queue"<<endl;
        cout<<"5) Exit"<<endl;
        cin>>x;
        switch(x)
        {
            case 1 : cout<<"Enter the value you want to enqueue."<<endl;
                cin>>value;
                enqueue(value);
                break;
            case 2 : dequeue();
                break;
            case 3 : display();
                break;
            case 4 : Size();
                break;
            case 5 : cout<<"EXIT."<<endl;
                break;
            default : cout<<"Invalid Choice"<<endl;
        }
    }while(x!=5);
    return 0;
}
