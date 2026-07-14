#include <stdio.h>
#include <stdlib.h>

// Define structure //
struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// Push (Insert) //
void push(int value) {
    struct node* newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Stack Overflow\n");
    } else {
        newnode->data = value;
        newnode->next = top;
        top = newnode;
        printf("Inserted: %d\n", value);
    }
}

// Pop (Delete) //
void pop() {
    struct node* temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
    } else {
        temp = top;
        printf("Deleted: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

// Peek (Top element) //
void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

// Display //
void display() {
    struct node* temp;

    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        temp = top;
        printf("Stack elements are:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}