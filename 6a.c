#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Initialize queue
void initialize(struct Queue *q) {
    q->front = q->rear = NULL;
}

// Check if queue is empty
int is_empty(struct Queue *q) {
    return (q->front == NULL);
}

// Check if queue is full (for linked list, only when memory is full)
int is_full() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL)
        return 1;
    free(temp);
    return 0;
}

// Insert element (Enqueue)
void insert(struct Queue *q, int value) {
    if (is_full()) {
        printf("Queue is FULL\n");
        return;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (is_empty(q)) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    printf("Inserted: %d\n", value);
}

// Delete element (Dequeue)
void delete(struct Queue *q) {
    if (is_empty(q)) {
        printf("Queue is EMPTY\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Deleted: %d\n", temp->data);

    q->front = q->front->next;
    free(temp);

    if (q->front == NULL)
        q->rear = NULL;
}

// Traverse queue
void traverse(struct Queue *q) {
    if (is_empty(q)) {
        printf("Queue is EMPTY\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main menu
int main() {
    struct Queue q;
    initialize(&q);

    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Traverse\n4. isEmpty\n5. isFull\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(&q, value);
                break;

            case 2:
                delete(&q);
                break;

            case 3:
                traverse(&q);
                break;

            case 4:
                if (is_empty(&q))
                    printf("Queue is EMPTY\n");
                else
                    printf("Queue is NOT EMPTY\n");
                break;

            case 5:
                if (is_full())
                    printf("Queue is FULL\n");
                else
                    printf("Queue is NOT FULL\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}