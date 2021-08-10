#include <stdlib.h>
#include <stdio.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
void push(struct stack *st, int key)
{
    if (st->top == st->size - 1)
    {
        printf("queue is  full");
    }
    else
    {
        st->top++;
        st->arr[st->top] = key;
    }
}
int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("stack  underflow");
    }
    else
    {
        x = st->arr[st->top];
        st->top--;
    }
    return x;
}

void display(struct stack st)
{
    int temp = st.top;
    while (temp != -1)
    {
        printf("%d", st.arr[temp]);
        printf("\n");
        temp++;
    }
}
int isFull(struct stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}
int stackTop(struct stack st)
{
    if (st.top == -1)
    {
        return -1;
    }
    return st.arr[st.top];
}

void enqueue(struct stack *st1, int key)
{
    push(st1, key);
}
int dequeue(struct stack *st1, struct stack *st2)
{ // if stack2 khali xa vane matra st1 bata st2 ma copy garne
    int x = -1;
    if (isEmpty(*st2))
    { // only start this procedure if 2nd stack is empty; if not empty directly pop out
        if (isEmpty(*st1))
        { // stack one nai empty xa vane ta  k dequeue garne ho ra
            printf("queue is empty");
            return -1;
        }
        else
        {
            while (!isEmpty(*st1))
            {
                push(st2, pop(st1));
            }
        }
    }
    x = pop(st2);
    return x;
}

void queue_display(struct stack st1, struct stack st2)
{
    int temp = st2.top;
    if (!isEmpty(st2))
    { // empty xaina vane matra print garne
        while (temp != -1)
        {
            printf("%d", st2.arr[temp]);
            printf("\n");
            temp--;
        }
    }
    temp++; // temp lai 0 ma lyako; stack2 empty xa vane ta st2.top=-1; so
    while (temp != (st1.top + 1))
    { // FIFO parama display garna parxa so// here i dont check if stack is empty; assumming it has some values
        printf("%d", st1.arr[temp]);
        printf("\n");
        temp++;
    }
}
void main()
{
    struct stack st1,  st2;
    st1.top=st2.top=-1;
    st1.size=st2.size=5;
    st1.arr=(int*)malloc(sizeof(int)*st1.size);
    st2.arr=(int*)malloc(sizeof(int)*st2.size);
    enqueue(&st1,24);
    enqueue(&st1,25);
    enqueue(&st1,28);
    enqueue(&st1,23);
    enqueue(&st1,87);
    // queue_display(st1, st2);
    // enqueue(&st1,87);
    dequeue(&st1,&st2);
    dequeue(&st1,&st2);
    dequeue(&st1,&st2);
    queue_display(st1, st2);
    enqueue(&st1,56);
    enqueue(&st1,76);
    queue_display(st1, st2);
    dequeue(&st1,&st2);
    printf("\n");
    queue_display(st1, st2);
    
}