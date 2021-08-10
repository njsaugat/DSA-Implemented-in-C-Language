// binary tree created using queue implelmented using array
#include <stdio.h>
#include <stdlib.h>
#include "E:\c progamming\DSA\tree\queue_array.h"
// #include "E:\c progamming\DSA\tree\tree_arr.h"
void create(int arr[])
{
    int x, i = 0;
    struct node *root, *p;
    root = (struct node *)malloc(sizeof(struct node));
    printf("enter root's data   ");
    scanf("%d", &x);
    root->data = x;
    root->lchild = root->rchild = NULL;
    struct queue q;
    q.front = -1; q.rear = -1; q.size = 6;
    q.que = (struct node **)malloc(sizeof(int) * q.size);
    enqueue(&q, root);
    while (!isEmpty(q))// I had written isEmpty instead of !isEmpty
    {
        p = dequeue(&q);
        printf("enter left child of(-1 for no child) %d", p->data);
        scanf("%d", &x);
        // x=arr[i++];
        if (x!=-1 )
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = x;
            newnode->lchild = newnode->rchild = NULL;
            p->lchild = newnode;
            enqueue(&q, newnode);
        }
        printf("enter right child of(-1 for no child) %d", p->data);
        scanf("%d", &x);
        // x=arr[i++];
        if (x!=-1)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = x;
            newnode->lchild = newnode->rchild = NULL;
            p->rchild = newnode;
            enqueue(&q, newnode);
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
    create(arr);
}