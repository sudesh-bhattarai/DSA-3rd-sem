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

/* RL Rotation = Right then Left */
struct Node* RLrotate(struct Node* root) {
    root->right = LLrotate(root->right);
    return RRrotate(root);
}

void printTreeBefore() {
    printf("Before RL Rotation:\n\n");
    printf("10\n");
    printf(" \\\n");
    printf(" 30\n");
    printf(" / \n");
    printf("20\n\n");
}

void printTreeAfter() {
    printf("After RL Rotation:\n\n");
    printf("   20\n");
    printf("  /  \\\n");
    printf("10   30\n\n");
}

int main() {
    struct Node* root = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(20);

    printTreeBefore();
    root = RLrotate(root);
    printTreeAfter();
}
