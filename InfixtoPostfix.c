#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 7

//Only for +, -, /, * operators.

struct Stack{
    
    int top;
    char * arr;
};

int isEmpty(struct Stack* ptr)
{
    if(ptr->top==-1)
    return 1;
    return 0;
}
int isOperator(char a)
{
    if(a=='+'|| a=='-' || a=='*' || a=='/')
    return 1;
    return 0;
}
int Prec(char a)
{
    if(a=='*' || a=='/')
    return 2;
    else if(a=='+'|| a=='-')
    return 1;
}

void Push(struct Stack* ptr, int x)
{
    ptr->top++;
    ptr->arr[ptr->top]=x;  
}

char Pop(struct Stack* ptr)
{
    char a=ptr->arr[ptr->top];
    ptr->top--;
    return a;
}

char* InftoPost(struct Stack* s)
{
    char infix[]= "a+b/c";
    char* postfix; 
    postfix =(char*) malloc(sizeof(infix)* sizeof(char));
    int j=0;
    for(int i=0; i<strlen(infix); i++)
    {
        if(isOperator(infix[i]))
        {
            if(isEmpty(s))
                Push(s,infix[i]);
            else
                {
                    if(Prec(infix[i])>Prec(s->arr[s->top]))
                    Push(s,infix[i]);
                    else{
                    postfix[j]=Pop(s);
                    Push(s,infix[i]);
                    j++;
                    }
                }
        }
        else
        {
        postfix[j]=infix[i];
        j++;
            }
    }
    while(!isEmpty(s))
    {     
        postfix[j]=Pop(s);   
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    struct Stack* s;
    s= (struct Stack*) malloc (sizeof(struct Stack));
    s->top=-1;
    s->arr = (char*) malloc (N * sizeof(char));
    printf("Postfix is: %s", InftoPost(s));
}