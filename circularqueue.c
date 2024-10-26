#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the queue

// Declare the circular queue and its front and rear pointers
char queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to enqueue (insert) an element into the queue
void enqueue(char data) {
    if (isFull()) {
        printf("Queue is Full. Cannot enqueue '%c'.\n", data);
        return;
    }
    
    if (isEmpty()) {
        front = rear = 0;  // Initialize front and rear if queue is empty
    } else {
        rear = (rear + 1) % MAX_SIZE;  // Move rear to the next position
    }
    
    queue[rear] = data;  // Insert the data
    printf("'%c' enqueued to queue.\n", data);
}

// Function to dequeue (remove) an element from the queue
char dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty. Cannot dequeue.\n");
        return '\0';  // Return null character to indicate error
    }

    char data = queue[front];  // Store the data to be removed

    if (front == rear) {
        // If there's only one element left, reset the queue
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;  // Move front to the next position
    }

    printf("'%c' dequeued from queue.\n", data);
    return data;  // Return the dequeued data
}

// Function to display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
        printf("'%c' ", queue[i]);
    }
    printf("'%c'\n", queue[rear]);  // Print the last element
}

// Main function
int main() {
    int choice;
    char data;

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
            case 1: // Enqueue operation
                printf("Enter data to enqueue: ");
                scanf(" %c", &data);  // Read character input
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
