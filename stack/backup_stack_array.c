#include <stdio.h>
#include<stdlib.h>
// arr integer pointer matra vaae pugxa bcz malloc le heap ma contigous form ma elements lai store garxa like array
// so we only need a single pointer which becomes array pointer bcz of heap;
struct stack{
    int size;
    int top;
    int* arr;
};

void push(struct stack* st, int key){
    if (st->top==st->size-1){
        printf("stack overflow");
    }else{
        st->top++;
        st->arr[st->top]=key;
    }
}
int pop(struct stack* st){
    int x=-1;
    if (st->top==-1){
        printf("stack underflow");
    }else{
        x=st->arr[st->top];
        st->top--;
    }return x;
}
int peek(struct stack st, int pos){
    int x=-1;
    if(st.top==-1){
        printf("stack is empty");
    }else{
        x=st.arr[st.top-pos+1];
    }return x;
}
void display(struct stack st){
    int temp=st.top;
    while (temp!=-1)
    {
        printf("%d",st.arr[temp]);
        printf("\n");
        temp--;
    }
    
}
int isEmpty(struct stack st){
    if(st.top==-1){
        return 1;
    }return 0;
}
int isFull(struct stack st){
    if (st.top==st.size-1){
        return 1;
    }return 0;
}
int stackTop(struct stack st){
    if(isEmpty(st)){
        return -1;
    }return st.arr[st.top];
}
void main(){
    struct stack st;
    printf("Enter the size of the stack");
    scanf("%d", &st.size);
    st.top=-1;
    st.arr=(int*)malloc(sizeof(int)*10);
    push(&st,4);
    push(&st,6);
    push(&st,7);
    push(&st,8);
    push(&st,3);
    display(st);

}