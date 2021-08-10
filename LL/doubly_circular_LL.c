#include<stdio.h>
#include<stdlib.h>
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
    temp->next=head;
    head->prev=temp;
}

void insert(int key, int pos){
    struct node* newnode, *temp,*q;
    newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=newnode->prev=NULL;
    if (head){
        if (pos==0){
            newnode->next=head;
            newnode->prev=head->prev;
            head->prev->next=newnode;
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

void display(){
    struct node* temp=head;
    while (temp->next!=head)
    {
        printf("%d",temp->data);
        printf("\n");
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n");    
}

void delete(int pos){
    int x=-1;
    struct node*temp,*q;
    if(pos==1){
        temp=head;
        head->next->prev=head->prev;
        head->prev->next=head->next;
        head=head->next;
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
    struct node* p=head, *q=head->prev,*r=NULL;
    while (p->next!=head)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
        q->prev=p;
    }
    p->next=q;//at last p->next!=head le garda p will be on tail so both tails and prev have to changed
    p->prev=head;
    head=p;
}
void swap_reverse(){
    struct node* p=head,*temp;
    while (p->next!=head)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;


        // head=p;// harek step ma head lai update garena vane p ta null hunxa ; so we would be left with null;
        // yaha yo step necessary xaina bcz yaha ta tail bata head ma reach garna sakinxa 
        p=p->prev;//p ko next ta fwak vaisakyo
    }
    p->next=p->prev;// yo step haru ma baki raheko euta lai modify garna parxa
    p->prev=head;
    head=p;
}
void main(){
    int arr[5]={32,23,67,89,43};
    for(int i=0;i<5;i++){
        create(arr[i]);
    }
    // insert(34,0);
    // insert(65,1);
    // // insert(79,4);
    // delete(1);
    // delete(2);
    // delete(4);
    swap_reverse();
    display();
}
