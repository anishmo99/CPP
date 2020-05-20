#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};

Node* mergeSort(Node* head) {
  vector<int>v;
  Node *temp=head;
  while(temp!=NULL)
  {
      v.push_back(temp->data);
      temp=temp->next;
  }
  sort(v.begin(),v.end());
  temp=head;
  int i=0;
  while(temp!=NULL)
  {
      temp->data=v[i++];
      temp=temp->next;
  }
  return head;
}