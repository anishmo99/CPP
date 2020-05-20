#include <iostream>
using namespace std;

struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};


// Compare two strings represented as linked lists
int compare(struct Node*list1,struct Node*list2)
{
    if(list1 == NULL && list2 == NULL) return 0;
    if(list1 == NULL) return -1;
    if(list2 == NULL) return 1;
    if(list1->c < list2->c) return -1;
    else if(list1->c > list2->c) return 1;
    else return compare(list1->next,list2->next);
}