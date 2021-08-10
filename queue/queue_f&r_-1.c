#include <stdio.h>
#include <stdlib.h>
//queue using arrays can be solved using 2 methods; ie 1) is pointing on -1. (2) using rear and front pointing on 0 
// this is 1st approach
// both enqueue and dequeue operations have opposite steps in approach 1 and 2
// in both approaches however we are storing elements from index 0;
struct queue{
    int front;
    int rear;
    int size;
    int* que;
};

void enqueue(struct queue* q, int key){
    if(q->rear==q->size-1){
        printf("queue is full");
    }else{
        q->rear++;
        q->que[q->rear]=key;
    }
}

int dequeue(struct queue* q){
    int x=-1;    
    if(q->front==q->rear){
        printf("queue is empty");
    }else{
        q->front++;
        x=q->que[q->front];
    }
    return x;
}
void display(struct queue q){
    int temp=q.front;// yaha ta FIFO follow hunxa so front bata start garna parxa
    while(temp!=(q.rear)){
        temp++;//pahila move garxa ani print garne ho ni ta so (rear-1)th iteration ma huda nai rear ko print hunxa; so no need to write temp =rear+1 instead of current one
        printf("%d",q.que[temp]);
        printf("\n");
    }
}

void display1(struct queue q){
    int temp=q.rear;// esto garyo vane ta stack ko jastai hunca
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


void main(){
    struct queue q;
    q.front=q.rear=-1;
    q.size=10;
    q.que=(int*)malloc(sizeof(int)*q.size);
    enqueue(&q,12);
    enqueue(&q,43);
    enqueue(&q,45);
    enqueue(&q,15);
    enqueue(&q,65);
    enqueue(&q,23);
    display(q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    printf("\n");
    display(q);
    printf("%d", isEmpty(q));
    printf("\n");
    printf("%d", isFull(q));
    printf("\n");
}