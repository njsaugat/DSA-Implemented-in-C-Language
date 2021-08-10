#include <stdlib.h>
#include <stdio.h>
struct queue
{
    int rear;
    int front;
    int size;
    int *que;
};

void enqueue(struct queue *q, int key)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("the queue is full");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->que[q->rear] = key;
    }
}

int dequeue(struct queue *q)
{
    int x = -1;
    if (q->rear == q->front)
    {
        printf("the queue is empty");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->que[q->front];
    }
    return x;
}
void display(struct queue q)
{
    if (q.rear == q.front)
    { // one extra condition added on this circular queue;like to show  error when queue is empty
        printf("queue is empty");
    }
    else
    {
        int temp = q.front;
        while (temp != q.rear)
        {
            temp = (temp + 1) % q.size;
            printf("%d", q.que[temp]);
            printf("\n");
        }
    }
}
int isEmpty(struct queue q)
{
    if (q.rear == q.front)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue q)
{
    if ((q.rear + 1) % q.size == q.front)
    {
        return 1;
    }
    return 0;
}
void main()
{
    struct queue q;
    q.front = q.rear = 0;
    q.size = 10;
    q.que = (int *)malloc(sizeof(int) * q.size);
    enqueue(&q,46);
    enqueue(&q,23);
    enqueue(&q,43);
    enqueue(&q,89);
    enqueue(&q,65);
    display(q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    printf("\n");
    display(q);
    printf("\n");
    printf("%d",isEmpty(q));
    printf("%d",isFull(q));

}