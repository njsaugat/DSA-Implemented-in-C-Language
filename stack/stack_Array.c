//3 realizations while implementing stack
// 1. try implementing it the way to write basic algorithm
// 2. try implementing it using struct only;without using pointers; and debug; realize that changes only within function
// 3. implementing using pointers we realize that it works fine; hell so use like st->top ie *st.top
// 4. after that you can make array in heap


// try to implement this stack using pointer to array 
#include<stdlib.h>
#include<stdio.h>

struct stack{
    int size;
    int top;
    int* arr;

};

void push(struct stack* st, int key){
    if (st->top==size-1){
        printf("stack overflow ");
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
    }
}
void display(struct stack st){
    int temp=st.top;
    while (temp!=-1){
        printf("%d",st.arr[temp]);
        printf("\n");
        temp--;
    }
}
int peek(struct stack st,int pos){// helps at peeking values; like well ma hereko; bcz stack is like well(kuwa) ani peek helps see us what is there 
    int x=-1;// btw we consider elements being named from 1 from top not 0; so we say top-pos+1; had we counted from 1 we would write top-pos
    if (st.top==-1){
        printf("stack underflow");
    }else{
        x=st.arr[st.top-pos+1];
    }
    return x;

}
int isEmpty(struct stack st){
    
    if(st.top==-1){
        return 1;
    }return 0;
}
int isFull(struct stack st){
    if(st.top==size-1){
        return 1;
    }return 0;
}
int stackTop(struct stack st){
    if(isEmpty(st)){
        return -1;
    }return st.arr[st.top];
}
void main(){
    // int siz=5;
    struct stack st;
    st.top=-1;
    st.size=5;
    st.arr=(int*) malloc(sizeof(int)*st.size);
    // struct stack* st=&sta;
    push(&st,5);
    push(&st,4);
    push(&st,6);
    push(&st,8);
    push(&st,9);
    // push(&st,2);
    display(st);
    printf("\n");
    // pop(&st);
    // display(st);
    // display(st);
    // pop(&st);
    // pop(&st);
    // pop(&st);
    // pop(&st);
    // display(st);
    printf("\n");
    printf("%d", peek(st,4));    
    printf("\n");
    // display(st);
    printf("%d", isEmpty(st));    
    printf("\n");
    printf("%d", isFull(st));    
    printf("\n");
    printf("%d", stackTop(st));    
    printf("\n");
    
}