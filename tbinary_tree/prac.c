#include <stdlib.h>
#include<stdio.h>
struct node{
    struct node* lchild;
    int data;
    struct node* rchild;
};
struct node* create(struct node* root){
    int x;
    printf("enter root's data");
    scanf("%d",&x);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
       
    create(root->lchild);
    create(root->rchild);
}

void main(){
    int x;
    struct node* root=(struct node*)malloc(sizeof(struct node));
    printf("enter root's data");
    scanf("%d",&x);
    root->data=x;
    root->lchild=root->rchild=NULL;
    create(root);
}