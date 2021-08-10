#include<stdlib.h>
#include<stdio.h>

void swap(int* a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int arr[],int n){
    int i,j,k;
    for(int i=0;i<n-1;i++){
        int j=i;
        for(int k=i;k<n;k++){
            if(arr[j] > arr[k]){
                j=k;
            }
        }
        swap(&arr[i],&arr[j]);
    }

}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf("\n");
    }
}

void main(){
    int arr[] = {43, 34, 66, 32, 7, 23, 76, 23, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr,n);
    display(arr,n);   
}