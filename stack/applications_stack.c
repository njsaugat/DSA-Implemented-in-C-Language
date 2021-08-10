#include <stdio.h>
#include <stdlib.h>
#include "stack_LL.h"// header ma main function rakhna vaena; comment garera ni rakhna hunna else tyaha 
//bata execute hunxa; so delete any main function in header files

// applications of stacks are implemented using linked list 
// can be even implemented using array

int paranthesis_match(char exp[]){// array pointer ra structure lai function call ma pathauna milxa
    int i=0;
    int x=-1;
    while(exp[i]!='\0'){
        if(exp[i]=='('){
            push(exp[i]);
        }else if(exp[i]==')'){
            x=pop();
            if(x==-1){
                return 0;
            }
        }
        i++;
    }
    if (isEmpty()){
        return 1;
    }return 0;
}

int complex_paranthesis_match(char exp[]){
    int x;
    for(int i=0; exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(exp[i]);
        }else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            x=pop();// fail cases haru lai test garna parxa; instead of writing 3 if statemensts i can combine them into 1; anyone gets true then it is not mathcing
            if( (x=='(' && exp[i]!=')') || (x=='[' && exp[i]!=']') ||  (x=='{' && exp[i]!='}')){ 
                return 0;
            }else if (x==-1){// tyo  ( ( ) ) ) esto khalko condition vayo vane lai check garna ho
                return 0;
            }
        }
    }if (isEmpty()){// mathi ko function ko exagerration maatra ho yo; yaha ni stack empty xaina vane paranthesis match no
        return 1;
    }return 0;
}
int is_operand(char c){
    if(c=='+'|| c=='-' || c=='*' || c=='/' || c=='(' || c==')'){
        return 0;
    }return 1; // if above condition is not satisfied, then obviously it is not operator ie is operand 
}
int precedence(char c){
    if (c=='+' || c=='-'){
        return 1;
    }else if (c=='*' || c=='/'){
        return 2;
    }else if (c=='(' || c==')'){
        return -1;
    }return 0;
}
char infix_postfix(char inf[],int size){
    int i=0,  j=0;
    char postfix[20];
    while(inf[i]!='\0'){
        if(is_operand(inf[i])){
            postfix[j++]=inf[i++];
        }else{
            char x=stackTop();
            if(precedence(x)<precedence(inf[i])){
                push(inf[i++]);
            }else{
                postfix[j++]=pop();
            }
        }
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j++]='\0';
    // return postfix;
    for(int i=0; postfix[i]!='\0'; i++){
        printf("%c", postfix[i]);
        // printf("\n");
    }
}
char infix_postfix_brackets(char inf[],int size){
    int i=0,  j=0;
    char postfix[20];
    while(inf[i]!='\0'){
        if(is_operand(inf[i])){
            postfix[j++]=inf[i++];
        }
        else if(inf[i]=='('){
            push(inf[i++]);
        }
        else if(inf[i]==')'){
            char x=stackTop();
            if(x=='('){
                pop();
                i++;
            }else{
                postfix[j++]=pop();
            }
        }
        else{
            char x=stackTop();
            if(precedence(x)<precedence(inf[i])){
                push(inf[i++]);
            }else{
                postfix[j++]=pop();
            }
        }
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j++]='\0';
    // return postfix;
    for(int i=0; postfix[i]!='\0'; i++){
        printf("%c", postfix[i]);
        // printf("\n");
    }
}
postfix_infix(){}
int csize(char exp[]){
    for(int i=0; exp[i]!='\0'; i++)
    return i+1;
}
void strDisplay(char exp[]){
    for(int i=0; exp[i]!='\0'; i++){
        printf("%c", exp[i]);
        printf("\n");
    }
}
void main(){
//     char exp[]="[({)]";
//     int x=complex_paranthesis_match(exp);
//     if(x){
//         printf("the paranthesis match");
//     }else{
//         printf("the paranthesis do not match");
//    }
    char exp[]="((a+b)-((c*d)/e))";
    int size=csize(exp);
    char postfix= infix_postfix_brackets(exp, size);
    // strDisplay(postfix);
}