#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *link;
};

typedef struct node* NODE;

// Function to allocate memory for a new node
NODE getnode() {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return newNode;
}

// Function to enqueue (insert) an element at the rear of the queue
NODE enqueue(NODE rear, int item) {
    NODE temp = getnode();
    temp->data = item;
    temp->link = NULL;
    if (rear != NULL) {
        rear->link = temp;
    }
    return temp;
}

// Function to dequeue (remove) an element from the front of the queue
NODE dequeue(NODE *front) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return NULL;
    }
    NODE temp = *front;
    printf("Dequeued element: %d\n", temp->data);
    *front = (*front)->link;
    free(temp);
    return *front;
}

// Function to display the queue
void display(NODE front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    NODE temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Main function for the menu-driven program
int main() {
    int choice, item;
    NODE front = NULL, rear = NULL;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                if (front == NULL) {
                    // If the queue is empty, set both front and rear to the new node
                    front = rear = enqueue(rear, item);
                } else {
                    // Enqueue at the rear
                    rear = enqueue(rear, item);
                }
                break;

            case 2:
                front = dequeue(&front);
                if (front == NULL) {
                    rear = NULL;  // If the queue becomes empty, reset rear
                }
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
