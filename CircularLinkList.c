#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *insartatfast(struct node *head);
struct node *deleteatfast(struct node *head);
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *fast=(struct node*)malloc(sizeof(struct node));
    struct node *secand=(struct node*)malloc(sizeof(struct node));
    struct node *therrd=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=fast;
    fast->data=20;
    fast->next=secand;
    secand->data=30;
    secand->next=therrd;
    therrd->data=40;
    therrd->next=head;
    desplay(head);
    printf("\n");
    head=insartatfast(head);
    desplay(head);
    printf("\n");
    insartatlast(head);
    desplay(head);
    printf("\n");
    insartatmead(head,2);
    desplay(head);
    printf("\n Delete Fast\n");
    head=deleteatfast(head);
    desplay(head);
    printf("\n Delete Mead\n");
    deleteatmead(head,2);
    desplay(head);
    printf("\n Delete Lest\n");
    deleteatlast(head);
    desplay(head);
}
void desplay(struct node *head){
    struct node *ptr;
    ptr=head;
    do{
        printf("%d,",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node *insartatfast(struct node *head){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    newnode->data=60;
    newnode->next=ptr;
    ptr=newnode;
    do{
        ptr=ptr->next;
    }while(ptr->next!=head);
    ptr->next=newnode;
    return newnode;
};
void insartatlast(struct node *head){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    newnode->data=70;
    do{
        ptr=ptr->next;
    }while(ptr->next!=head);
    newnode->next=ptr->next;
    ptr->next=newnode;
}
void insartatmead(struct node *head,int index){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    int i=0;
    struct node *ptr=head;
    newnode->data=90;
    while(i<index-1){
        ptr=ptr->next;
        i++;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
}
struct node *deleteatfast(struct node *head){
    struct node *ptr;
    struct node *temp;
    ptr=head;
    do{
        ptr=ptr->next;
    }while(ptr->next!=head);
    ptr->next=head->next;
    temp=head->next;
    free(head);
    return temp;
};
void deleteatmead(struct node *head,int index){
    struct node *ptr=head;
    int i=1;
    ptr=ptr->next;
    while(i<index-1){
        head=head->next;
        ptr=ptr->next;
        i++;
    }
    head->next=ptr->next;
    free(ptr);
}
void deleteatlast(struct node *head){
    struct node *ptr=head;
    struct node *temp=head;
    temp=temp->next;
    do{
        ptr=ptr->next;
        temp=temp->next;
    }while(temp->next!=head);
    ptr->next=head;
    free(temp);
}
