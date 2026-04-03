#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List Empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_begin()
{
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insert_end()
{
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

int main()
{
    int ch;
    do
    {
        printf("\n1.Display\n2.Insert Begin\n3.Insert End\n4.Delete Begin\n5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_begin();
            break;
        }
    } while (ch != 5);
}
