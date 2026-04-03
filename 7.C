#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *front=NULL,*rear=NULL;

void insert(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(rear==NULL) front=rear=newnode;
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void deletequeue(){
    if(front==NULL){ printf("Queue Empty\n"); return; }
    struct node* temp=front;
    printf("Deleted: %d\n",temp->data);
    front=front->next;
    if(front==NULL) rear=NULL;
    free(temp);
}

void display(){
    struct node* temp=front;
    if(front==NULL){ printf("Queue Empty\n"); return; }
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int ch;
    do{
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert(); break;
            case 2: deletequeue(); break;
            case 3: display(); break;
        }
    }while(ch!=4);
}
