#include<stdio.h>
#include<stdlib.h>


void sorted_insert(int arr[],int key,int n){
    int i=n;
    while(i>=0){
        if(arr[i]>key){
            arr[i+1]=arr[i];
        }
        i--;
    }
    arr[i++]=key;
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
        printf("\n");
    }
}
void main(){
    int arr[]={23,56,67,86,76};
    int size=sizeof(arr)/sizeof(arr[0]);
    sorted_insert(arr,54,size);
    display(arr,size);
}