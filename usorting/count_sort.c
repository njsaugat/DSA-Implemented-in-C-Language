#include<stdio.h>
#include<stdlib.h>

int findmax(int arr[],int n){
    int max=-32768;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;

}

void count_sort(int arr[],int n){
    int max;
    max=findmax(arr,n);
    int c[8];
    for(int i=0;i<=max;i++){
        c[i]=0;
    }

    for(int i=0;i<n;i++){
        c[arr[i]]++;
    }
    int i=0;
    int j=0;
    while(i<=max){
        if(c[i]){
            arr[j++]=i;
            c[i]--;
        }
        else{
            i++;
        }
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        printf("\n");
    }
}

void main()
{
    int arr[] = {3, 3, 6, 2, 7, 2, 7, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    count_sort(arr, n);
    display(arr, n);
}