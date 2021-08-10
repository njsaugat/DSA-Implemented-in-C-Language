// tree with queue;queue implemented using LINKED LIST
#include <stdio.h>
#include <stdlib.h>
// #include "E:\c progamming\DSA\tree\tree.h"
#include "E:\c progamming\DSA\tree\queue_LL.h"

struct node *create(int arr[])
{
    int key, x, i = 0;
    struct node *p;
    printf("enter root's data   ");
    scanf("%d", &key);
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = key;
    root->lchild = root->rchild = NULL;
    // struct queue* q;
    enqueue(root);

    while (!isEmpty())
    {
        p = dequeue();
        printf("enter left child of %d(-1 if no left child  )", p->data);
        scanf("%d", &x);
        // x=arr[i++];
        if (x != -1)
        {
            struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
            newnode1->data = x;
            newnode1->lchild = newnode1->rchild = NULL;
            p->lchild = newnode1;
            enqueue(newnode1);
        }

        // x=arr[i++];

        printf("enter right child of %d(-1 if no right child    )", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
            newnode2->data = x;
            newnode2->lchild = newnode2->rchild = NULL;
            p->rchild = newnode2;
            enqueue(newnode2);
            // display();
        }
    }
    return root;
}
void preorder(struct node *root)
{
    if (root)
    {
        printf("%d", root->data);
        printf("\n");
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void level_order(struct node *root)
{
    struct node *p;
    printf("%d", root->data);
    printf("\n");
    enqueue(root);
    while (!isEmpty())
    {
        p = dequeue();
        if (p->lchild)
        {
            printf("%d", p->lchild->data);
            printf("\n");
            enqueue(p->lchild);
        }
        if (p->rchild)
        {
            printf("%d", p->rchild->data);
            printf("\n");
            enqueue(p->rchild);
        }
    }
}

void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->lchild);
        printf("%d", root->data);
        printf("\n");
        inorder(root->rchild);
    }
}

void postorder(struct node *root)
{
    if (root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d", root->data);
        printf("\n");
    }
}
// most of the other operations of tree follows postorder traversals
int count(struct node *root)
{
    if (root)
    {
        int x = count(root->lchild);
        int y = count(root->rchild);
        return x + y + 1;
    }
    return 0;
}

int height(struct node *root)
{
    if (root)
    {
        int x = height(root->lchild);
        int y = height(root->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    return 0;
}

int sum(struct node *root)
{
    if (root)
    {
        int x = sum(root->lchild);
        int y = sum(root->rchild);
        return x + y + root->data;
    }
    return 0;
}
int count_leaf(struct node *root)
{
    if (root)
    {
        int x = count_leaf(root->lchild);
        int y = count_leaf(root->rchild);
        if (root->lchild == NULL && root->rchild == NULL)
        {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}
int count_deg2(struct node *root)
{
    if (root)
    {
        int x = count_deg2(root->lchild);
        int y = count_deg2(root->rchild);
        if (root->lchild != NULL && root->rchild != NULL)
        {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}
int count_deg1_2(struct node *root)
{
    if (root)
    {
        int x = count_deg1_2(root->lchild);
        int y = count_deg1_2(root->rchild);
        if (root->lchild != NULL || root->rchild != NULL)// if only 1 condition is true then it counts; 2 condition then also count; no count if both false
        {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}
int count_deg1(struct node *root)
{
    if (root)
    {
        int x = count_deg1(root->lchild);
        int y = count_deg1(root->rchild);
        if ((root->lchild != NULL && root->rchild == NULL) || (root->lchild == NULL && root->rchild != NULL))// only 1 condition can be true not both; so perfect for measuring deg 1 nodes
        {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

void main()
{
    int arr[] = {16, 18, 17, 20, 31, 32};
    struct node *root = create(arr);

    printf("Level Order:");
    level_order(root);
    printf("\n");

    printf("preorder :");
    printf("\n");preorder(root);
    printf("\n");

    printf("inorder :");
    printf("\n"); inorder(root);
    printf("\n");

    printf("postorder :");
    printf("\n");postorder(root);
    printf("\n");

    printf("the number of nodes in the tree is %d", count(root));
    printf("\n");

    printf("the height of the tree is %d", height(root));
    printf("\n");
    
    printf("the sum of all elements  of the tree is %d", sum(root));
    printf("\n");
    
    printf("the number of nodes in the tree with degree 0 is %d", count_leaf(root));
    printf("\n");

    printf("the number of nodes in the tree with degree 2 is %d", count_deg2(root));
    printf("\n");

    printf("the number of nodes in the tree with degree 1 and 2 is %d", count_deg1_2(root));
    printf("\n");

    printf("the number of nodes in the tree with degree 1 is %d", count_deg1(root));
    printf("\n");

}
