#include <stdio.h>
#include <stdlib.h>
#include <E:\c progamming\DSA\stack\prac\LLhead.h>
int paranthesis_match(char exp[]){
    int i=0;
    while(exp[i]!='\0'){
        if(exp[i]=='('){
            push(exp[i]);
        }else if(exp[i]==')'){
            char x=pop();
            if (x==-1){
                return 0;
            }
        }
    }
    if(!isEmpty()){
        return 1;
    }return 0;
}

int isOperand(char c){
    if (c=='+'|| c=='-' || c=='*' || c=='/' || c==')' || c=='('){
        return 0;
    }return 1;
}
int precedence(char c){
    if ( c=='-'|| c=='+'){
        return 1;
    }else if(c=='*'|| c=='/'){
        return 2;
    }else if(c==')'|| c=='('){
        return -1;
    }
    return 1;
}
char* infix_postfix(char inf[], int size){
    int i=0, j=0;
    char post[size];
    while(inf[i]!='\0'){
        if(isOperand(inf[i])){
            post[j++]=inf[i++];
        }else{
            char x=stackTop();
            if (precedence(x)<precedence(inf[i])){
                push(inf[i++]);
            }else{
                post[j++]=pop();
            }
        }
    }while(!isEmpty()){
        post[j++]=pop();
    }
    return post;
}

void main(){
    // char exp[]="(()))))";
    // int x=paranthesis_match(exp);
    // if(x){
    //     printf("paranthesis match");
    // }else{
    //     printf("paranthesis match");
    // }
    char inf="a+b-c";
    char* post=infix_postfix(inf, 5);
    for(int i=0;post[i]!='\0';i++){
        printf("%c",post[i]);
    }
}
