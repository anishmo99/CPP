struct Node* reverseList(struct Node* ptr){
    struct Node *prev, *cur, *next;
    cur = ptr;
    prev = nullptr;
    next = nullptr;
    while(cur){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    ptr = prev;
    return ptr;
}

struct Node* addTwoLists(struct Node* a, struct Node* b){
    if(!a)
        return b;
    if(!b)
        return a;
    
    struct Node *A = reverseList(a); // 345 -> 543
    struct Node *B = reverseList(b); // 45 -> 54
    
    int sum = 0, carry = 0;
    sum = A -> data + B -> data;
    struct Node *ptr = new Node(sum % 10); // 0
    struct Node *head = ptr;
    
    A = A -> next; // 4
    B = B -> next; // 4
    carry = sum / 10; // 1
    
    while(A or B or carry){
        sum = (A ? A -> data : 0) + (B ? B -> data : 0) + carry; // 4 + 4 + 1 = 9
        
        struct Node *temp = new Node(sum % 10); // 9
        carry = sum / 10;  // 0
        
        ptr -> next = temp; 
        ptr = ptr -> next;
        
        if(A) // nullptr
            A = A -> next;
        if(B) 
            B = B -> next;
    }
    return reverseList(head);
}