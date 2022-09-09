#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void Traversal(struct Node* ptr)
{
    printf("All elements are:\n");
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr= ptr->next;
    }
}

struct Node* InsertStart(struct Node* head, int data)
{
    struct Node* newhead = (struct Node*)malloc (sizeof(struct Node*));
    newhead->next= head;
    newhead-> data =data;
    return newhead;
}

struct Node* InsertEnd(struct Node* last, int data)
{
    struct Node* newlast = (struct Node*)malloc (sizeof(struct Node*));
    last->next= newlast;
    newlast->data=data;
    newlast->next =NULL;
    return newlast;
}

void InsertIndex(struct Node* head, int data, int index)
{
    struct Node* ptr = (struct Node* )malloc (sizeof(struct NNode*));
    struct Node* p= head;
    int i=0;
    while(i<index-1)
    {
        p= p->next;
        i++;
    }
    ptr->data =data;
    ptr->next = p->next;
    p->next = ptr;
}

void Delete(struct Node* head, int index)
{
    struct Node* p1=head;
    struct Node* p;
    int i=0;
    while(i <index-1)
    {
        p1=p1->next;
        i++;
    }
    p=p1;
    p1 = p1->next;
    p1= p1->next;
    p->next = p1;
}

int main()
{
    //Creation
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    head= (struct Node*)malloc(sizeof(struct Node));
    second= (struct Node*)malloc(sizeof(struct Node));
    third= (struct Node*)malloc(sizeof(struct Node));
    fourth= (struct Node*)malloc(sizeof(struct Node));
    fifth= (struct Node*)malloc(sizeof(struct Node));

    struct Node* p= (struct Node*) malloc (sizeof(struct Node*));
    p=head;
    while(p->next!=NULL)
            scanf("%d", p->data);
    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=13;
    third->next=fourth;

    fourth->data=17;
    fourth->next=NULL;


    //Insertion at Beginning
    head= InsertStart(head, 5);

    //Insertion at End
    fifth=InsertEnd(fourth, 19);

    // Insertion at an Index
    InsertIndex(head, 1, 3); // 1 at 3rd position

    //Deletion
    Delete(head, 3);

    //Traversal and Print
    Traversal(head);
    
    return 0;
}