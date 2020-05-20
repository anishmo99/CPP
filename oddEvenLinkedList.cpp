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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int>odd,even;
        ListNode* temp=head;
        while(temp)
        {
            odd.push_back(temp->val);
            if(temp->next!=NULL)
            {
                temp=temp->next;
                even.push_back(temp->val);
            }
            temp=temp->next;
        }
        temp=head;
        for(auto& i:odd)
        {
            temp->val=i;
            temp=temp->next;
        }
        for(auto& i:even)
        {
            temp->val=i;
            temp=temp->next;
        }
        return head;
    }
};
