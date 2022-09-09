#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createnode(int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int CheckBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!CheckBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return CheckBST(root->right);
    }
    else
        return 1;
}

int SearchBST(struct Node *root, int key)
{
    int flag = 0;
    while (root != NULL)
    {
        if (root->data == key)
        {
            flag = 1;
            break;
        }
        else if (key > root->data)
            root = root->right;
        else
            root = root->left;
    }
    return flag;
}

void Insertion(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
            return;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    struct Node *new = createnode(key);
    if (new->data < prev->data)
        prev->left = new;
    else
        prev->right = new;
}

int *arr;
int k;
int *InorderTarray(struct Node *root)
{
    if (root != NULL)
    {
        InorderTarray(root->left);
        arr[k] = root->data;
        k++;
        InorderTarray(root->right);
    }
    return arr;
}
int AlternativeisBST(struct Node *root)
{
    arr = (int *)malloc(7 * sizeof(int));
    int *b = InorderTarray(root);
    for (int i = 1; i < 7; i++)
        if (b[i] < b[i - 1])
            return 0;
    return 1;
}

void DeletionLeafNode(struct Node *root, int x)
{
    struct Node *prev = NULL;
    while (root->data != x)
    {
        prev = root;
        if (x == root->data)
            break;
        else if (x > root->data)
            root = root->right;
        else
            root = root->left;
    }
    if (root->data > prev->data)
        prev->right = NULL;
    else
        prev->left = NULL;
    free(root);
}

struct Node *InorderPrec(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct Node *Deletion(struct Node *root, int x)
{
    struct Node *iprev = NULL;
    if (root->left == NULL && root->right == NULL)
        return NULL;

    if (root->data < x)
    {
        root->right = Deletion(root->right, x);
    }
    else if (root->data > x)
    {
        root->left = Deletion(root->left, x);
    }
    else
    {
        iprev = InorderPrec(root);
        root->data = iprev->data;
        root->left = Deletion(root->left, x);
    }
    return root;
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

    // Checking For BST
    printf("is BST : %d\n", CheckBST(p));
    printf("is BST by alternative method : %d\n", AlternativeisBST(p));

    // Searching BST
    printf("0 Element present : %d\n", SearchBST(p, 0));

    printf("\nInorder Traversal:\n");
    InorderTraversal(p);

    // Insertion in BST
    Insertion(p, 11);
    printf("\nInserting 11 :\n");
    InorderTraversal(p);

    // Deletion at Leaf Node in BST
    DeletionLeafNode(p, 16);
    printf("\nDeleting 16 Leaf Node:\n");
    InorderTraversal(p);

    // Deletion at Any Node in BST
    Deletion(p, 10);
    printf("\nDeleting 10 Node:\n");
    InorderTraversal(p);

    return 0;
}