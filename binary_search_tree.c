#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the BST
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);  // Create a new node if tree is empty
    }
    if (value < root->data) {
        root->left = insert(root->left, value);  // Insert in the left subtree
    } else if (value > root->data) {
        root->right = insert(root->right, value);  // Insert in the right subtree
    }
    return root;
}

// Function to find the minimum value node in the right subtree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;  // Go as far left as possible
    }
    return root;
}

// Function to delete a node in the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;  // If the tree is empty or the value is not found
    }

    // Traverse the tree to find the node to delete
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node to be deleted found
        if (root->left == NULL && root->right == NULL) {
            // Case 1: Node has no children (leaf node)
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            // Case 2: Node has only a right child
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Case 2: Node has only a left child
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Case 3: Node has two children
            struct Node* temp = findMin(root->right);  // Find the inorder successor
            root->data = temp->data;  // Copy the successor's value to the current node
            root->right = deleteNode(root->right, temp->data);  // Delete the successor
        }
    }
    return root;
}

// Function for in-order traversal (left -> root -> right)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Perform in-order traversal
    printf("In-order traversal of the BST: ");
    inOrder(root);
    printf("\n");

    // Delete a node and display the tree
    printf("Deleting node 20...\n");
    root = deleteNode(root, 20);
    printf("In-order traversal after deletion: ");
    inOrder(root);
    printf("\n");

    printf("Deleting node 30...\n");
    root = deleteNode(root, 30);
    printf("In-order traversal after deletion: ");
    inOrder(root);
    printf("\n");

    printf("Deleting node 50...\n");
    root = deleteNode(root, 50);
    printf("In-order traversal after deletion: ");
    inOrder(root);
    printf("\n");

    return 0;
}
