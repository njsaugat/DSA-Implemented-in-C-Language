#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *less_optimied_create(struct node *root)
{
    int x;
    printf("enter root's data");
    scanf("%d", &x);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter  left child's  data of %d    ", root->data);
    scanf("%d", &x);
    if (x != -1)
    {
        newnode->data = x;
        root->lchild = create(newnode);
    }
    else
    {
        root->lchild = NULL;
    }
    printf("enter  right child's  data of %d    ", root->data);
    scanf("%d", &x);
    if (x != -1)
    {
        newnode->data = x;
        root->rchild = create(newnode);
    }
    else
    {
        root->rchild = NULL;
    }
}

struct node *create()
{
    int x, key;
    printf("enter  data   ");
    scanf("%d", &key);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    printf("does left child exist of %d    ", newnode->data);
    scanf("%d", &x);
    if (x == 1)
    {
        newnode->lchild = create();
    }
    else
    {
        newnode->lchild= NULL;
    }
    printf("does right child exist of %d   ", newnode->data);
    scanf("%d", &x);
    if (x == 1)
    {
        newnode->rchild = create();
    }
    else
    {
        newnode->rchild= NULL;
    }
    return newnode; // last ma ghumi phiri pheri root ma nai auxa which is root node;
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
    struct node *root = create();
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