#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the queue

// Declare the queue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initialize(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to enqueue (insert) an element
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0;  // Initialize front if queue is initially empty
        }
        q->rear++;
        q->items[q->rear] = value;  // Insert the data
        printf("Inserted %d into the queue.\n", value);
    }
}

// Function to dequeue (remove) an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;  // Indicate error
    }
    int data = q->items[q->front];  // Store the data to be removed

    if (q->front == q->rear) {
        // If there's only one element left, reset the queue
        q->front = q->rear = -1;
    } else {
        q->front++;  // Move front to the next position
    }

    printf("Dequeued %d from the queue.\n", data);
    return data;  // Return the dequeued data
}

// Function to display the elements in the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue q;
    initialize(&q);  // Initialize the queue

    int choice, value;

    while (1) {
        // Display the menu options
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Enqueue operation
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:  // Dequeue operation
                dequeue(&q);
                break;
            case 3:  // Display queue elements
                display(&q);
                break;
            case 4:  // Exit program
                printf("Exiting the program.\n");
                exit(0);
            default:  // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
