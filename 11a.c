#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert node
struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search node
struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum node
struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete node
struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node* root = NULL;
    int n, value, choice, key, i;

    // Bulk insertion first
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Menu options after insertion
    while (1)
    {
        printf("\n--- BST MENU ---\n");
        printf("1. Search Element\n");
        printf("2. Delete Element\n");
        printf("3. Display BST (Inorder)\n");
        printf("4. Insert New Element\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);

                if (search(root, key))
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &key);

                root = deleteNode(root, key);
                printf("Element deleted\n");
                break;

            case 3:
                printf("BST elements are: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Enter new element: ");
                scanf("%d", &value);

                root = insert(root, value);
                printf("Element inserted\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
