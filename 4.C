#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;

void push() {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}

void pop(){
    if(top==NULL){ printf("Stack Empty\n"); return; }
    struct node* temp=top;
    printf("Deleted: %d\n",temp->data);
    top=top->next;
    free(temp);
}

void display(){
    struct node* temp=top;
    if(top==NULL){ printf("Stack Empty\n"); return; }
    while(temp!=NULL); {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int ch;
    do{
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
        }
    }while(ch!=4);
}
