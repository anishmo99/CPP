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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k == 0)
            return head;
        
        auto *cur = head;
        int len = 1;
        
        while(cur->next){
            cur = cur->next;
            len++;
        }
        
        k = len - k % len;
        cur->next = head;
        
        while(k--){
            cur = cur->next;
        }
        
        head = cur->next;
        cur->next = nullptr;
        
        return head;
    }
};