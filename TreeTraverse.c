//Pre-Order, In-Order and Post-order 
#include <stdio.h> 
#include <stdlib.h> 

/* Structure of tree node */ 
struct node { 
    int data; 
    struct node *left, *right; 
}; 

/* Create Binary Tree using Preorder */ 
struct node* create() { 
    int x; 
    printf("Enter value (-1 for no node): "); 

    if (scanf("%d", &x) != 1) {   // ← ONLY NECESSARY FIX
        printf("Invalid input. Exiting.\n");
        exit(1);
    }

    if (x == -1) 
        return NULL; 

    struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = x; 

    printf("Enter left child of %d\n", x); 
    newNode->left = create(); 

    printf("Enter right child of %d\n", x); 
    newNode->right = create(); 

    return newNode; 
} 

/* Preorder Traversal */ 
void preorder(struct node* root) { 
    if (root != NULL) { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 

/* Inorder Traversal */ 
void inorder(struct node* root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 

/* Postorder Traversal */ 
void postorder(struct node* root) { 
    if (root != NULL) { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); 
    } 
} 

int main() { 
    struct node* root; 
    printf("Create Binary Tree using Preorder\n"); 
    root = create(); 

    printf("\nPreorder Traversal: "); 
    preorder(root); 

    printf("\nInorder Traversal: "); 
    inorder(root); 

    printf("\nPostorder Traversal: "); 
    postorder(root); 

    return 0; 
}
