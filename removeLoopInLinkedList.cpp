struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// latest

void removeLoop(Node *head)
{
    Node *slow = head, *fast = head, *prev;
    //first detecting whether there is a loop in ll
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow; //to keep track of prev position if both pointers meet at head of ll
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow != fast) //if loop not present return;
        return;
    if (slow == head)
    {                      //if both pointers meet at start of ll
        prev->next = NULL; //with the help of prev pointer break the link
        return;
    }
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return;
}

// older

void removeTheLoop(Node *head) 
{
    Node *slow, *fast;
    slow = head->next;
    fast = head->next->next;
    while (fast && fast->next)
    {
        if (slow == fast)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else return;
}