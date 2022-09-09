#include <stdio.h>
#include <stdlib.h>
#define head a second b third c

struct Node{
    int value;
    struct Node* next;
};

void Traversal(struct Node* p)
{
    for(int i=0 ;i<10; i++)
    {
        printf("Iteration %d: \t%d\n",i, p->value);
        p=p->next;
    }
}
int main()
{
    struct Node*a;
    struct Node *b;
    struct Node*c;

   a= (struct Node*) malloc(sizeof(struct Node*));
   b = (struct Node*) malloc(sizeof(struct Node*));
   c = (struct Node* )malloc(sizeof(struct Node*));

   a -> value =2;
   a -> next =b;

   b -> value= 4;
   b -> next =c;

   c -> value = 6;
   c -> next =a;

    Traversal(a);
    return 0;
}