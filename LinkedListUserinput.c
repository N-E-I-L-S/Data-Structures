#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main()
{
    struct Node* head = (struct Node*) malloc(sizeof(struct Node*));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node*));
    struct Node* third = (struct Node*) malloc(sizeof(struct Node*));

    head->next= second;
    second->next= third;
    third->next=NULL;

    struct Node* p;
    for(p=head; p!=NULL; p=p->next)
        scanf("%d", &(p->data));
    return 0;
}