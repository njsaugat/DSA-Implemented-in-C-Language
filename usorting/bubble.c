#include<stdio.h>
#include<stdlib.h>

void swap(int* x, int* y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void bubble(int arr[],int n){
    for(int j=0;j<n;j++){
        if(arr[j]>arr[j+1]){
            swap(&arr[j],&arr[j+1]);
        }
    }
}

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){// last ma ta sorted hunxa;so 1 less choti pass;n elements n-1 passes
        for(int j=0;j<n-i-1;j++){// ek pass ma 2 elements lai compare garna parne vaera 1 less hunca;n-i garna parxa bcz 1st start bata milauda last ko already sorted
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}


void bubble_sorted_imp(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int flag=0;// harek pass ma flag lai 0 parne; 
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag=1;// swap garexi matra flag lai 1 parne
            }
        }if(flag==0){// this means that no work is to be done ie the list is already sorted;
            break;
        }
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
        printf("\n");
    }
}
void main(){
    // int arr[]={5,6,3,7,2,12,9};
    int arr[]={1,2,3,4,5,6,17};
    int size=(sizeof(arr)/sizeof(arr[0]));
    bubble_sorted_imp(arr,size);
    display(arr, size);
}