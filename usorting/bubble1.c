#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf("\n");
    }
}
void main(){
    int arr[]={43,34,66,32,87,23,76,23,32};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    display(arr,n);
}