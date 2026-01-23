#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node *left, *right;
};
struct Node* newNode(int key) {
    struct Node* n = malloc(sizeof(struct Node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}
/* LL Rotation */
struct Node* LLrotate(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}
/* RR Rotation */
struct Node* RRrotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
/* LR Rotation = Left then Right */
struct Node* LRrotate(struct Node* root) {
    root->left = RRrotate(root->left);
    return LLrotate(root);
}
void printTreeBefore() {
    printf("Before LR Rotation:\n\n");
    printf("    30\n");
    printf("   /\n");
    printf("  10\n");
    printf("   \\\n");
    printf("   20\n\n");
}
void printTreeAfter() {
    printf("After LR Rotation:\n\n");
    printf("   20\n");
    printf("  /  \\\n");
    printf("10   30\n\n");
}
int main() {
    struct Node* root = newNode(30);
    root->left = newNode(10);
    root->left->right = newNode(20);

    printTreeBefore();
    root = LRrotate(root);
    printTreeAfter();
}
