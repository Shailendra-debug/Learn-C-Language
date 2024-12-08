#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void deleteatlast(struct node *head);
struct node *nodeensrtatfast(struct node *head);
struct node *deleteatfast(struct node *head);
void insartatlast(struct node *head);
void insartatmead(struct node *head,int index);
void desplay(struct node *head);
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *fast=(struct node*)malloc(sizeof(struct node));
    struct node *sec=(struct node*)malloc(sizeof(struct node));
    struct node *therd=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=fast;
    fast->data=20;
    fast->next=sec;
    sec->data=22;
    sec->next=therd;
    therd->data=30;
    therd->next=NULL;
    desplay(head);
    head=nodeensrtatfast(head);
    printf("\n Inseratatfast\n");
    desplay(head);
    insartatlast(head);
    printf("\nInsartatlast\n");
    desplay(head);
    insartatmead(head,4);
    printf("\nInsartatmead\n");
    desplay(head);
    head=deleteatfast(head);
    printf("\nDeleteaatfast\n");
    desplay(head);
    deleteatlast(head);
    printf("\nDeleteaatleast\n");
    desplay(head);
    deleteatmead(head,2);
    printf("\nDeleteaatmead\n");
    desplay(head);

return 0;
}
void desplay(struct node *head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}
struct node *nodeensrtatfast(struct node *head){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=40;
    newnode->next=head;
    return newnode;
};
void insartatlast(struct node *head){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=50;
    newnode->next=NULL;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=newnode;
}
void insartatmead(struct node *head,int index){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=60;
    int i=2;
    while(i<=index){
        head=head->next;
        //printf("%d\n",i);
    i++;}
    newnode->next=head->next;
    head->next=newnode;
}
struct node *deleteatfast(struct node *head){
    struct node *newnode=head->next;
    free(head);
    return newnode;
};
void deleteatlast(struct node *head){
    struct node *tempnode;
    tempnode=head;
    tempnode=tempnode->next;
    while(tempnode->next!=NULL){
        tempnode=tempnode->next;
        head=head->next;
    }
    head->next=NULL;
    free(tempnode);
}

void deleteatmead(struct node *head,int index){
    struct node *newnode;
    int i=1;
    newnode=head;
    head=head->next;
    while(i<index){
        newnode=newnode->next;
        head=head->next;
        i++;
    }
    newnode->next=head->next;
    free(head);
    }
