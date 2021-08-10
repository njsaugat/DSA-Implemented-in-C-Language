#include <stdio.h>
int sum(int a, int b){
    int s;
    a=5;
    s=a+b;
    return a;
}
int a=3
int*p=&a;
int a=1;
int main(){
    a=sum(12,12);
    printf("%d",a);
}