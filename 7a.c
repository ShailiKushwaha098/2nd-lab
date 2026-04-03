#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// Create node (insert at end)
void create() {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
}

// Traverse
void traverse() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
void insert_begin() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

// Insert at end
void insert_end() {
    create();
}

// Insert at position (middle)
void insert_pos() {
    int pos, i = 1;
    struct node *newnode, *temp = head;

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        insert_begin();
        return;
    }

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

// Delete from beginning
void delete_begin() {
    struct node *temp;
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// Delete from end
void delete_end() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

// Delete from position (middle)
void delete_pos() {
    int pos, i = 1;
    struct node *temp = head;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_begin();
        return;
    }

    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Create\n2. Traverse\n");
        printf("3. Insert Beginning\n4. Insert End\n5. Insert any  Position\n");
        printf("6. Delete Beginning\n7. Delete End\n8. Delete any  Position\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: traverse(); break;
            case 3: insert_begin(); break;
            case 4: insert_end(); break;
            case 5: insert_pos(); break;
            case 6: delete_begin(); break;
            case 7: delete_end(); break;
            case 8: delete_pos(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}