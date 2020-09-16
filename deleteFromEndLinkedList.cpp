#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void deleteFromEnd(struct node *head)
{
    if (!head)
        return;

    struct node *cur = head, *prev;
    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct node *head = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &head->data);

    struct node *ptr = head;
    for (int i = 0; i < n - 1; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &temp->data);
        ptr->next = temp;
        ptr = temp;
    }

    int x;
    scanf("%d", &x);

    while (x--)
    {
        deleteFromEnd(head);
    }

    while (head->next)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("%d", head->data);

    return 0;
}