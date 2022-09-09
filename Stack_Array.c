#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct Stack* ptr)
{
    if(ptr->top==-1)
    return 1;
    return 0;
}

int isFull(struct Stack* ptr)
{
    if(ptr->size == ptr->top)
    return 1;
    return 0;
}

void Push(struct Stack* ptr, int data)
{
    ptr->top++;
   if(!isFull(ptr))
    ptr->arr[ptr->top]= data;
   else
   {
   ptr->top--;
   printf("\n\nFatal Error : Stack is Full\n\n");
   }
}

void Pop(struct Stack* ptr)
{
    if(!isEmpty(ptr)){
    ptr->arr[ptr->top]=0;
    ptr->top--;
    }
    else
    printf("\n\nFatal Error: The Stack is Empty\n\n");
}

int main()
{
    struct Stack* s;
    s=(struct Stack* ) malloc (sizeof(struct Stack));
    s->top=-1;
    s->size=3;
    s->arr =(int*) calloc (s->size, sizeof(int));   
    
    //Push an element at top
    Push(s, 5);

    //Pop an element from top
    Pop(s);

    //Trial
    for(int i=0; i<s->size; i++)
    Push(s,i+1);
    for(int i=0; i<s->size; i++)
    Pop(s);

    return 0;
}