#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* insert(int key,struct node* head){
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
    return head;
}

struct node* delete(struct node* head){
    int x=-1;
    struct node* p;
    if(head==NULL){
        return 0;
    }else{
        
        
    }
    return p;
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

void bin_bucket_sort(){
    int arr[] = {3, 3, 6, 2, 7, 2, 7, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max=-32768;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    struct node* barr[10];
    for(int i=0;i<=max;i++){
        // (*barr[i]).data=0;
        barr[i]=NULL;
    }
    for(int i=0;i<n;i++){

        struct node* head=insert(arr[i],barr[arr[i]]);
        if (barr[arr[i]]==NULL){
            barr[arr[i]]=head;
        }
    }
    int i=0;
    int j=0;
    while(i<=max){
        if(barr[i]==NULL){
            i++;
        }else if(barr[i]!=NULL){
            struct node* p,*temp;
            p=temp=barr[i];
            int x=p->data;
            p=p->next;
            arr[j++]=x;
            free(temp);
            temp=NULL;
        }
    }

    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}

void main(){
  
    bin_bucket_sort();
    // display();
}