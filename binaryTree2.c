//
//  binaryTree2.c
//  AnishC++
//
//  Created by Anish Mookherjee on 04/11/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
}*tree;
void insert(int d){
    struct node *p,*t,*curr;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=d;
    t->right=t->left=NULL;
    if(tree==NULL){
        tree=t;
        
    }
    else{
        curr=tree;
        while(curr){
            p=curr;
            if(t->data<curr->data){
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        if(t->data<p->data){
            p->left=t;
        }
        else{
            p->right=t;
        }
    }
}
struct node *search(struct node *tree,int value){
    if(tree->data==value || tree==NULL)
        return tree;
    else{
        if(value<tree->data){
            return search(tree->left,value);
        }
        else
             return search(tree->right,value);
    }
}
void preordert(struct node *tree)
{
    if(tree!=NULL)
    {
    printf("%d",tree->data);
    preordert(tree->left);
    preordert(tree->right);
    }
}
void inorder(struct node *tree)
{
    if(tree!=NULL){
        inorder(tree->left);
        printf("%d",tree->data);
        inorder(tree->right);
    }
}
void postordert(struct node *tree){
    if(tree!=NULL){
        postordert(tree->left);
        postordert(tree->right);
        printf("%d",tree->data);
        }
}
int height(struct node *tree){
    int leftheight,rightheight;
    if(tree==NULL){
        return 0;
    }
    else{
        leftheight=height(tree->left);
        rightheight=height(tree->right);
        if(leftheight>rightheight)
            return leftheight+1;
        else
            return rightheight+1;
    }
}
int totalnodes(struct node *tree){
    if (tree==NULL)
        return 0;
    else{
        return (totalnodes(tree->left)+totalnodes(tree->right)+1);
    }
}
int externalnodes(struct node *tree){
    if(tree==NULL)
        return 0;
    else if(tree->left==NULL && tree->right==NULL){
        return 1;
    }
    else
        return (externalnodes(tree->left)+externalnodes(tree->right));
}
int internalnodes(struct node *tree){
    if(tree==NULL || (tree->left==NULL && tree->right==NULL))
    {
        return 0;
    }
    else{
        return internalnodes(tree->left)+internalnodes(tree->right)+1;
    }
}
void deletetree(struct node *tree){
    if(tree!=NULL){
        deletetree(tree->left);
        deletetree(tree->right);
        free(tree);
    }
}
struct node *largest(struct node *tree){
    if(tree==NULL || tree->right==NULL)
        return tree;
    else
        return largest(tree->right);
}
struct node *smallest(struct node *tree){
    if(tree==NULL || tree->left==NULL)
        return tree;
    else
        return smallest(tree->left);
    }
int main(){
    int option,value;
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    do{
        printf("1 Insert element\n");
        printf("2 Search element\n");
        printf("3 Height\n");
        printf("4 Total nodes\n");
        printf("5 External nodes\n");
        printf("6 Internal nodes\n");
        printf("7 Delete tree\n");
        printf("8 preorder \n");
        printf("9 inorder\n");
        printf("10 postorder\n");
        printf("11 largest\n");
        printf("12 smallest\n");
        printf("13 exit\n");
        scanf("%d",&option);
        switch (option) {
            case 1:
                printf("enter the element");
                scanf("%d",&value);
                insert(value);
                break;
            case 2:
                printf("enter the element you wnt to search");
                scanf("%d",&value);
                if(search(tree,value)==NULL)
                    printf("NOT FOUND\n");
                else
                        printf("FOUND\n");
                break;
            case 3:
                printf("height of the tree:%d\n",height(tree));
                break;
            case 4:
                printf("total nodes: %d\n",totalnodes(tree));
                break;
            case 5:
                printf("external nodes: %d\n",externalnodes(tree));
                break;
            case 6:
                printf("internal nodes: %d\n",internalnodes(tree));
                break;
            case 7:
                printf("delete tree:\n");
                deletetree(tree);
                break;
            case 8:
                printf("preorder:\n");
                preordert(tree);
                break;
            case 9:
                printf("inorder:\n");
                inorder(tree);
                break;
            case 10:
                printf("postorder:\n");
                postordert(tree);
                break;
            case 11:
                p=largest(tree);
                printf("largest element is:%d\n",p->data);
                break;
            case 12:
                p=smallest(tree);
                printf("smallest element is:%d\n",p->data);
                break;
            default:
                printf("EXIT");
                break;
        }
    }while (option!=13);
    return 0;
}


