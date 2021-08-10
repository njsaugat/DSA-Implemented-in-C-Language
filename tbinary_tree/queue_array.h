#include <stdio.h>
#include <stdlib.h>
#include "E:\c progamming\DSA\tree\tree_arr.h"

struct queue{
    int front;
    int rear;
    int size;
    struct node** que;//double pointer because double way access/ single pointer ley array of nodes ma point garxa vane from that pointer bata ni pheri tree ko nofes lai access garna parxa so we need double pointer; 1st was for array like previoudly also it was but extra pointer heres to point ot tree ko node 
};

void enqueue(struct queue * q, struct node* key){// array of pointers haina? so tyo array ko harek element(key) pointer huna paryo ni ta tree node ko
    if(q->rear==q->size-1){
        printf("queue is full");
    }else{
        q->rear++;
        q->que[q->rear]=key;
    }
}

struct node* dequeue(struct queue* q){// same reason as above; array of pointers so pointer ko address dina paryo
    struct node* x=NULL;    
    if(q->front==q->rear){
        printf("queue is empty");
    }else{
        q->front++;
        x=q->que[q->front];
    }
    return x;
}
void display(struct queue q){
    int temp=q.front;
    while(temp!=(q.rear)){
        temp++;
        printf("%d",q.que[temp]);
        printf("\n");
    }
}

void display1(struct queue q){
    int temp=q.rear;
    while(temp!=(q.front)){
        printf("%d",q.que[temp]);
        temp--;
    }
}
int isEmpty(struct queue q){
    if(q.front==q.rear){
        return 1;
    }return 0;
}
int isFull(struct queue q){
    if(q.rear==q.size-1){
        return 1;
    }return 0;
}