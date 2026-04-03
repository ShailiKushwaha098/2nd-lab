#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Create node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert
struct node* insert(struct node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Traversals
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int choice, n, val;

    do {
        // 👉 MENU FIRST
        printf("\n===== BST MENU =====\n");
        printf("1. Insert Elements (Bulk)\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);

                printf("Enter %d values:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    root = insert(root, val);
                }
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is empty!\n");
                else {
                    printf("Preorder: ");
                    preorder(root);
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is empty!\n");
                else {
                    printf("Inorder: ");
                    inorder(root);
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty!\n");
                else {
                    printf("Postorder: ");
                    postorder(root);
                }
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