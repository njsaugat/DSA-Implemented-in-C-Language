// advantage of using global head is that it can be accessed by each function and make changes in the head's value; as the head is in
// heap, changing its' value is fairly easy for the function
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node* next;
};

struct node* head=NULL;

struct node* create()
{
    struct node*newnode,*temp;
    int choice=1;
    while(choice==1)
    {   int x;
        printf("enter data : ");
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;
        if (head==NULL){
            temp=head=newnode;}
        else{
            temp->next=newnode;
            temp=newnode;
        }    
        printf("enter 1 if you want to insert more and 0 for quit ");
        scanf("%d",&choice);
    }
    return head;
}
void icreate(int x)
{
    struct node* newnode,*temp;
    int choice=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if (head==NULL){
        temp=head=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }   
}
void display(){
    struct node* temp=head;
    while(temp){
        printf("%d",temp->data);
        printf("\n");
        temp=temp->next;
    }
}
void rdisplay(struct node* temp){
    if(temp!=NULL){
        printf("%d",temp->data);
        printf("\n");
        rdisplay(temp->next);

    }
}
int count(){
    int count=0;
    struct node* temp=head;
    while(temp){
        count=count+1;
        temp=temp->next;
    }
    return count;
}
int sum(){
    int sum=0;
    struct node* temp=head;
    while(temp){
        sum=sum+temp->data;
        temp=temp->next;
    }
    return sum;
}
int maxi(){
    struct node* temp= head;
    int imax=INT_MIN;
    while(temp){
        if (temp->data>imax){
            imax=temp->data;
        }
        temp=temp->next;
    }
    return imax;
}
struct node* search(int key){
    struct node* temp= head;
    while(temp){
        if (key==temp->data){
            return temp;
        }
        temp=temp->next;
    }
}
struct node* improve_search(int key){
    struct node* temp=head,*q=NULL;
    while(temp){
        if (key==temp->data){
            q->next=temp->next;
            temp->next= head;
            head=temp;
        }
        q=temp;
        temp=temp->next;
    }
}
void insert(int key, int pos){
    struct node* temp=head, *q,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if (head){    
        if (pos==0){
            newnode->data=key;
            newnode->next=head;
            head=newnode;
        }
        else{
            q=NULL;
            for(int i=0;i<pos && temp;i++){// if pos-1 vayo vane inserting after 1st position won't be possible bcz 0<1-1;0<0 would hit and q wont be declared
                q=temp;
                temp=temp->next;
            }
            newnode->data=key;
            newnode->next=temp;
            q->next=newnode;
        }
    }
}


void insert_at_last(int key){ //since we are inserting at last, we dont need positon
    struct node* tail, *q,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=NULL;
    if(head==NULL){
        tail=head=newnode;
    }else{
        tail->next=newnode;
        tail=newnode;
    }
}
void sorted_insert(int key){
    struct node* newnode, *temp=head,*q;
    while(temp->data<key && temp){
        q=temp;
        temp=temp->next;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=temp;
    q->next=newnode;
}
int delete(int pos){
    int x=-1;
    struct node* temp,*q=head;    
    if (pos==1){
        temp=head;
        head=head->next;
        x=temp->data;
        free(temp);
        temp=NULL;
    }else{
        for(int i=0;i<pos-2 && q;i++){ //pos-2; so only 1 pointer inside for;and q  is moving ahead from left to right; and check for q
            q=q->next;
        }
        temp=q->next;//temp is ahead now
        q->next=temp->next;
        x=temp->data;
        free(temp);
        temp=NULL;
    }
    return x;

}
int is_sorted(){
    struct node* temp=head;//assume that head is not null
    while(temp && ((temp->next)->data)>temp->data){
        temp=temp->next;
    }
    if (temp==NULL){//temp null kahile hunxa; when entire linked list is traversed then only it is null
        return 1;
    }else{
        return 0;
    }
}

void reverse(){
    struct node*p,*q,*r;
    p=head;
    q=r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}

void rec_reverse(struct node*p, struct node*q){
    if(p){
        // q=p;
        rec_reverse(p->next, p);
        p->next=q;
    }else{
        head=q;
    }
}



void main(){
    // struct node* head=create();
    // display(head);
    
    int arr[5]={11,22,32,21,23};//{72,26,11,65,22,32,21,23}
    for(int i=0; i<5;i++){
        icreate(arr[i]);
    }
    insert(72,0);
    insert(26,1);
    insert(65,3);
    insert(53,8);
    display();
    delete(2);
    printf("\n");
    display();
    // display(head);
    // // printf("%d",head);
    // printf("%d",sum());
    // printf("\n");
    // printf("%d",count());
    // printf("\n");
    // printf("%d",maxi());
    // printf("\n");
    // struct node* temp= improve_search(23);
    // if (temp){    //     printf("the element is present");
    // }
    // else{
    //     printf("the element isnot present");

    // }
    // printf("%d",head->data);
    // printf("\n");
    // display(head);
    // printf("\n");
    // insert(65,4);
    // insert(15,0);
    // printf("\n");
    // insert_at_last(3);
    // insert_at_last(12);
    // insert_at_last(21);
    // insert_at_last(31);
    // insert_at_last(42);
    // insert_at_last(47);
    // insert_at_last(1);// if this is elsewhere the tail's location is dismissed
    // display();
    // sorted_insert(32);
    // printf("\n");
    // // display();
    // int z= delete(6);
    // int y=delete(1);
    // printf("\n");
    // display();
    // if  (is_sorted()){
    //     printf("the list is sorted");
    // }else{
    //     printf("the list is not sorted");
    // }
    // printf("\n");
    // reverse();
    // display();
    // printf("\n");
    // rec_reverse(head,NULL);
}