#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int key;
    struct Node *left, *right;
};

/* Create new node */
struct Node* newNode(int key) {
    struct Node* n = malloc(sizeof(struct Node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}
/* LL Rotation = Right Rotation */
struct Node* LLrotate(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}
/* Print tree in textbook style */
void printTreeBefore() {
    printf("Before LL Rotation:\n\n");
    printf("    30\n");
    printf("   /\n");
    printf("  20\n");
    printf(" /\n");
    printf("10\n\n");
}
void printTreeAfter() {
    printf("After LL Rotation:\n\n");
    printf("   20\n");
    printf("  /  \\\n");
    printf("10   30\n\n");
}
int main() {
    struct Node* root = newNode(30);
    root->left = newNode(20);
    root->left->left = newNode(10);
    printTreeBefore();
    root = LLrotate(root);
    printTreeAfter();
return 0;
}
