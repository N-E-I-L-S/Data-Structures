#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createnode(int x)
{
    struct Node* n= (struct Node*) malloc(sizeof(struct Node));
    n->data=x;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int* arr;
int k;
int* InorderTraversalforCheckBST(struct Node* root)
{
    if(root!=NULL)
    {
        InorderTraversalforCheckBST(root->left);
        arr[k]=root->data;
        k++;
        InorderTraversalforCheckBST(root->right);
    }   
    return arr;
}
int AlternativeisBST(struct Node* root)
{
    arr= (int*) malloc(7*sizeof(int));
    int * b= InorderTraversalforCheckBST(root);
    for(int i=1; i<7; i++)
    if(b[i]<b[i-1])
    return 0;
    return 1;
}


int main()
{
    struct Node *p = createnode(15);
    struct Node *p1 = createnode(10);
    struct Node *p2 = createnode(20);
    p->left = p1;
    p->right = p2;

    struct Node *p3 = createnode(12);
    struct Node *p4 = createnode(8);
    p1->left = p4;
    p1->right = p3;

    struct Node *p5 = createnode(25);
    struct Node *p6 = createnode(16);
    p2->left = p6;
    p2->right = p5;

    printf("is BST : %d", AlternativeisBST(p));
    
}