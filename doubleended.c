#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 // Maximum size of the deque

int deque[SIZE];
int front = -1, rear = -1;

// Insert at the front of the deque
void insertFront(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        deque[front] = value;
        printf("%d inserted at front\n", value);
    }
}

// Insert at the rear of the deque
void insertRear(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
    } else {
        if (rear == -1) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("%d inserted at rear\n", value);
    }
}

// Delete from the front of the deque
void deleteFront() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else {
        printf("Deleted from front: %d\n", deque[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

// Delete from the rear of the deque
void deleteRear() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else {
        printf("Deleted from rear: %d\n", deque[rear]);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
        }
    }
}

// Display all elements of the deque
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
