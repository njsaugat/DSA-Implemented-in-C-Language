#include <stdlib.h>
#include<stdio.h>
//using this file for paranthesis matching, int data is modified to char data; bcz the data type of () is char
// so in push function it should accept char type of data and even in pop it should pop out char data
struct node{
    char data;
    struct node* next;
};

struct node* top=NULL;

void push(char key){
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
char pop(){
    struct node* temp;
    char x=-1;
    if(top==NULL){
        return -1;
    }else{
        x=top->data;
        temp=top;
        top=top->next;
        free(temp);
        temp=NULL;
    }
    return x;
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
char stackTop(){
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

