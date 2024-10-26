#include <stdio.h>
#include <stdlib.h>

// Define the doubly linked list node structure
struct node {
    int info;
    struct node *prev;
    struct node *next;
};
typedef struct node* NODE;

// Function to allocate memory for a new node
NODE getnode() {
    NODE X;
    X = (NODE)malloc(sizeof(struct node));
    if (X == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    X->prev = X->next = NULL;
    return X;
}

// Function to free memory of a node
void freenode(NODE X) {
    free(X);
}

// Function to insert a node at the front of the doubly linked list (Stack push operation)
NODE insert_front(NODE first, int item) {
    NODE temp = getnode();
    temp->info = item;
    temp->next = first;
    if (first != NULL) {
        first->prev = temp;
    }
    return temp;
}

// Function to insert a node at the rear of the doubly linked list (Queue enqueue operation)
NODE insert_rear(int item, NODE first) {
    NODE temp = getnode();
    temp->info = item;

    if (first == NULL) {
        return temp;
    }

    NODE cur = first;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
    return first;
}

// Function to delete a node from the front of the doubly linked list (Stack pop/Queue dequeue operation)
NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return first;
    }

    NODE temp = first;
    first = first->next;
    if (first != NULL) {
        first->prev = NULL;
    }
    printf("Deleted data is %d\n", temp->info);
    freenode(temp);
    return first;
}

// Function to display the doubly linked list and count the number of nodes
void display(NODE first) {
    NODE temp = first;
    int count = 0;

    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Contents of the Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
        count++;
    }
    printf("\nNumber of nodes in the list: %d\n", count);
}

// Main function for the menu-driven program
int main() {
    int choice, item;
    NODE first = NULL;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Front (Stack Demonstration)\n");
        printf("2. Insert at Rear (Queue Demonstration)\n");
        printf("3. Delete from Front (Stack/Queue Demonstration)\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Stack Push - Insert at front
                printf("Enter the item to insert at front (Stack): ");
                scanf("%d", &item);
                first = insert_front(first, item);
                break;

            case 2: // Queue Enqueue - Insert at rear
                printf("Enter the item to insert at rear (Queue): ");
                scanf("%d", &item);
                first = insert_rear(item, first);
                break;

            case 3: // Stack Pop/Queue Dequeue - Delete from front
                first = delete_front(first);
                break;

            case 4: // Display list and count nodes
                display(first);
                break;

            case 5: // Exit
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
