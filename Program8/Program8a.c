#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// a) Insert into BST
struct node *insert(struct node *root, int value){
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert (root->right, value);
    return root;
}
// traversals

// Inorder
void inorder (struct node *root){
    if (root == NULL) return;
        inorder (root->left);
    printf("%d", root->data);
    inorder (root->right);
}

// Preorder
void preorder (struct node *root) {
    if (root==NULL) return;
        printf("%d", root->data);
    preorder (root->left);
    preorder (root->right);
}

// Postorder
void postorder (struct node *root){
    if (root == NULL) return;
        postorder (root->left);
    postorder (root->right);
    printf ("%d", root->data);
}

// Display BST elements. (using inorder)
void display (struct node *root) {
    printf (" BST Elements (Inorder); ");
    inorder (root);
    printf("\n");
}
int main()
{
    struct node *root = NULL;
    int choice, value;
    while(1)
    {
        printf("--- BST Menu ---\n");
        printf("1. Insert into BST\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Display BST\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                display(root);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
