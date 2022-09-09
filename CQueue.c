#include <stdio.h>
#include <stdlib.h>
#define N 3

struct Queue
{
    int f, r, size;
    int *arr;
};

int isEmpty(struct Queue *ptr)
{
    if (ptr->f == ptr->r)
        return 1;
    return 0;
}

int isFull(struct Queue *ptr)
{
    if ((ptr->r + 1) % ptr->size == ptr->f)
        return 1;
    return 0;
}
void Enqueue(struct Queue *ptr, int x)
{
    if (isFull(ptr))
        printf("Circular Queue is Full\n");
    else
    {
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = x;
        printf("element added = %d\n", ptr->arr[ptr->r]);
    }
}

int Dequeue(struct Queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
        printf("Circular Queue is Empty");
    else
    {
        ptr->f = (ptr->f + 1) % ptr->size;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->f = q->r = 0;
    q->size = N;
    q->arr = (int *)malloc(N * sizeof(int));

    Enqueue(q, 5);
    Enqueue(q, 6);
    printf("Element removed= %d\n", Dequeue(q));
    Enqueue(q, 8);
    printf("Element removed= %d\n", Dequeue(q));
    Enqueue(q, 9);
}