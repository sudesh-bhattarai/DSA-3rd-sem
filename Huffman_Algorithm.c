//Huffman algorithm 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct Node { 
    char c; 
    int f; 
    struct Node *left, *right; 
} Node; 

// Create a new node 
Node* newNode(char c, int f) { 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->c = c; 
    node->f = f; 
    node->left = node->right = NULL; 
    return node; 
} 

// Print Huffman codes by traversing the tree 
void printCodes(Node* root, int arr[], int top) { 
    if(root->left) { 
        arr[top] = 0; 
        printCodes(root->left, arr, top+1); 
    } 
    if(root->right){ 
        arr[top] = 1; 
        printCodes(root->right, arr, top+1); 
    } 
    if(!root->left && !root->right) { 
        printf("%c: ", root->c); 
        for(int i = 0; i < top; i++) 
            printf("%d", arr[i]); 
        printf("\n"); 
    } 
} 

// Build Huffman Tree 
Node* buildHuffman(Node* nodes[], int n) { 
    while(n > 1) { 
        // Find two nodes with smallest frequencies 
        int m1 = 0, m2 = 1; 
        if(nodes[m2]->f < nodes[m1]->f) { 
            int t = m1; 
            m1 = m2; 
            m2 = t; 
        } 
        for(int i = 2; i < n; i++) { 
            if(nodes[i]->f < nodes[m1]->f) { 
                m2 = m1; 
                m1 = i; 
            } 
            else if(nodes[i]->f < nodes[m2]->f) 
                m2 = i; 
        } 
        Node* combined = newNode('$', nodes[m1]->f + nodes[m2]->f); 
        combined->left = nodes[m1]; 
        combined->right = nodes[m2]; 
        if(m1 > m2) { 
            int t = m1; 
            m1 = m2; 
            m2 = t; 
        } 
        nodes[m1] = combined; 
        nodes[m2] = nodes[n-1]; 
        n--; 
    } 
    return nodes[0]; 
} 

int main() { 
    char str[100]; 
    printf("Enter string: "); 
    scanf("%s", str); 

    int freq[256] = {0}; 
    for(int i = 0; str[i]; i++) 
        freq[(unsigned char)str[i]]++; 

    Node* nodes[256]; 
    int n = 0; 
    for(int i = 0; i < 256; i++) 
        if(freq[i]) 
            nodes[n++] = newNode((char)i, freq[i]); 

    int arr[100]; 
    Node* root = buildHuffman(nodes, n); 

    printf("Huffman Codes:\n"); 
    printCodes(root, arr, 0); 

    return 0; 
}
