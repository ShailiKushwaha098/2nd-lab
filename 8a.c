#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial node
struct Node {
    int coeff;
    int power;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int p) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->power = p;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
struct Node* insert(struct Node* head, int c, int p) {
    struct Node* temp = createNode(c, p);

    if (head == NULL)
        return temp;

    struct Node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    return head;
}

// Display polynomial
void display(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->power);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->power == p2->power) {
            result = insert(result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power) {
            result = insert(result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else {
            result = insert(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    // Remaining terms
    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

// Main function (Menu)
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, coeff, power, choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Create Polynomial 1\n");
        printf("2. Create Polynomial 2\n");
        printf("3. Display Polynomials\n");
        printf("4. Add Polynomials\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter number of terms: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter coeff and power: ");
                scanf("%d %d", &coeff, &power);
                poly1 = insert(poly1, coeff, power);
            }
            break;

        case 2:
            printf("Enter number of terms: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter coeff and power: ");
                scanf("%d %d", &coeff, &power);
                poly2 = insert(poly2, coeff, power);
            }
            break;

        case 3:
            printf("Polynomial 1: ");
            display(poly1);
            printf("Polynomial 2: ");
            display(poly2);
            break;

        case 4:
            result = addPoly(poly1, poly2);
            printf("Resultant Polynomial: ");
            display(result);
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}