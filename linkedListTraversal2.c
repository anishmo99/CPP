//
//  LinkedListTraversal2.c
//  AnishC++
//
//  Created by Anish Mookherjee on 12/10/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <stdio.h>
struct node
{
    int data;
    struct node *next;
}*head, *tail;

//void createNode();
//void display();

void createNode(int value)
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
        tail=new;
    }
    else
    {
        tail->next=new;
        tail=new;
    }
}
void display()
{
    printf("Displaying the current LinkedList\n");
    struct node *temp;
    if(head==NULL)
        printf("List Empty");
    else
    {
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    }
}
int Search(int search)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==search)
            return 1;
        else
            temp=temp->next;
    }
    return 0;
}
void InsertBeg(int value)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=head;
    head=temp;
}
void InsertPos(int value)
{
    struct node *temp, *cur=head, *prev;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    int pos;
    printf("enter the position where you want to enter: \n");
    scanf("%d",&pos);
    for(int i=0;i<pos;i++)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=temp;
    temp->next=cur;
}
void InsertEnd(int value)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    tail->next=temp;
    tail=temp;
}
void deleteBeg()
{
    head=head->next;
}
void deletePos()
{
    int pos;
    printf("Enter the position from where you want to delete the element.\n");
    scanf("%d",&pos);
    struct node *cur=head, *prev;
    for(int i=0;i<pos;i++)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    cur->next=NULL;
}
void deleteEnd()
{
    struct node *cur=head, *prev;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    tail=prev;
    
}
int main()
{
    int n = 0;
    printf("Enter the no. of nodes you want in the list : \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int value=0;
        printf("Enter the value for %d node : ",(i+1));
        scanf("%d",&value);
        createNode(value);
    }
    display();
    int x;
    do
    {
        int value;
        printf("Enter 0 to EXIT\nEnter 1 to InsertAtBeginning\nEnter 2 to InsertAtPosition\nEnter 3 to InsertAtEnd\nEnter 4 to DeleteAtBeginning\nEnter 5 to DeleteAtPosition\nEnter 6 to DeleteEnd\nEnter 7 to Search\n");
        scanf("%d",&x);
        switch(x)
      {
          case 1 :
          {
              printf("Enter the value you want to enter.\n");
              scanf("%d",&value);
              InsertBeg(value);
              display();
          }
              break;
          case 2 :
          {
              printf("Enter the value you want to enter.\n");
              scanf("%d",&value);
              InsertPos(value);
              display();
          }
              break;
          case 3 :
          {
              printf("Enter the value you want to enter.\n");
              scanf("%d",&value);
              InsertEnd(value);
              display();
          }
              break;
          case 4 :
          {
              deleteBeg();
              display();
          }
              break;
          case 5 :
          {
              deletePos();
              display();
          }
              break;
          case 6 :
          {
              deleteEnd();
              display();
          }
              break;
          case 7 :
          {
              printf("Enter the element you want to search : ");
              int search;
              scanf("%d",&search);
              if(Search(search)==1)
                  printf("Found\n");
              else
                  printf("Not Found\n");
          }
              break;
          default : printf("EXIT.\n");
      }
    }while(x!=0);
    return 0;
}
