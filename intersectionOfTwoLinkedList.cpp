void intersection(Node **head1, Node **head2,Node **head3)
{
    Node *temp1=*head1,*temp2=*head2;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->val==temp2->val)
        {
            push(head3,temp1->val);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->val<temp2->val)
            temp1=temp1->next;
        else //(temp2->val<temp1->val)
            temp2=temp2->next;
    }
}