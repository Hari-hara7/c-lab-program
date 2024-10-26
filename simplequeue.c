#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Maximum size of the queue

// Queue structure
struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

// Initialize the queue
void initialize(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == SIZE - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Insert an element into the queue
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert %d.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;  // Initialize front on the first insert
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Delete an element from the queue
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete.\n");
    } else {
        printf("Deleted %d from the queue.\n", q->items[q->front]);
        q->front++;
        if (q->front > q->rear) {
            // Reset the queue when it's empty
            q->front = q->rear = -1;
        }
    }
}

// Display elements of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Main program
int main() {
    struct Queue q;
    initialize(&q);
    
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}