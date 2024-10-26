#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Global variables for the queue
int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to enqueue (insert) an element
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }

    // If the queue is empty, initialize front and rear
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++; // Move rear to the next position
    }

    queue[rear] = data; // Add the new element to the rear
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (remove) an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return -1; // Indicate error
    }

    int data = queue[front]; // Store the data to be dequeued
    if (front == rear) {
        // Reset the queue if only one element was present
        front = rear = -1;
    } else {
        front++; // Move front to the next position
    }

    printf("%d dequeued from queue\n", data);
    return data; // Return the dequeued data
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue operation
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2: // Dequeue operation
                dequeue();
                break;
            case 3: // Display queue elements
                display();
                break;
            case 4: // Exit program
                printf("Exiting the program.\n");
                exit(0);
            default: // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
 