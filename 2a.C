#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create node (insert at end initially)
void create()
{
    struct node *newnode, *temp;
    int val;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &val);

    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

// Traverse
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
void insert_begin()
{
    struct node *newnode;
    int val;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &val);

    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

// Insert at end
void insert_end()
{
    create();
}

// Insert at middle (after position)
void insert_middle()
{
    struct node *newnode, *temp = head;
    int val, pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter value: ");
    scanf("%d", &val);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    for (i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete from beginning
void delete_begin()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void delete_end()
{
    struct node *temp = head, *prev;

    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Delete from middle
void delete_middle()
{
    struct node *temp = head, *prev;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }

    if (pos == 1)
    {
        delete_begin();
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Main menu
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Create\n2. Display\n3. Insert Begin\n4. Insert Middle\n5. Insert End\n");
        printf("6. Delete Begin\n7. Delete Middle\n8. Delete End\n9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_begin();
            break;
        case 4:
            insert_middle();
            break;
        case 5:
            insert_end();
            break;
        case 6:
            delete_begin();
            break;
        case 7:
            delete_middle();
            break;
        case 8:
            delete_end();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}