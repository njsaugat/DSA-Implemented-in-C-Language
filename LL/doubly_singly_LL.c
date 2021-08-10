#include<stdlib.h>
#include<stdio.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* head= NULL;

void create(int key){
    struct node* newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=newnode->prev=NULL;
    if (head==NULL){
        temp=head=newnode;
    }else{
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
}
void insert(int key, int pos){
    struct node* newnode, *temp,*q;
    newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=newnode->prev=NULL;
    if (head){
        if (pos==0){
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }else{
            temp=head;
            for(int i=0;i<pos &&temp;i++){
                q=temp;
                temp=temp->next;
            }
            newnode->next=temp;
            newnode->prev=q;
            if (temp){// temp agadi xa;s so yo null pani huna sakxa; so we check for that
                temp->prev=newnode;
            }
            q->next=newnode;
        }
    }

}
void delete(int pos){
    int x=-1;
    struct node*temp,*q;
    if(pos==1){
        temp=head;
        head=head->next;
        head->prev=NULL;
        x=temp->data;
        free(temp);
        temp=NULL;
    }
    else{
        temp=head;
        for (int i=0;i<pos-1&& temp;i++){
            q=temp;
            temp=temp->next;
        }
        q->next=temp->next;
        if (temp->next){
            temp->next->prev=q;
        }
        x=temp->data;
        free(temp);
        temp=NULL;
    } 
}
void reverse(){
    struct node* p=head, *q=NULL,*r=NULL;
    while (p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
        q->prev=p;
    }head=q;
}
void swap_reverse(){
    struct node* p=head,*q=NULL,*temp;
    while (p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;


        head=p;// harek step ma head lai update garena vane p ta null hunxa ; so we would be left with null
        p=p->prev;//p ko next ta fwak vaisakyo
    }
}

void display(){
    struct node* temp=head;
    while (temp)
    {
        printf("%d",temp->data);
        printf("\n");
        temp=temp->next;
    }
    
}
void main(){
    int arr[5]={32,23,67,89,43};
    for(int i=0;i<5;i++){
        create(arr[i]);
    }
    printf("\n");
    // display();
    // insert(33,0);
    // insert(45,2);
    // printf("\n");
    // display();
    // delete(3);
    // delete(1);
    // printf("\n");
    swap_reverse();
    display();

}
