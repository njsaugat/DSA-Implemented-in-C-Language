#include <stdlib.h>
#include <stdio.h>

struct node
{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
};

int node_height(struct node* temp)
{
    int x=temp->lchild->height;
    int y=temp->rchild->height;
    // if(x)
    return 0;
}
struct node* LLrotation(struct node* temp){
    return NULL;
}
struct node* RRrotation(struct node* temp){
    return NULL;
}
struct node* LRrotation(struct node* temp){
    return NULL;
}
struct node* RLrotation(struct node* temp){
    return NULL;
}

struct node *insert(struct node *temp, int key)
{
    if (temp)
    {
        if (temp->data == key)
        {
            printf("no duplicates allowed");
        }
        else if (key < temp->data)
        {
            temp->lchild = insert(temp->lchild, key);
        }
        else if (key > temp->data)
        {
            temp->rchild = insert(temp->rchild, key);
        }

        if( node_height(temp)==2 && node_height(temp->lchild)==1 ){
            temp=LLrotation(temp);
        }
        if( node_height(temp)==-2 && node_height(temp->lchild)==-1 ){
            temp=RRrotation(temp);
        }
        if( node_height(temp)==2 && node_height(temp->lchild)==-1 ){
            temp=LRrotation(temp);
        }
        if( node_height(temp)==-2 && node_height(temp->lchild)==1 ){
            temp=RLrotation(temp);
        }
        return temp;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->lchild=newnode->rchild=NULL;
    newnode->height=1;
    
    return newnode;
}
