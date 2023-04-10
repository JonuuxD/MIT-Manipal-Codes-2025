#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node *p = malloc(sizeof (struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return (p);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int diameter(struct Node* tree) {
    if ( tree == NULL)
        return 0;

    int lheight = height(tree->left);
    int rheight = height(tree->right);

    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->right = createNode(5);

    printf("The inOrder traversal of the entered tree is: ");
    inOrder(root);
    printf("\n");
    printf("The diameter of the entered tree is: %d\n", diameter(root));
    return 0;
}
