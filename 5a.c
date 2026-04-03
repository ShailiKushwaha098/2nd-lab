#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Initialize queue
void initialize() {
    front = rear = -1;
    printf("Queue initialized\n");
}

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Insert (Enqueue)
void insert(int value) {
    if (isFull()) {
        printf("Queue is FULL\n");
        return;
    }

    if (front == -1) // first element
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("Inserted: %d\n", value);
}

// Delete (Dequeue)
void delete() {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1; // queue becomes empty
    } else {
        front = (front + 1) % SIZE;
    }
}

// Traverse
void traverse() {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Initialize\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Traverse\n");
        printf("5. Check Empty\n");
        printf("6. Check Full\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initialize();
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 3:
                delete();
                break;

            case 4:
                traverse();
                break;

            case 5:
                if (isEmpty())
                    printf("Queue is EMPTY\n");
                else
                    printf("Queue is NOT EMPTY\n");
                break;

            case 6:
                if (isFull())
                    printf("Queue is FULL\n");
                else
                    printf("Queue is NOT FULL\n");
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}