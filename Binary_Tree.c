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

void PreorderTraversal(struct Node* root)
{
    if(root!=NULL)
    {
        printf("%d\t", root->data);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

void PostorderTraversal(struct Node* root)
{
    if(root!=NULL)
    {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("%d\t", root->data);
    }   
}

void InorderTraversal(struct Node* root)
{
    if(root!=NULL)
    {
        InorderTraversal(root->left);
        printf("%d\t", root->data);
        InorderTraversal(root->right);
    }   

}

int sum;
int SumofallNodes(struct Node* root)
{
    if(root!=NULL)
    {
        SumofallNodes(root->left);
        SumofallNodes(root->right);
        sum=sum+root->data;
    }
    return sum;
}
int main()
{
    struct Node* p=createnode(15);
    struct Node* p1=createnode(10);
    struct Node* p2=createnode(20);
    p->left=p1;
    p->right=p2;

    struct Node* p3=createnode(12);
    struct Node* p4=createnode(8);
    p1->left=p4;
    p1->right=p3;

    struct Node* p5=createnode(25);
    struct Node* p6=createnode(16);
    p2->left=p6;
    p2->right=p5;
    
    printf("\nPreOrder Traversl :\n");
    PreorderTraversal(p);
    printf("\nPostOrder Traversal:\n");
    PostorderTraversal(p);
    printf("\nInOrder Traversal :\n");
    InorderTraversal(p);
    
    printf("\nSum of all Nodes is : %d\n",SumofallNodes(p));
    return 0;
}