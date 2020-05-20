//
//  harmeetArray.c
//  AnishC++
//
//  Created by Anish Mookherjee on 04/11/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <stdio.h>
int main(){
    int i,j,n,m,t;
    scanf("%d %d",&n,&m);
    int a[n],b[m],c[n+m];
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (j=0;j<m;j++){
        scanf("%d",&b[j]);
    }
    for(i=0;i<n;i++)
    {
        c[i]=a[i];
        //printf("%d\n",c[i]);
    }
    for(i=0;i<m;i++)
    {
        c[n]=b[i];
        //printf("%d\n",c[n]);
        n++;
    }
    for(i=0;i<n+m;i++){
        for(j=i+1;j<n+m;j++){
            if(c[i]>c[j]){
                t=c[i];
                c[i]=c[j];
                c[j]=t;
            }
        }
    }
    for(i=0;i<n+m;i++)
    {
        printf("%d\n",c[i]);
    }
    return 0;
}
    


LINKED LIST:
#include <stdio.h>
struct node{
    int data;
    struct node *link;
};
struct node *root=NULL;
void create(int value){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        struct node *p;
        p=root;
        while (p->link!=NULL) {
            p=p->link;
        }
        p->link=temp;
    }
}
void display(){
    struct node *t;
    t=root;
    if(t==NULL){
        printf("list is empty\n");
    }
    else{
    while(t!=NULL){
        printf("%d->",t->data);
        t=t->link;
    }
    }
}
int SEARCH(int search){
    struct node *temp;
    temp=root;
    while(temp!=NULL){
        if(temp->data==search)
            return 1;
        else
            return temp=temp->link;
    }
    return 0;
}
void insertbeg(int value){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=root;
    root =temp;
    }
void insertpos(int value){
    struct node *temp,*curr,*prev;
    curr=root;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    printf("enter the position");
    int pos;
    scanf("%d",&pos);
    if(root==NULL){
        root=temp;
    }
    else{
        int i;
        for(i=0;i<pos;i++){
            prev=curr;
            curr=curr->link;
        }
        temp->link=curr;
        prev->link=temp;
    }
}
void insertend(int value){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        struct node *p;
        p=root;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=temp;
    }
}
void deletebeg(){
    if(root==NULL){
        printf("list is empty\n");
    }
    else{
        struct node *temp;
        temp=root;
        root=root->link;
        temp->link=NULL;
        //free (temp);
    }
}
void deletepos(){
    struct node *temp1=root,*temp2;
    printf("enter the position from where you wnt to delet the element");
    int pos,i;
    scanf("%d",&pos);
    for(i=0;i<pos;i++){
        temp2=temp1;
        temp1=temp1->link;
    }
    temp2->link=temp1->link;
    temp1->link=NULL;
}
void deletend(){
    struct node *temp1=root,*temp2;
    //temp=(struct node*)malloc(sizeo)
    while(temp1->link!=NULL){
        temp2=temp1;
        temp1=temp1->link;
    }
    temp2->link=NULL;
}
int main(){
    int n=0,i;
    printf("enter the nodes you want in the list:");
   // int n;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        int value=0;
        printf("enter valus for %d node: ",i+1);
        scanf("%d",&value);
        create(value);
    }
    display();
    int x;
    do{
        int value;
        printf("1 insert at begin\n2 insert at position\n3 insert at end\n4 delete at beginning\n5 delete at position\n6 delete at end\n7 Search\n8 exit\n");
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("enter the value");
                scanf("%d",&value);
                insertbeg(value);
                display();
                break;
            case 2:
                printf("enttre the value:");
                scanf("%d",&value);
                insertpos(value);
                display();
                break;
            case 3:
                printf("enter the value:");
                scanf("%d",&value);
                insertend(value);
                          display();
                break;
            case 4:
                deletebeg();
                display();
                break;
            case 5:
                deletepos();
                display();
                break;
            case 6:
                deletend();
                display();
                break;
            case 7:
                //int value;
                printf("enter the element you want to search\n");
                scanf("%d",&value);
                if(SEARCH(value)==NULL)
                    printf("FOUND\n");
                    else
                        printf("NOT FOUND\n");
                break;
            default:
                printf("EXIT\n");
                
        }
    }while(x!=8);
    return 0;
}

STACK USING LINKED LIST
#include <stdio.h>
struct node{
    int data;
    struct node *link;
}*new,*top,*temp;
int size=0;
void push(int value){
    size++;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->link=NULL;
    if(top==NULL){
        top=new;
    }
    else{
        new->link=top;
        top=new;
    }
}
void pop(){
    if(top==NULL){
        printf("stack underflow\n");
    }
    else{
        temp=top;
        printf("deleted element is %d",top->data);
        size--;
        top=top->link;
        temp->link=NULL;
    }
}
void display(){
    if(top==NULL){
        printf("stack is empty\n");
    }
    else{
        temp=top;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}
    void Size()
    {
        printf("size is %d\n",size);
    }
int main(){
    int x,value;
    do{
        printf("1 push\n2 pop\n3 display\n4 size\n5 exit\n");
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("enter the value to be pushed");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
            case 4:
                Size();
                break;
            default:
                printf("exit\n");
        }
    }while (x!=5);
    return 0;
}

SWAPPING OF NODES
#include <stdio.h>
//#include <malloc.h>
struct node{
    int data;
    struct node *link;
};
struct node *root=NULL;
void create(int n){
    int i,value;
    for (i=0;i<n;i++){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&value);
    temp->data=value;
    temp->link=NULL;
    if(root==NULL)
        root=temp;
    else{
        struct node *p;
        p=root;
        while (p->link!=NULL) {
            p=p->link;
        }
        p->link=temp;
    }
    }
}
void display(){
    struct node *temp;
    temp=root;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->link;
    }
}
void swapnodes(int x,int y){
    struct node *prevx=NULL,*currx=root,*prevy=NULL,*curry=root;
    if(x==y)
        return;
    while(currx->data!=x){
        prevx=currx;
        currx=currx->link;
    }
    while (curry->data!=y) {
        prevy=curry;
        curry=curry->link;
    }
    currx->link=curry->link;
    curry->link=currx;
    prevx->link=curry;
    }
int main(){
    int n,i;
    scanf("%d",&n);
    create(n);
    display();
    int x, y;
    scanf("%d %d",&x,&y);
    swapnodes(x,y);
    display();
    return 0;
}


#include <stdio.h>
int main(){
    int i,x[10],xl,xsl;
    for (i=0;i<5;i++){
        scanf("%d",&x[i]);
    }
    xl=x[0];
    for (i=1;i<5;i++){
        if(x[i]>xl)
        {
            xl=x[i];
        }
    }
    xsl=x[0];
    for (i=1;i<5;i++)
    {
        if(x[i]<xl && x[i]>xsl && xl>xsl)
        {
            xsl=x[i];
        }
    }
 
    printf("%d %d",xl,xsl);
    return 0;
}

