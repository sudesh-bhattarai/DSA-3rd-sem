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
/* RR Rotation = Left Rotation */
struct Node* RRrotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
void printTreeBefore() {
    printf("Before RR Rotation:\n\n");
    printf("10\n");
    printf(" \\\n");
    printf(" 20\n");
    printf("  \\\n");
    printf("  30\n\n");
}

void printTreeAfter() {
    printf("After RR Rotation:\n\n");
    printf("   20\n");
    printf("  /  \\\n");
    printf("10   30\n\n");
}

int main() {
    struct Node* root = newNode(10);
    root->right = newNode(20);
    root->right->right = newNode(30);

    printTreeBefore();
    root = RRrotate(root);
    printTreeAfter();
}
