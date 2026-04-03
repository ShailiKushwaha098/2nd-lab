#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
// Function to check if stack is empty
int isEmpty()
{
    return (top == -1);
}
// Function to check if stack is full
int isFull()
{
    return (top == MAX - 1);
}
// Function to create stack
void create()
{
    top = -1;
    printf("Stack created successfully!\n");
}
// Function to push element
void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed into stack\n", value);
    }
}
// Function to pop element
void pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! Cannot pop\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top--]);
    }
}
// Function to peek (peep top element)
void peep()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
    }
}
// Function to traverse stack
void traverse()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
// Main function (Menu-driven)
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Create Stack\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Peep (Top Element)\n");
        printf("5. Traverse\n");
        printf("6. Check if Empty\n");
        printf("7. Check if Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 3:
            pop();
            break;
        case 4:
            peep();
            break;
        case 5:
            traverse();
            break;
        case 6:
            if (isEmpty())
                printf("Stack is EMPTY\n");
            else
                printf("Stack is NOT EMPTY\n");
            break;
        case 7:
            if (isFull())
                printf("Stack is FULL\n");
            else
                printf("Stack is NOT FULL\n");
            break;
        case 8:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}