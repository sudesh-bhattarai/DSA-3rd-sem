#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Enqueue (Insert) //
void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) {   // first element
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;        // circular condition
        } else {
            rear++;
        }
        queue[rear] = value;
        printf("Inserted: %d\n", value);
    }
}

// Dequeue (Delete) //
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Deleted: %d\n", queue[front]);

        if (front == rear) {
            front = rear = -1;   // queue becomes empty
        } else if (front == MAX - 1) {
            front = 0;           // circular condition
        } else {
            front++;
        }
    }
}

// Peek (Front element) //
void peek() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Display //
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        int i = front;
        printf("Queue elements are:\n");

        if (front <= rear) {
            for (i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (i = front; i < MAX; i++) {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
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