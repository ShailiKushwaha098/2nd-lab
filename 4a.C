#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
// Initialize stack
void initialize() {
    top = NULL;
    printf("Stack initialized successfully.\n");
}
// Check if empty
int isEmpty() {
    return (top == NULL);
}
// Check if full (for linked stack, it depends on memory)
int isFull() {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL)
        return 1;
    free(temp);
    return 0;
}
// Push operation
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Inserted: %d\n", value);
}
// Pop operation
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("Deleted: %d\n", temp->data);
    top = top->next;
    free(temp);
}
// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}
// Traverse stack
void traverse() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
// Main function (Menu)
int main() {
    int choice, value;
    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Initialize\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Peek\n");
        printf("5. Traverse\n");
        printf("6. Check Empty\n");
        printf("7. Check Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                initialize();
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 3:
                pop();
                break;
            case 4:
                peek();
                break;
            case 5:
                traverse();
                break;
            case 6:
                if (isEmpty())
                    printf("Stack is EMPTY.\n");
                else
                    printf("Stack is NOT EMPTY.\n");
                break;
            case 7:
                if (isFull())
                    printf("Stack is FULL.\n");
                else
                    printf("Stack is NOT FULL.\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}