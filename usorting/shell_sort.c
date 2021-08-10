#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int arr[],int n){
    
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }j++;
        arr[j]=temp;
    }
}


void shell_sort(int arr[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=1;i<n;i++){
            int temp=arr[i];
            int j=i-gap;
            while(j>=0 && arr[j]>temp){
                arr[j+gap]=arr[j];
                j=j-gap;
            }j=j+gap;
            arr[j]=temp;
        }
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}
void main(){
    int arr[] = {3, 3, 6, 2, 7, 2, 7, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    shell_sort(arr,n);
    display(arr,n);

}