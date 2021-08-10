#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node* next;
};
struct node* top= NULL;
void push(int key){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=NULL;
    if(newnode==NULL){
        printf("stack overflow");
    }else{
        if(top!=NULL){
            newnode->next=top;
        }
        top=newnode;
    }
}
int pop(){
    int x=-1;
    struct node* temp;
    if(top==NULL){
        printf("stack underflow");
    }else{
        temp=top;
        x=temp->data;
        top=top->next;
        free(temp);
        temp=NULL;
    }
    return x;
}
int display(){
    struct node* temp=top;
    while(temp!=NULL){
        printf("%d", temp->data);
        printf("\n");
        temp=temp->next;
    }
}
int peek(int pos){
    struct node* temp=top;
    for(int i=0;i<pos-1 && temp;i++){
        temp=temp->next;
    }
    return temp->data;
}
int isFull(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL){
        return 1;
    }return 0;    
}
int isEmpty(){
    if(top==NULL){
        return 1;
    }return 0;
}
int stackTop(){
    if(top==NULL){
        return -1;
    }return top->data;
}
void main(){
    push(2);
    push(5);
    push(8);
    push(9);
    push(3);
    push(6);
    display();
    printf("\n");
    pop();
    pop();
    pop();
    display();
    printf("%d", peek(3));
    printf("%d", isFull());
    printf("%d", isEmpty());
    printf("%d", stackTop());

}