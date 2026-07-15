#include <stdio.h>
#include <stdlib.h>

// Node structure //
struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

// Enqueue (Insert) //
void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Overflow\n");
        return;
    }

    newnode->data = value;

    if (front == NULL) {   // first element
        front = rear = newnode;
        rear->next = front;   // circular link
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;   // maintain circular link
    }

    printf("Inserted: %d\n", value);
}

// Dequeue (Delete) //
void dequeue() {
    struct node* temp;

    if (front == NULL) {
        printf("Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted: %d\n", temp->data);

    if (front == rear) {   // only one node
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;   // maintain circular link
    }

    free(temp);
}

// Peek (View front element)    //
void peek() {
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

// Display //
void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct node* temp = front;

    printf("Queue elements:\n");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
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