// This program inserts keys into the tree, searches for the keys, and prints traversal orders.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

struct Node* insert(int data, struct Node* node) {
    struct Node* temp;
    if (node == NULL) {
        temp = malloc(sizeof(struct Node));
        temp->data = data;
        temp->left = temp->right = NULL;
        if( root == NULL)
            root = temp;
        return temp;
    }
    else if (data < node->data) {
        node->left = insert(data, node->left);
        return node;
    }
    else if (data > node->data) {
        node->right = insert(data, node->right);
        return node;
    }
    else {
        printf("Duplicate element found while inserting, falied. ");
        return NULL;
    }
}

struct Node* search(struct Node* root, int key) {
    if ( root == NULL) {
        return NULL;
    }
    if (key == root->data) {
        return root;
    }
    else if (key < root->data) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
   int choice, data;
   do {
    printf("1. Insert\n");
    printf("2. Search for a key\n");
    printf("3. Display the traversals\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: printf("Insertion: please enter an element\n");
        scanf("%d", &data);
        insert(data, root);
        break;

        case 2:
        printf("Enter the key to be searched.\n");
        scanf("%d", &data);
        struct Node* n = search(root, data);
        if (n != NULL) {
            printf("Found: %d\n", n->data);
        }
        else {
            printf("Couldnt find\n");
        }
        break;

        case 3: printf("PreOrder: ");
        preOrder(root);
        printf("\n");
        printf("InOrder: ");
        inOrder(root);
        printf("\n");
        printf("PostOrder: ");
        postOrder(root);
        printf("\n"); 
        break;

        case 4: break;
        default: printf("Invalid choice.");
        break; 
        }
    }while(choice != 4);
    return 0;
}
