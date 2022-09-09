#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
struct Node *createnode(int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void InorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        InorderTraversal(root->left);
        printf("%d\t", root->data);
        InorderTraversal(root->right);
    }
}
int max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}
int getHt(struct Node *root)
{
    if (root == NULL)
        return 0;
    return max(getHt(root->right), getHt(root->left)) + 1;
}
int getBF(struct Node *root)
{
    if (root == NULL)
        return 0;
    return getHt(root->left) - getHt(root->right);
}

struct Node *RotateLeft(struct Node *root)
{
    struct Node *c = root->right;
    struct Node *b = root->left;

    root->right = c->left;
    c->left = root;

    root->height = getHt(root);
    b->height = getHt(b);
    return c;
}

struct Node *RotateRight(struct Node *root)
{
    struct Node *c = root->right;
    struct Node *b = root->left;

    root->left = b->right;
    b->right = root;

    root->height = getHt(root);
    c->height = getHt(c);
    return b;
}

struct Node *InsertAVL(struct Node *root, int x)
{
    if (root == NULL)
        return createnode(x);
    if (x > root->data)
        root->right = InsertAVL(root->right, x);
    else if (x < root->data)
        root->left = InsertAVL(root->left, x);
    return root;

    root->height= getHt(root);
    int bf = getBF(root);
    // LL
    if(bf>1 && x< root->left->data)
    root = RotateRight(root);
    // RR
    else if(bf<-1 && x> root->right->data)
    root = RotateLeft(root);
    //  LR
    else if(bf > 1 && x> root->left->data)
    RotateLeft(root);
    //  RL
    else if(bf < -1 && x> root->right->data)
    RotateLeft(root);
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

    // p = RotateLeft(p);
    // printf("%d\n", getBF(p));
    // printf("%d\t", p->data);
    // printf("%d\t", p->left->data);
    // printf("%d\t", p->right->data);
    // printf("%d\t", p->left->left->data);
    // printf("%d\t", p->left->right->data);
    // printf("%d\t", p->left->left->left->data);
    // printf("%d\t", p->left->left->right->data);

    // p = RotateRight(p);
    // printf("%d\t", p->data);
    // printf("%d\t", p->left->data);
    // printf("%d\t", p->right->data);
    // printf("%d\t", p->right->left->data);
    // printf("%d\t", p->right->right->data);
    // printf("%d\t", p->right->right->left->data);
    // printf("%d\t", p->right->right->right->data);

    // InorderTraversal(p);

    InsertAVL(p, 6);
}