#include <stdio.h>
#define MAX 5 

int stack[MAX];
int top = -1;
//Push into stack//
void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}
//Pop into stack//
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}
//Display//
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
//check full//
void isFull() {
    if (top == MAX - 1)
        printf("Stack is Full\n");
    else
        printf("Stack is Not Full\n");
}

//Check empty//
void isEmpty() {
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");
}


// Main function
int main() {
    int choice;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. isFull\n5. isEmpty\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: isFull(); break;
            case 5: isEmpty(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}