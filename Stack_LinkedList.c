#include <stdio.h>
#include <stdlib.h>

int size=5,top=-1;
struct Node
{
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

int isEmpty(struct Node* ptr)
{
    if(ptr ==NULL)
    return 1;
    return 0;
}

int isFull(struct Node* ptr)
{
    if(top==size-1)
    return 1;
    return 0;
}

void Pop(struct Node** top)
{
    if(!isEmpty(*top))
    {
       struct Node* p=*top; 
       *top= (*top)->next;
       free(p);                
    }
    else
        printf("Stack is Empty");
}

struct Node* Push(struct Node* top, int x)
{
    if(!isFull(top))
    {
        struct Node* n= (struct Node*) malloc (sizeof(struct Node*));
        n->data = x;
        n->next = top;
        top=n;
    }
    else
        printf("Stack is Full");
    return top;
}

int main()
{
    struct Node* top =NULL;
    top = Push(top, 5);
    top = Push(top, 6);
    top = Push(top, 7);
    Pop(&top);
    Traversal(top);
    return 0;
}