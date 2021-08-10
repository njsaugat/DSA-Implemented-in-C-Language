#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int key)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("the queue is full");
    }
    else
    {
        newnode->data = key;
        newnode->next = NULL;
        if (front == NULL && rear == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
}
int dequeue()
{
    struct node *temp;
    int x = -1;
    if (front == NULL)
    { //it will not be empty when front and rear are equal; instead will be empty when front is null only; bcz rear will not be deleted and made as null once initalized ;but front willbe
        printf("the queue is empty");
    }
    else
    {
        temp = front;
        front = front->next;
        x = temp->data;
        free(temp);
        temp = NULL;
    }
    return x;
}

void display()
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        printf("\n");
        temp = temp->next;
    }
}

int isEmpty()
{   if (front == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        return 1;
    }
    return 0;
}
void main()
{
    enqueue(4);
    enqueue(6);
    enqueue(8);
    enqueue(3);
    display();
    dequeue();
    dequeue();
    dequeue();
    printf("\n");
    display();
    printf("%d",isFull());
    printf("%d",isEmpty());
}