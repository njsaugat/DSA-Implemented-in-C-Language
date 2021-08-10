#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node* next;
};
struct node* create()
{
    struct node* head=NULL,*newnode,*temp;
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
struct node* head= NULL;
struct node* icreate(int x)
{
    struct node* newnode,*temp;
    int choice=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if (head==NULL){
        temp=head=newnode;
        return head;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }   
}
void display(struct node* head){
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
int count(struct node* head){
    int count=0;
    struct node* temp=head;
    while(temp){
        count=count+1;
        temp=temp->next;
    }
    return count;
}
int sum(struct node* head){
    int sum=0;
    struct node* temp=head;
    while(temp){
        sum=sum+temp->data;
        temp=temp->next;
    }
    return sum;
}
int maxi(struct node* temp){
    int imax=INT_MIN;
    while(temp){
        if (temp->data>imax){
            imax=temp->data;
        }
        temp=temp->next;
    }
    return imax;
}
struct node* search(struct node* temp, int key){
    while(temp){
        if (key==temp->data){
            return temp;
        }
        temp=temp->next;
    }
}
struct node* improve_search(struct node* head, int key){
    struct node* temp=head,*q=NULL;
    while(temp){
        if (key==temp->data){
            q->next=temp->next;
            temp->next= head;
            head=temp;
            return head;
        }
        q=temp;
        temp=temp->next;
    }
}

void main(){
    // struct node* head=create();
    // display(head);
    struct node* head;
    int arr[5]={11,22,32,21,23};
    head=icreate(arr[0]); //we couldn't have taken the value but chose to bcz we want the head pointer 
    for(int i=1; i<5;i++){
        icreate(arr[i]); //although the function returns a pointer to a struct node, it's our choice whether to store that returned value or not
    }
    display(head);
    // printf("%d",head);
    printf("%d",sum(head));
    printf("\n");
    printf("%d",count(head));
    printf("\n");
    printf("%d",maxi(head));
    printf("\n");
    struct node* head1= improve_search(head,23);
    if (head1){
        printf("the element is present");
        head=head1;
    }
    else{
        printf("the element isnot present");

    }
    printf("%d",head->data);
    printf("\n");
    display(head);
}