#include <stdlib.h>
#include <stdio.h>
// in this approach we initialize front and rear to 0
struct queue
{
    int front;
    int rear;
    int size;
    int *que;
};

void enqueue(struct queue *q, int key)
{
    if (q->rear == q->size - 1)
    {
        printf("queue is full");
    }
    else
    {
        q->que[q->rear] = key; // yesma ta jasari ni euta space empty hunxa bcz 0th position ma insert garna lai yo line lekhyo vane second last choti insert garda nai rear last ma pugxa ra queue full vanne auxa;
        q->rear++;             //euta space khali vae ni we follow this;ie front empty vae ni we follow this
    }
}
int dequeue(struct queue *q)
{
    int x = -1;
    if (q->front == q->rear || q->front > q->rear)
    { // esma chai front agadi xa ni ta initialize garne bela so this has to be checked
        printf("queue is empty");
    }
    else
    {
        x = q->que[q->front];
        q->front++; //so pahila move then delete; so last el
    }
    return x;
}

void display(struct queue q)
{
    int temp = q.front; // agadi bata print garna parxa like to follow FIFO
    while (temp != q.rear)
    {
        printf("%d", q.que[temp]);
        printf("\n");
        temp++; // pahila print then move bcz front is from 0
    }
}

int isEmpty(struct queue q)
{
    if (q.front == q.rear)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue q)
{
    if (q.rear == q.size - 1)
    {
        return 1;
    }
    return 0;
}

void main()
{
    struct queue q;
    q.size = 10;
    q.front = 0;
    q.rear = 0; //circular queue ma matra ho front ra rear 0 bata start garne
    q.que = (int *)malloc(sizeof(int) * q.size);
    enqueue(&q, 3);
    enqueue(&q, 6);
    enqueue(&q, 5);
    enqueue(&q, 7);
    enqueue(&q, 4);
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