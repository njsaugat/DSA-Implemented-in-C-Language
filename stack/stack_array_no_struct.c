#include <stdio.h>
#include<stdlib.h>
// #define N 10;
int N=10;
int top=-1;
int stack[10];
void push(int key){
    if (top==(N-1)){
        printf("stack overflow");
    }
    else{
        top++;
        stack[top]=key;
    }
}

int pop(){
    int x=-1;
    if (top==-1){
        printf("stack underflow");
    }else{
        x=stack[top];
        top--;
    }
    return x;
}
void display(){
    int temp=top;
    while (temp!=-1)
    {
        printf("%d",stack[temp]);
        printf("\n");
        temp--;
    }
    
}
void main(){
   push(4);
   push(3);
   push(5);
   push(6);
   push(8);
   push(7);
   pop();
   pop();
   pop();
   display();
}