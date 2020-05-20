//HARMEET'S CODE
#include <stdio.h>
#include <stdlib.h>
int count=0;
struct node{
    int data;
    struct node *link;
}*new,*front,*rear,*temp;
void enqueue(int value)
{
    count++;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->link=NULL;
    if(rear==NULL)
    {
        rear=new;
        front=new;
    }
    else
    {
        rear->link=new;
        rear=rear->link;
        rear->link=front;
    }
}
void dequeue(){
    count--;
    if(front==rear)
    {
        int ele;
        ele=front->data;
        printf("dequeued element is:%d",ele);
        front=NULL;
        rear=NULL;
    }
    else{
        temp=front;
        front=front->link;
        rear->link=front;
        temp->link=NULL;
        free(temp);
    }
}
void display(){
    if(rear==NULL)
    {
        printf("queue is empty");
    }
    else{
        temp=front;
        while(temp->link!=front)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("%d\n ",temp->data);
        }
}
void size(){
    printf("SIZE: %d\n",count);
}
int main(){
    int x,value;
    do{
    printf("1 ENQUEU\n2 dequeue\n3 display\n4 size\n5 exit\n");
    printf("enter the option");
    scanf("%d",&x);
        switch(x){
            case 1:
                printf("enter any value");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                size();
                break;
            case 5:
                printf("exit\n");
                break;
            default:
                printf("invalid option\n");
        }

        
    }while(x!=5);
    return 0;
}
/*
 //FROM INTERNET
 //  CircularQueue.c
 //  AnishC++
 //
 //  Created by Anish Mookherjee on 14/10/19.
 //  Copyright © 2019 Anish Mookherjee. All rights reserved.
 //
 
 #include<stdio.h>
 #include<stdlib.h>
 #define que struct queue
 #define pf printf
 #define sf scanf
 struct queue{
 int info;
 struct queue *link;
 };
 que *front=NULL,*rear=NULL;
 int count=0;
 void push(int n)
 {
 que *newnode;
 newnode=(struct queue*)malloc(sizeof(struct queue));
 newnode->info=n;
 newnode->link=NULL;
 if(count==0)
 front=newnode;
 else
 rear->link=newnode;
 rear=newnode;
 rear->link=front;
 count++;
 }
 int pop(void)
 {
 int n;
 que *temp;
 if(count==0)
 return (-1);
 count--;
 if(front==rear)
 {
 n=front->info;
 free(front);
 front=NULL;
 rear=NULL;
 }else
 {
 temp= front ;
 n = temp-> info ;
 front = front -> link ;
 rear -> link = front ;
 free ( temp ) ;
 }
 return n;
 }
 void display(void)
 {
 que *temp;
 int i;
 if(count==0)
 pf("Empty");
 else
 {
 temp=front;
 for(i=0;i<count;i++)
 {
 pf("%d ",temp->info);
 temp=temp->link;
 }
 }
 pf("\n");
 }
 int size(void)
 {
 return count;
 }
 int main()
 {
 int n,ch=10;
 while(ch!=0)
 {
 pf("\n       What do you want to do??\n");
 pf("1.Push\n");
 pf("2.Pop\n");
 pf("3.SizeOfQueue\n");
 pf("4.Display\n");
 pf("0.EXIT\n");
 sf("%d",&ch);
 switch(ch)
 {
 case 1:
 {
 pf("What no. do you want to push in queue\n");
 sf("%d",&n);
 push(n);
 break;
 }
 case 2:
 {
 n=pop();
 if(n==-1)
 pf("Queue is empty\n");
 else
 pf("Number poped from queue is %d\n",n);
 break;
 }
 case 3:
 {
 n=size();
 pf("Size of queue is %d\n",n);
 break;
 }
 case 4:
 {
 pf("Queue is -->> ");
 display();
 }
 case 0:
 break;
 default:
 pf("Wrong Choice\n");
 break;
 }
 }
 */
