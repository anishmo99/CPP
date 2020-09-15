#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    struct node* next;
};

int main() {
    int n;
    cin>>n;
    
    struct node* head = (struct node*)malloc(sizeof(struct node));
    
    cin >> head->data;
    
    for(int i = 0; i < n - 1; i++){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        cin >> temp->data;
        temp->next = head;
        head = temp;
    }
    
    for(int i = 0; i < n - 1; i++){
        cout << head->data;
        cout << "->";
        head = head->next;
    }
    cout << head->data;
    return 0;
}

// input : 5 5 4 3 2 1
// output : 1->2->3->4->5