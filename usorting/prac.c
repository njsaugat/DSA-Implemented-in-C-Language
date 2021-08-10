#include<stdio.h>
#include<stdlib.h>
void insert(int arr[], int key,int n){
    int i=n-1;
    while(i>0 && arr[i]>key ){
        arr[i]=arr[i-1];
        i--;
    }
    arr[i++]=key;
}

void insertion_sort(int arr[], int n){
    for(int i=1;i<=n;i++){
        int key=arr[i];int j=i;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j++]=key;
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
        printf("\n");
    }
}
void main(){
    int arr[7]={12,14,32,100};
    int n= sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    display(arr,n);
}