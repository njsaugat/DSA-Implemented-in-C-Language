#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
void insert(int key,struct node* head){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=NULL;
    struct node* temp;
    if(head==NULL){
        head=temp=newnode;
    }else{
        temp->next=newnode;
        temp=newnode;
    }
}

int delete(struct node* head){
    int x=-1;
    struct node* p;
    if(head==NULL){
        return 0;
    }else{
        p=head;
        x=p->data;
        head=head->next;
        free(p);
        p=NULL;

    }
    return x;
}
int find_max(int arr[],int n){
    int max=-32768;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void bin_bucket_sort(int arr[],int n){
    int max=find_max(arr,n);
    struct node* barr[max+1];
    for(int i=0;i<=max;i++){
        barr[i]=NULL;
    }
    for(int i=0;i<n;i++){

        insert(arr[i],barr[i]);
    }
    int i=0;
    int j=0;
    while(i<=max){
        if(barr[i]->data){
            arr[j++]=delete(barr[i]);
        }else{
            i++;
        }
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}

void main(){
    int arr[] = {3, 3, 6, 2, 7, 2, 7, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bin_bucket_sort(arr,n);
    display(arr,n);
}