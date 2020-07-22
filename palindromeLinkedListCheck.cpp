// leetcode

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast and fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode *node = nullptr;
    ListNode *nxt;
    while (slow)
    {
      nxt = slow->next;
      slow->next = node;
      node = slow;
      slow = nxt;
    }

    while (node)
    {
      if (node->val != head->val)
        return false;
      // cout << node->val << ". ";
      // cout << head->val << "/ ";
      node = node->next;
      head = head->next;
    }
    return true;
  }
};

// gfg

#include <iostream>
#include <stack>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool isPalindrome(Node *head)
{
    Node *temp=head;
    stack <int> s;
    while(temp!=NULL)
    {
        s.push(temp->data);
        temp=temp->next;
    }
    while(head!=NULL)
    {
        int i=s.top();
        s.pop();
        if(i!=head->data)
            return false;
        head=head->next;
    }
    return true;
}