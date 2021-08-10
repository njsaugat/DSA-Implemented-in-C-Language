#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* tail=NULL;

void create(){
    struct node* newnode,*tail;
    int x,choice=1;
    while(choice){
        newnode=(struct node*) malloc(sizeof(struct node));
        printf("enter data in list  ");
        scanf("%d",&x);
        newnode->data=x;
        newnode->next=NULL;
        if (head==NULL){
            tail=head=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }tail->next=head; // we kinnda maintain double pointers; 
        printf("do you want to continue;enter 1; else 0 ");
        scanf("%d",&choice);
    }
}
void arr_create(int key){
    struct node* newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=key;
    // newnode->next=NULL;
    if (head==NULL){
        tail=head=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
    tail->next=head;
}
void display(){
    struct node* temp=head;
    while(temp->next!=head){
        printf("\n");
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
    printf("%d",temp->data);

}
void insert(int key,int pos){
    struct node* newnode, *temp,*q=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    if (head){
        if (pos==0){
            newnode->next=head;
            head=newnode;
            tail->next=newnode;
        }else{
            temp=head;
            for (int i=0;i<pos &&temp;i++){
                q=temp;
                temp=temp->next;
            }
            newnode->next=temp;
            q->next=newnode;
            if(tail==q){ //we have to move the tail pointer as well
                tail=newnode;
            }
        }
    }

}
int delete(int pos){
    struct node* temp,*q=NULL;
    int x=-1;
    if (head){
        if (pos==1){
            temp=head;
            head=head->next;
            tail->next=head;
            x=temp->data;
            free(temp);
            temp=NULL;
        }else{
            temp=head;
            for (int i = 0; i < pos-1 && temp; i++){
                q=temp;
                temp=temp->next;
            }q->next=temp->next;
            x=temp->data;
            if(temp==tail){//if we are removing last element then tail has to be modified
                tail=q;
            }
            free(temp);
            temp=NULL;
        }
        return x;
    }
}
void reverse(){
    struct node* p=head, *q=NULL, *r=NULL;
    // tail=head;
    while (p->next!=head){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    p->next=q;// one extra last element won't be swapped bcz of the while loop's condition; so we reverse that last by ourselves
    tail=head; // swapping head and tail; no need of third pointer because we have a pointer p
    head=p;// p was actually at last so it was last
}
void re_reverse(struct node* p, struct node* q){
    if(p->next!=head){
        re_reverse(p->next,p);
        p->next=q; //yaha ni xa 
    }else{
        p->next=q; //yaha ni same xa ; so duitai lai we can write out of if statement and everytime it would go outta the if to execte this 
        tail=head;// swapping like iterative ones
        head=p;
    }
    // p->next=q;// we need to make paxadi ko pointer to point agadi ani reverse hunxa; so this step becomes common in if blocks;and recursion maintains the pointers so no need of 3 pointers 
}
void main(){
    // create();
    int arr[5]={22,32,55,66,45};//{46,22,32,12,55,66,45,25,}
    for (int i = 0; i < 5; i++){
        arr_create(arr[i]);
    }
    display();
    printf("\n");
    insert(12,3);
    insert(25,6);
    insert(46,0);
    insert(65,1);
    display();
    // delete(3);
    // delete(6);
    printf("\n");
    delete(9);
    display();
    // printf("\n");
    // display();
    // printf("\n");
    // re_reverse(head,NULL);
    // display();
}