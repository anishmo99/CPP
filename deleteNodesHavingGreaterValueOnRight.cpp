Node *compute(Node *head)
{
    while(head->next->data>head->data&&head->next!=NULL)
    {
        head=head->next;
    }
    
    if(head->next!=NULL&&head->next->next!=NULL)
    Node *cur_prev=head,*cur=head->next,*cur_next=cur->next;
        
    while(cur_prev!=NULL&&cur!=NULL&&cur_next!=NULL)
    {
        if(cur->data>cur_next->data)
        {
            cur_prev->next=cur->next;
            cur->next=NULL;
            cur=cur_next;
        }
        else
        {
            cur_prev=cur;
            cur=cur_next;
        }
        cur_next=cur_next->next;
    }
    return head;
}