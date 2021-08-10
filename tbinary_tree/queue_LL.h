#include <stdio.h>
#include <stdlib.h>
// #include "E:\c progamming\DSA\tree\tree.h"
struct node{
    struct node* lchild;
    int data;
    struct node* rchild;
};

struct lnode
{
    struct node* data;// this is the first difference ie instead of int data; the data member should store address of tree nodes
    struct lnode *next; 
};

struct lnode *front = NULL;
struct lnode *rear = NULL;

void enqueue(struct node* key)// second difference: the key should also be of struct tnode* type as this key is gonna be stored in data member which accepts the struct node* tnode 
{
    struct lnode *newnode = (struct lnode *)malloc(sizeof(struct lnode));
    if (newnode == NULL)
    {
        printf("the queue is full");
    }
    else
    {
        newnode->data = key;
        newnode->next = NULL;
        if (front == NULL && rear == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
}
struct node* dequeue()// return type becz we have to access the tree node from the dequeued elements
{
    struct lnode *temp;
    struct node* x = NULL;
    if (front == NULL && rear==NULL)// it will be empty when both front and rear arre; not when front==NULL;
    { //it will not be empty when front and rear are equal; instead will be empty when front is null only; bcz rear will not be deleted and made as null once initalized ;but front willbe
        printf("the queue is empty");
    }
    else
    {
        temp = front;
        if(front->next==NULL){// very crutial step// could make/break the algo; bcx if we are trying to move front to next,which is null,then front would be null; and if had the conditon of q being empty by front==Null then the no matter what we may enquque front would'nt be brought there  as we dont have any conditiion for that in enqueue;even with the empty's condition as above front would only try to move to next and next from Null;like rat race/rat in circle :) 
            rear=NULL;
        }
        front = front->next;
        x = temp->data;
        free(temp);
        temp = NULL;
    }
    return x;
}

void display()
{
    struct lnode *temp = front;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        printf("\n");
        temp = temp->next;
    }
}

int isEmpty()
{   if (front == NULL && rear==NULL )// as mentioned above
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct lnode *newnode = (struct lnode *)malloc(sizeof(struct lnode));
    if (newnode == NULL)
    {
        return 1;
    }
    return 0;
}
