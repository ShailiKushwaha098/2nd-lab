#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};
struct node* head=NULL;

void insert_begin(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=head;
    if(head!=NULL) head->prev=newnode;
    head=newnode;
}

void delete_begin(){
    if(head==NULL){ printf("Empty\n"); return; }
    struct node* temp=head;
    head=head->next;
    if(head!=NULL) head->prev=NULL;
    free(temp);
}

void display(){
    struct node* temp=head;
    if(head==NULL){ printf("Empty\n"); return; }
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int ch;
    do{
        printf("\n1.Insert Begin\n2.Delete Begin\n3.Display\n4.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert_begin(); break;
            case 2: delete_begin(); break;
            case 3: display(); break;
        }
    }while(ch!=4);
}
