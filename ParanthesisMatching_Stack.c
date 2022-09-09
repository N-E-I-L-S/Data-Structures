#include <stdio.h>
#include <stdlib.h>
#define N 10 // Size of Input array and Stack

struct Stack{
    int top;
    int size;
    int *arr;
};

//Basic Stack Functions
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
    ptr->arr[ptr->top]=0;
    ptr->top--;   
}

//Driver Function
void Paramatch(struct Stack* s, int* array)
{
    int flag=0;
    for(int i=0; i<N; i++)
    {
        if(array[i]==1)
        Push(s, 1);
        else if(array[i]==2)
        {
            if(isEmpty(s))
            {
                printf("Paranthesis Not Matched!");
                flag=1;
                break;
            }
            else
            Pop(s);
        }
    }
    if(flag==0){
    if(isEmpty(s))
    printf("Paranthesis Matched!");
    else
    printf("Paranthesis Not Matched!");
    }
    
}

int main()
{
    struct Stack* s;
    int array[N];
    s=(struct Stack* ) malloc (sizeof(struct Stack));
    s->top= -1;
    s->size =N;
    s->arr =(int*) calloc (s->size, sizeof(int));   
    
    //  Assigning All Elements
    for(int i=0; i<N; i++){    // 1 == open, 2== closed
    if(i%2==0)
    array[i]=1;
    else
    array[i]=2;
    }
    
    //Function Call
    Paramatch(s,array);
}