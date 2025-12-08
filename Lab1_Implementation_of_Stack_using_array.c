#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void init(struct stack *s) {
    s->top = -1;
}

// Check full
int isFull(struct stack *s) {
    return s->top == MAX - 1;
}

// Check empty
int isEmpty(struct stack *s) {
    return s->top == -1;
}

// Push element
void push(struct stack *s, int value) {
    if (isFull(s)) {
        printf("\nStack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
    printf("\n%d pushed into the stack.\n", value);
}

// Pop element
int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("\nStack Underflow! Nothing to pop.\n");
        return -1;
    }
    int value = s->arr[s->top--];
    printf("\n%d popped from the stack.\n", value);
    return value;
}

// Peek top element
int peek(struct stack *s) {
    if (isEmpty(s)) {
        printf("\nStack is empty! No top element.\n");
        return -1;
    }
    return s->arr[s->top];
}

// Display elements
void display(struct stack *s) {
    if (isEmpty(s)) {
        printf("\nStack is empty!\n");
        return;
    }
    
    printf("\nStack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct stack s;
    init(&s);
    
    int choice, value;
    
    while (1) {
        printf("\n=== STACK OPERATIONS USING ARRAYS ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Check Empty\n");
        printf("5. Check Full\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
                
            case 2:
                pop(&s);
                break;
                
            case 3:
                value = peek(&s);
                if (value != -1)
                    printf("\nTop element is: %d\n", value);
                break;
                
            case 4:
                if (isEmpty(&s))
                    printf("\nStack is EMPTY.\n");
                else
                    printf("\nStack is NOT EMPTY.\n");
                break;
                
            case 5:
                if (isFull(&s))
                    printf("\nStack is FULL.\n");
                else
                    printf("\nStack is NOT FULL.\n");
                break;
                
            case 6:
                display(&s);
                break;
                
            case 7:
                printf("\nExiting Program...\n");
                exit(0);
                
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    
    return 0;
}