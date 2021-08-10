#include <stdlib.h>
#include <stdio.h>
//we dont declare anything as  N
// yaha sabai kura lau pointer ko through bata address garna parxa bcz c ma everything is inside function ; so whatever is inside one function 
// mayn't be there in the other function ; but by declaring struct stack with help of pointer  in heap helps every function access it 
// here we shouldn't worry abt deleting unused space in heap as we have declared array in heap
#define size 10
struct stack{
    // int top
    // int size;
    int arr[];
    int top;
};

void push(struct stack st, int key){
    if(st.top==size-1){
        printf("stack overflow");
    }else{
        st.top++;
        st.arr[st.top]=key;
    }
}
void display(struct stack st){
    int temp=st.top;
    while (temp!=-1){
        printf("%d", st.arr[temp]);
        printf("\n");
        temp--;
    }
}

void main(){
    struct stack st;
    
    push(st,64);
    push(st,45);
    push(st,86);
    push(st,28);
    display(st);
}
