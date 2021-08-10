#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
};
struct node *root = NULL;
int node_height(struct node *temp)
{
    int x, y;
    if (temp != NULL && temp->lchild != NULL)
    {
        x = temp->lchild->height;
    }
    else
    {
        x = 0; // make it as 1; so in rotation function it is easy to manage
    }
    if (temp != NULL && temp->rchild != NULL)
    {
        y = temp->rchild->height;
    }
    else
    {
        y = 0; //
    }
    return x - y;
}
int fheight(struct node *temp)
{ //this is done iteratively instead of recursively
    int x;
    int y;
    if (temp != NULL && temp->lchild != NULL)
    {
        x = temp->lchild->height;
    }
    else
    {
        x = 0; // make it as 1; so in rotation function it is easy to manage
    }
    if (temp != NULL && temp->rchild != NULL)
    {
        y = temp->rchild->height;
    }
    else
    {
        y = 0; //
    }
    if (x > y)
    {
        return x + 1;
    }
    return y + 1;
}

struct node *LLrotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = fheight(p);   //height vanya children ma dependente hunxa; jasko
    pl->height = fheight(pl); // santan change vairaxa tesko height change
    if (p == root)
    {
        root = pl;
    }
    return pl;
}

struct node *RRrotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    pr->height = fheight(pr);
    p->height = fheight(p);
    if (root == p)
    {
        root = pr;
    }
    return pr;
}

struct node *LRrotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    plr->height = fheight(plr);
    pl->height = fheight(pl);
    p->height = fheight(p);
    if (root = p)
    {
        root = plr;
    }
    return plr;
}
struct node *RLrotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;
    prl->height = fheight(prl);
    pr->height = fheight(pr);
    p->height = fheight(p);
    if (root = p)
    {
        root = prl;
    }
    return pr;
}

struct node *insert(struct node *temp, int key)
{
    if (temp)
    {
        if (key == temp->data)
        {
            printf(" no duplicates are allowed");
        }
        else if (key < temp->data)
        {
            temp->lchild = insert(temp->lchild, key);
        }
        else if (key > temp->data)
        {
            temp->rchild = insert(temp->rchild, key);
        }
        //height should be adjusted here
        temp->height = fheight(temp); // height milaepaxi ta honi rotation hanna parne
        if (node_height(temp) == 2 && node_height(temp->lchild) == 1)
        {
            temp = LLrotation(temp);
        }
        if (node_height(temp) == -2 && node_height(temp->rchild) == -1)
        {
            temp = RRrotation(temp);
        }
        if (node_height(temp) == 2 && node_height(temp->lchild) == -1)
        {
            temp = LRrotation(temp);
        }
        if (node_height(temp) == -2 && node_height(temp->rchild) == 1)
        {
            temp = RLrotation(temp);
        }
        return temp;
    }
    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = key;
        newnode->lchild = newnode->rchild = NULL;
        newnode->height = 1;
        return newnode;
    }
}
void preorder(struct node *p)
{
    if (p)
    {
        printf("%d", p->data);
        printf("\n");
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
struct node *predecessor(struct node *p)
{
    struct node *q;
    while (p)
    {
        q = p;
        p = p->rchild;
    }
    return q;
}
struct node *successor(struct node *p)
{
    struct node *q;
    while (p)
    {
        q = p;
        p = p->lchild;
    }
    return q;
}
struct node *delete (struct node *temp, int key)
{
    struct node *q;
    if (root == NULL)
    {
        return NULL;
    }
    if (temp->lchild == NULL && temp->rchild == NULL)
    {
        free(temp);
        temp = NULL;
        return NULL;// delete vaisakeko height change garna pardaina

    }
    if (temp)
    {
        if (key < temp->data)
        {
            temp->lchild = delete (temp->lchild, key);
        }
        else if (key > temp->data)
        {
            temp->rchild = delete (temp->rchild, key);
        }
        else
        {
            if (temp->lchild)
            { // in this case call succesor
                q = predecessor(temp->lchild);
                temp->data = q->data;
                temp->lchild = delete(temp->lchild, q->data);
            }
            else if(temp->rchild)
            {
                q = successor(temp->rchild);
                temp->data = q->data;
                temp->rchild = delete(temp->rchild, q->data);
            }
        }
        temp->height=fheight(temp);
        if (node_height(temp) == 2 && ((node_height(temp->lchild) == 1) || (node_height(temp->lchild) == 0)))
        {
            temp = LLrotation(temp);
        }
        if (node_height(temp) == -2 && ((node_height(temp->rchild) == -1) || (node_height(temp->rchild) == 0)))
        {
            temp = RRrotation(temp);
        }
        if (node_height(temp) == 2 && node_height(temp->lchild) == -1)
        {
            temp = LRrotation(temp);
        }
        if (node_height(temp) == -2 && node_height(temp->rchild) == 1)
        {
            temp = RLrotation(temp);
        }
        return temp;
    }
}
void main()
{
    root = insert(root, 10);
    insert(root, 30);
    insert(root, 20);
    insert(root, 15);
    insert(root, 25);
    insert(root, 40);
    // preorder(root);
    delete(root,20);
    delete(root,15);
    preorder(root);
}
