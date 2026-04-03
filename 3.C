#include<stdio.h>
#define MAX 5

int stack[MAX], top=-1;

void push(){
    if(top==MAX-1){ printf("Stack Full\n"); return; }
    int val;
    printf("Enter value: ");
    scanf("%d",&val);
    stack[++top]=val;
}

void pop(){
    if(top==-1){ printf("Stack Empty\n"); return; }
    printf("Deleted: %d\n",stack[top--]);
}

void peek(){
    if(top==-1){ printf("Stack Empty\n"); return; }
    printf("Top Element: %d\n",stack[top]);
}

void display(){
    if(top==-1){ printf("Stack Empty\n"); return; }
    for(int i=top;i>=0;i--)
        printf("%d ",stack[i]);
    printf("\n");
}

int main(){
    int ch;
    do{
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    }while(ch!=5);
}
