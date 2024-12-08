#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node* insartatfast(struct node *head);
struct node* deleteatfast(struct node *head);
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *fast=(struct node*)malloc(sizeof(struct node));
    struct node *secnd=(struct node*)malloc(sizeof(struct node));
    struct node *therrd=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->prev=NULL;
    head->next=fast;
    fast->data=20;
    fast->next=secnd;
    fast->prev=head;
    secnd->data=30;
    secnd->next=therrd;
    secnd->prev=fast;
    therrd->data=40;
    therrd->next=NULL;
    therrd->prev=secnd;
    desplay(head);
    printf("\n Insartatfast\n");
    head=insartatfast(head);
    desplay(head);
    printf("\n Insartatlest\n");
    insartatlast(head);
    desplay(head);
    printf("\n Insartatmead\n");
    insartatmead(head,2);
    desplay(head);
    printf("\n DeleteAtFast\n");
    head=deleteatfast(head);
    desplay(head);
    printf("\n DeleteAtLast\n");
    deleteatlast(head);
    desplay(head);
    printf("\n DeleteAtMead\n");
    deleteatmead(head,1);
    desplay(head);
return 0;
}
void desplay(struct node *head){
    while(head!=NULL){
            printf("%d,",head->data);
        head=head->next;
    }
}
struct node* insartatfast(struct node *head){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=50;
    newnode->prev=NULL;
    head->prev=newnode;
    newnode->next=head;
    return newnode;
};
void insartatlast(struct node *head){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    head=head->next;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=newnode;
    newnode->data=60;
    newnode->prev=head;
    newnode->next=NULL;
}
void insartatmead(struct node *head,int index){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    for(int i=0;i<index-1;i++){
        head=head->next;
    }
    newnode->data=70;
    newnode->next=head->next;
    newnode->prev=head;
    head->next=newnode;
}
struct node* deleteatfast(struct node *head){
    struct node *ptr=head->next;
    ptr->prev=NULL;
    free(head);
    return ptr;
};
void deleteatlast(struct node *head){
    struct node *ptr;
    while(head->next!=NULL){
        head=head->next;
    }
    ptr=head;
    head=head->prev;
    head->next=NULL;
    free(ptr);
}
void deleteatmead(struct node *head,int index){
    struct node *ptr;
    for(int i=0;i<index;i++){
        head=head->next;
    }
    ptr=head;
    ptr=ptr->prev;
    ptr->next=head->next;
    ptr=head->next;
    ptr->prev=head->prev;
    free(head);
    }
