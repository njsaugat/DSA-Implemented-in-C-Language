#include <stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node* next;
};

struct node* top=NULL;

void push(int key){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=NULL;
    if (newnode==NULL){
        printf("stack overflow");
    }else{
        if(top!=NULL){
            newnode->next=top;
        }top=newnode;
    }
}
int pop(){
    struct node* temp;
    int x=-1;
    if(top==NULL){
        printf("stack underflow");
    }else{
        x=top->data;
        temp=top;
        top=top->next;
        free(temp);
        temp=NULL;
    }return x;
}
void display(){
    struct node* temp=top;
    while (temp!=NULL)
    {
        printf("%d", temp->data);
        printf("\n");
        temp=temp->next;
    }    
}
int isFull(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL){
        return 1;
    }return 0;
}
int isEmpty(){
    if (top==NULL){
        return 1;
    }return 0;
}
int stackTop(){
    if (top==NULL){
        return -1;
    }return top->data;
}
int peek(int pos){
    struct node* temp=top;
    for(int i=0;i<pos-1 && temp;i++){
        temp=temp->next;
    }return temp->data;
}
void main(){
    push(4);
    push(3);
    push(6);
    push(8);
    push(5);
    display();
    // pop();
    // pop();
    // pop();
    // pop();
    printf("\n");
    printf("%d", peek(4));
    // display();
}