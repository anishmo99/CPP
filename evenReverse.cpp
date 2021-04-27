/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr, *cur = head, *next = nullptr;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;

    return head;
}

ListNode *Solution::solve(ListNode *head)
{
    if (!head or !head->next)
        return head;

    ListNode *odd, *even, *oddhead, *evenhead;

    odd = head;
    oddhead = odd;
    even = head->next;
    evenhead = even;
    ListNode *cur = even->next;

    int count = 0;

    while (cur)
    {
        if (count % 2 == 0)
        {
            odd->next = cur;
            odd = odd->next;
        }
        else
        {
            even->next = cur;
            even = even->next;
        }
        cur = cur->next;
        count++;
    }

    if (even)
        even->next = nullptr;

    if (odd)
        odd->next = nullptr;

    ListNode *revhead = reverse(evenhead);

    head = oddhead;
    cur = oddhead;

    count = 0;

    while (cur)
    {
        if (count % 2 == 0)
        {
            oddhead = oddhead->next;
            cur->next = revhead;
            cur = cur->next;
        }
        else
        {
            revhead = revhead->next;
            cur->next = oddhead;
            cur = cur->next;
        }
        count++;
    }
    return head;
}