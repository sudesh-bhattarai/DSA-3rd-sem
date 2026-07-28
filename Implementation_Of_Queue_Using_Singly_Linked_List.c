#include <stdio.h>
#include <stdlib.h>

// Define  structure //
struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

// Enqueue (Insert) //
void enqueue(int value) {
    struct node* newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Queue Overflow\n");
    } else {
        newnode->data = value;
        newnode->next = NULL;

        if (front == NULL) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
        printf("Inserted: %d\n", value);
    }
}

// Dequeue (Delete) //
void dequeue() {
    struct node* temp;

    if (front == NULL) {
        printf("Queue Underflow\n");
    } else {
        temp = front;
        printf("Deleted: %d\n", temp->data);
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        free(temp);
    }
}

// Peek (Front element) //
void peek() {
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

// Display //
void display() {
    struct node* temp;

    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        temp = front;
        printf("Queue elements are:\n");
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
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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