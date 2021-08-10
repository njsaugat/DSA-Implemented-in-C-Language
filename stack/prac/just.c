#include <stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int* arr;
};

void push(struct stack* st, int key){
    if(st->top==st->size-1){
        printf("stack overflow");
    }else{
        st->top++;
        st->arr[st->top]=key;
    }
}
int pop(struct stack* st){
    int x=-1;
    if(st->top==-1){
        printf("stack underflow");
    }else{
        x=st->arr[st->top];
        st->top--;
    }
    return x;
}
int peek(struct stack st, int pos){
    if(st.top==-1){
        printf("stack underflow");
    }else{
        return st.arr[st.top-pos+1];
    }
}
int isFull(struct stack st){
    if (st.top==st.size-1){
        return 1;
    }return 0;
}
int isEmpty(struct stack st){
    if(st.top==-1){
        return 1;
    }return 0;
}
int stackTop(struct stack st){
    if(st.top==-1){
        return -1;
    }return st.arr[st.top];
}
void display(struct stack st){
    int temp=st.top;
    while(temp!=-1){
        printf("%d", st.arr[temp]);
        printf("\n");
        temp--;
    }
}
void main(){
    struct stack st;
    st.top=-1;
    st.size=10;
    st.arr=(int*)malloc(sizeof(int)*st.size);
    push(&st,3);
    push(&st,5);
    push(&st,4);
    display(st);
    pop(&st);
    printf("\n");
    display(st);
    printf("%d",peek(st, 1));
    printf("\n");
    
    printf("%d",isEmpty(st));
    printf("%d",isFull(st));
    printf("%d",stackTop(st));
    
}