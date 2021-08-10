#include <stdlib.h>
#include <stdio.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *isearch(struct node *root, int key)
{
    struct node *temp = root;
    while (temp)
    {
        if (temp->data == key)
        {
            return temp;
        }
        else if (key < temp->data)
        {
            temp = temp->lchild;
        }
        else if (key > temp->data)
        {
            temp = temp->rchild;
        }
    }
    return NULL;
}

struct node *search(struct node *temp, int key)
{
    if (temp)
    {
        if (temp->data == key)
        {
            return temp;
        }
        else if (key < temp->data)
        {
            return search(temp->lchild, key);
        }
        else if (key > temp->data)
        {
            return search(temp->rchild, key);
        }
    }
    return NULL;
}

void i_insert(struct node *root, int key)
{ // would only work if root is already initialized; ie wouldn't create from scratch
    struct node *temp = root, *q;
    while (temp)
    {
        q = temp;
        if (key == temp->data)
        {
            printf("no duplicates are allowed");
        }
        else if (key < temp->data)
        {
            temp = temp->lchild;
        }
        else if (key > temp->data)
        {
            temp = temp->rchild;
        }
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->lchild = newnode->rchild = NULL;
    if (key < q->data)
    {
        q->lchild = newnode;
    }
    else
    {
        q->rchild = newnode;
    }
}
struct node *create_insert(struct node *root, int key)
{ // even cares about root; would create BST from scratch
    if (root == NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = key;
        newnode->lchild = newnode->rchild = NULL;
        root = newnode;
        return newnode; // (_not return null but return only)I guess instead of writing 'return newnode' and changing the return type to struct node* this is a good aproach as the root would be changed and while inserting other elements it wouldn't be different than inserting root node as we have made the return type void+ in recursive insert we'll see a different return type as well
    }
    struct node *temp = root, *q;
    while (temp)
    {
        q = temp;
        if (key == temp->data)
        {
            printf("no duplicates are allowed");
        }
        else if (key < temp->data)
        {
            temp = temp->lchild;
        }
        else if (key > temp->data)
        {
            temp = temp->rchild;
        }
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->lchild = newnode->rchild = NULL;
    if (key < q->data)
    {
        q->lchild = newnode;
    }
    else
    {
        q->rchild = newnode;
    }
}

struct node *insert(struct node *temp, int key)
{
    if (temp)
    {
        if (key == temp->data)
        {
            printf("no duplicates allowed");
        }
        else if (key < temp->data)
        {
            temp->lchild = insert(temp->lchild, key); // this is insert right; so modifications on the pointers have to be made
        }
        else if (key > temp->data)
        {
            temp->rchild = insert(temp->rchild, key);
        }
        return temp; // if this is not returned then it is gone; ie values couldn't simply get to its previous func calls
    }
    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node *));
        newnode->data = key;
        newnode->lchild = newnode->rchild = NULL;
        return newnode; // we dont need extra pointer because recursion will help link
    }
}
void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->lchild);
        printf("%d", root->data);
        printf("   ");
        inorder(root->rchild);
    }
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
        return y + 1;
    }
}
struct node *predecessor(struct node *temp)
{
    struct node *q;
    while (temp)
    {
        q = temp;
        temp = temp->rchild;
    }
    return q;
}
struct node *successor(struct node *temp)
{
    struct node *q;
    while (temp)
    {
        q = temp;
        temp = temp->lchild;
    }
    return q;
}
struct node *delete (struct node *temp, int key)
{
    // if(root->data==key){ IF ROOT WAS DECLARED GLOBALLY
    //     root=NULL;
    // }
    // (if root==NULL){return NULL}IF ROOT WAS DECLARED GLOBALLY
    if (temp->lchild == NULL && temp->rchild == NULL)
    { // duitai null ho vane matra delete
        free(temp);
        temp = NULL;
        return NULL; // idk abt the step
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
        { // element is found
            if (height(temp->lchild) > height(temp->rchild))
            { //  our goal is to reduce height;doing this would help decrease the height
                struct node *q = predecessor(temp->lchild);
                temp->data = q->data;
                temp->lchild = delete (temp->lchild, q->data);
            }
            else
            {
                struct node *q = successor(temp->rchild);
                temp->data = q->data;
                temp->rchild = delete (temp->rchild, q->data);
            }
        }
    } 
    return temp;
}

void main()
{
    struct node *root = NULL;
    // root=create_insert(root,20);//instead of passing null, pass root nai;
    // create_insert(root,15);
    // create_insert(root,10);
    // create_insert(root,18);
    // create_insert(root,25);
    // create_insert(root,22);
    // create_insert(root,27);

    // root = insert(root, 20);
    // insert(root, 15);
    // insert(root, 10);
    // insert(root, 18);
    // insert(root, 25);
    // insert(root, 22);
    // insert(root, 27);

    root = insert(root, 20);
    i_insert(root, 15);
    i_insert(root, 10);
    i_insert(root, 18);
    i_insert(root, 25);
    i_insert(root, 22);
    i_insert(root, 27);
    inorder(root);
    printf("\n");
    printf("%d", height(root));
    printf("\n");
    // if (isearch(root, 27))
    // {
    //     printf("the element is present");
    // }
    // else
    // {
    //     printf("the element is not present");
    // }
    delete (root, 15);
    delete (root, 25);
    delete (root, 10);
    delete (root, 22);
    inorder(root);
    printf("\n");
    printf("%d", height(root));
}