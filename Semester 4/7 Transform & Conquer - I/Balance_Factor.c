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

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    } 
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } 
        else {
            return (rightHeight + 1);
        }
    }
}

int balanceFactor(struct Node* root) {
    if (root == NULL)
        return 0;
    else
        return (height(root->left) - height(root->right));
}

void printBalanceFactors(struct Node* root) {
    if (root != NULL) {
        printBalanceFactors(root->left);
        printf("Balance factor of node %d: %d\n", root->data, balanceFactor(root));
        printBalanceFactors(root->right);
    }
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

        case 2:
        printf("The inorder traversal of the tree is: \n");
        inOrder(root);
        printf("The balance factor are: \n");
        printBalanceFactors(root);
        break;

        case 3: break;
        default: printf("Invalid choice.");
        break; 
        }
    }while(choice != 3);
    return 0;
}
