#include <stdio.h>
#include <stdlib.h>
#define N 2

struct Queue{
    int size;
    int f;
    int r;
    int * arr;
};
int isEmpty(struct Queue* ptr)
{
    if(ptr->f==ptr->r)
    return 1;
    return 0;
}

int isFull(struct Queue* ptr)
{
    if(ptr->size-1==ptr->r)
    return 1;
    return 0;
}
struct Queue* Enqueue(struct Queue* ptr, int x)
{
    if(!isFull(ptr))
    {
        ptr->r++;
        ptr->arr[ptr->r]=x;
    }
    else 
    printf("\nQueue is Full, cannot enqueue %d\n",x);
    return ptr;
}
struct Queue* Dequeue(struct Queue* ptr)
{
    if(!isEmpty(ptr))
        ptr->f++;
    else
    printf("Queue is Empty");
    return ptr;
}
void Traversal(struct Queue* ptr)
{
    for(int i=ptr->f+1; i<=ptr->r; i++)
    printf("%d\t", ptr->arr[i]);
}

int main()
{
    struct Queue * q= (struct Queue*) malloc (sizeof(struct Queue));
    q->size=N;
    q->f=q->r=-1;
    q->arr = (int*) malloc(sizeof(int));

    //Operations
    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);
    
    
    Dequeue(q);
    
    Enqueue(q, 5);

    Traversal(q);
}