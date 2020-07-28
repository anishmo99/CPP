//
//  binaryTree.cpp
//  AnishC++
//
//  Created by Anish Mookherjee on 01/11/19.
//  Copyright © 2019 Anish Mookherjee. All rights reserved.
//

#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*tree;
void createTree(struct node* tree)
{
    tree=NULL;
}
struct node* searchElement(struct node *tree,int val)
{
    if(tree->data==val||tree==NULL)
        return tree;
    else if(val<tree->data)
        return searchElement(tree->left, val);
    else
        return searchElement(tree->right, val);
}
struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if(tree==NULL)
    {
       tree=ptr;
       tree->left=NULL;
       tree->right=NULL;
        
    }
    else
    {
        parentptr=NULL;
        nodeptr=tree;
        while(nodeptr!=NULL)
        {
       parentptr=nodeptr;
       if(val<nodeptr->data)
              nodeptr=nodeptr->left;
       else
              nodeptr = nodeptr->right;
            
        }
        if(val<parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
        
    }
    return tree;
}
void preorder(struct node* tree)
{
    if(tree!=NULL)
    {
        cout<<tree->data<<" ";
        preorder(tree->left);
        preorder(tree->right);
    }
}
void inorder(struct node* tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        cout<<tree->data<<" ";
        inorder(tree->right);
    }
}
void postorder(struct node* tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        cout<<tree->data<<" ";
    }
}
struct node* largest(struct node* tree)
{
    if(tree==NULL||tree->right==NULL)
        return tree;
    else
        return largest(tree->right);
}
struct node* smallest(struct node* tree)
{
    if(tree==NULL||tree->left==NULL)
        return tree;
    else
        return smallest(tree->left);
}
struct node *deleteElement(struct node *tree, int val)
{
       struct node *cur, *parent, *suc, *psuc, *ptr;
       if(tree->left==NULL)
       {
              printf("\nThe tree is empty ");
              return(tree);
       }
       parent = tree;
       cur = tree->left;
       while(cur!=NULL && val!= cur->data)
       {
              parent = cur;
              cur = (val<cur->data)? cur->left:cur->right;
       }
       if(cur == NULL)
       {
              printf("\nThe value to be deleted is not present in the tree");
              return(tree);
       }
       if(cur->left == NULL)
              ptr = cur->right;
       else if(cur->right == NULL)
           ptr = cur->left;
       else
       {
           // Find the in–order successor and its parent
           psuc = cur;
           cur = cur->left;
           while(suc->left!=NULL)
           {
               psuc = suc;
               suc = suc->left;
           }
           if(cur==psuc)
           {
               // Situation 1
               suc->left = cur->right;
           }
           else
           {
               // Situation 2
               suc->left = cur->left;
               psuc->left = suc->right;
               suc->right = cur->right;
           }
           ptr = suc;
       }
       // Attach ptr to the parent node
       if(parent->left == cur)
              parent->left=ptr;
       else
              parent->right=ptr;
       free(cur);
       return tree;
}
int height(struct node* tree)
{
    int lh,rh;
    if(tree==NULL)
    {
        return 0;
    }
    else
    {
        lh=height(tree->left);
        rh=height(tree->right);
        if(lh>rh)
            return lh+1;
        else
            return rh+1;
    }
}
int totalNodes(struct node* tree)
{
    if(tree==NULL)
        return 0;
    else
        return totalNodes(tree->left)+totalNodes(tree->right)+1;
}
int internalNodes(struct node* tree)
{
    if(tree==NULL)
        return 0;
    else if(tree->left==NULL&&tree->right==NULL)
        return 0;
    else
        return internalNodes(tree->left)+internalNodes(tree->right)+1;
}
int externalNodes(struct node* tree)
{
    if(tree==NULL)
        return 0;
    else if(tree->left==NULL&&tree->right==NULL)
        return 1;
    else
        return externalNodes(tree->left)+externalNodes(tree->right);
}
void deleteTree(struct node* tree)
{
    if(tree!=NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}
int main()
{
    int option,val;
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    createTree(tree);
    do
    {
        cout<<"1.INSERT ELEMENT"<<endl;
        cout<<"2.SEARCH ELEMENT"<<endl;
        cout<<"3.SMALLEST ELEMENT"<<endl;
        cout<<"4.LARGEST ELEMENT"<<endl;
        cout<<"5.DELETE ELEMENT"<<endl;
        cout<<"6.HEIGHT"<<endl;
        cout<<"7.TOTAL NODES"<<endl;
        cout<<"8.TOTAL INTERNAL NODES"<<endl;
        cout<<"9.TOTAL EXTERNAL NODES"<<endl;
        cout<<"10.DELETE TREE"<<endl;
        cout<<"11.PRE-ORDER TRAVERSAL"<<endl;
        cout<<"12.IN-ORDER TRAVERSAL"<<endl;
        cout<<"13.POST-ORDER TRAVERSAL"<<endl;
        cout<<"14.EXIT"<<endl;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Insert the element you want to enter:"<<endl;
                cin>>val;
                tree=insertElement(tree, val);
                break;
            case 2:
                cout<<"Enter element you want to search:"<<endl;
                cin>>val;
                if(searchElement(tree, val)==NULL)
                    cout<<"Element not found"<<endl;
                else
                    cout<<"Element found"<<endl;
                break;
            case 3:
                ptr=smallest(tree);
                cout<<"The smallest element is: "<<ptr->data<<endl;
                break;
            case 4:
                ptr=largest(tree);
                cout<<"The largest element is: "<<ptr->data<<endl;
                break;
            case 5:
                cout<<"Enter the element to be deleted"<<endl;
                cin>>val;
                tree=deleteElement(tree, val);
                if(tree==NULL)
                    cout<<"Element not found"<<endl;
                else
                    cout<<"Element deleted"<<endl;
                break;
            case 6:
                cout<<"Height of the tree is: "<<height(tree)<<endl;
                break;
            case 7:
                cout<<"Total no. of nodes present are: "<<totalNodes(tree)<<endl;
                break;
            case 8:
                cout<<"Total no. of internal nodes are: "<<internalNodes(tree)<<endl;
                break;
            case 9:
                cout<<"Total no. of external nodes are: "<<externalNodes(tree)<<endl;
                break;
            case 10:
                cout<<"Deleting the entire tree."<<endl;
                deleteTree(tree);
                break;
            case 11:
                cout<<"Pre-order traversal:"<<endl;
                preorder(tree);
                cout<<endl;
                break;
            case 12:
                cout<<"In-order traversal:"<<endl;
                inorder(tree);
                cout<<endl;
                break;
            case 13:
                cout<<"Post-order traversal:"<<endl;
                postorder(tree);
                cout<<endl;
                break;
            case 14:
                cout<<"EXIT"<<endl;
                break;
            default:
                cout<<"Wrong choice, enter again."<<endl;
        }
    }while(option!=14);
    return 0;
}
