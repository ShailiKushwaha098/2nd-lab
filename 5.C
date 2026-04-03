#include<stdio.h>
#define MAX 5

int queue[MAX], front=-1, rear=-1;

void insert(){
    int val;
    if((front==0 && rear==MAX-1) || (rear+1)%MAX==front){
        printf("Queue Full\n"); return;
    }
    printf("Enter value: ");
    scanf("%d",&val);

    if(front==-1) front=0;
    rear=(rear+1)%MAX;
    queue[rear]=val;
}

void delete(){
    if(front==-1){ printf("Queue Empty\n"); return; }
    printf("Deleted: %d\n",queue[front]);

    if(front==rear) front=rear=-1;
    else front=(front+1)%MAX;
}

void display(){
    if(front==-1){ printf("Queue Empty\n"); return; }
    int i=front;
    while(1){
        printf("%d ",queue[i]);
        if(i==rear) break;
        i=(i+1)%MAX;
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
            case 2: delete(); break;
            case 3: display(); break;
        }
    }while(ch!=4);
}
