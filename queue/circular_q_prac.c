#include <stdlib.h>
#include <stdio.h>
#define size 5
// instead of incrementing the index pointer linearly we increase them circularly
// front le point gareko thau ma khali hunxa; no elements
int queue[size];

int front = 0;
int rear = 0;
void enqueue(int key)
{
    if ((rear + 1) % size == front)
    {
        printf("the queue is full");
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = key;
    }
}
int dequeue()
{
    int x = -1;
    if (front == rear)
    {
        printf("the queue is empty");
    }
    else
    {
        front = (front + 1) % size;
        x = queue[front];
    }
    return x;
}
void display()
{
    int temp = front ;
    while (temp != (rear)) // pahila print ani move so not (temp!=rear+1)
    {
        temp = (temp + 1) % size; // yaha ni  circularly increment garna parxa
        printf("%d", queue[temp]);
        printf("\n");
    }
}
void main()
{
    enqueue(45);
    enqueue(47);
    enqueue(46);
    enqueue(48);
    enqueue(43);
    enqueue(54);
    display();
    // dequeue();
    // dequeue();
    // // dequeue();
    printf("\n");
    // display();
}