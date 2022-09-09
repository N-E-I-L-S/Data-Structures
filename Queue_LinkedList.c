#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *r = NULL;
struct Node *f = NULL;

void Enqueue(int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n != NULL)
    {
        n->next = NULL;
        n->data = x;
        if (f == NULL)
            r = f = n;
        else
        {
            r->next = n;
            r = n;
        }
    }
    else
        printf("Queue is Full");
}

void Dequeue()
{
    f=f->next;
}

void Traversal(struct Node *ptr)
{
    printf("All  Elements are:\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    Enqueue(4);
    Enqueue(5);
    Enqueue(6);
    Dequeue();
    Traversal(f);
    return 0;
}