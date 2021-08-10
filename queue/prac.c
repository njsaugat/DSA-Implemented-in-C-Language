#include <stdio.h>
#include <stdlib.h>
// this code relates with practising the basic components of queue; for stack- done
// here we dont use structure
#define size 10 // only here we define the size
int front = 0, rear = 0;

void enqueue(int queue[], int key)
{
    if (rear == size - 1)
    {
        printf("the queue is full");
    }
    else
    {
        queue[rear] = key;
        rear++;
    }
}
int dequeue(int queue[])
{
    int x = -1;
    if (rear == front || front > rear)
    {
        printf("the queue is empty");
    }
    else
    {
        x = queue[front];
        front++;
    }
    return x;
}

void display(int queue[])
{
    int temp = front;
    while (temp != rear)
    {
        printf("%d", queue[temp]);
        printf("\n");
        temp++;
    }
}
int isEmpty(int queue[])
{
    if (rear == front || front > rear)
    {
        return 1;
    }
    return 0;
}

int isFull(int queue[])
{
    if (rear == size - 1)
    {
        return 1;
    }
    return 0;
}

void main()
{
    int queue[size];
    enqueue(queue, 4);// array when passed like this have 2 connotations
    enqueue(queue, 6);// one that the actual array is being passed so in that case the parameter should have like array[] or queue[]
    enqueue(queue, 5);// other being that of a pointer; ie we assume that name of array, which is pointer itself, is being passed as pointer ; so in parameter we pass *arr or *queue here
    enqueue(queue, 7);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    printf("%d", isEmpty(queue));
    printf("%d", isFull(queue));

}
