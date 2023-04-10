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

int countnode(struct Node* root) {
    if ( root == NULL)
        return 0;

    return (1 + countnode(root->left)) + countnode(root->right);
}

int main() {
   int choice, data;
   do {
    printf("1. Insert\n");
    printf("2. Find no of nodes\n");
    printf("3. Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: printf("Insertion: please enter an element\n");
        scanf("%d", &data);
        insert(data, root);
        break;

        case 2: printf("No of nodes of BST: %d\n", countnode(root));
        break;

        case 3: break;
        default: printf("Invalid choice.");
        break; 
        }
    }while(choice != 3);
    return 0;
}
