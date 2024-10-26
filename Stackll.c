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

// Function to push an element onto the stack
NODE push(NODE top, int item) {
    NODE temp = getnode();
    temp->data = item;
    temp->link = top;
    top = temp;
    return top;
}

// Function to pop an element from the stack
NODE pop(NODE top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return top;
    }
    NODE temp = top;
    top = top->link;
    printf("Popped element: %d\n", temp->data);
    free(temp);
    return top;
}

// Function to display the stack
void display(NODE top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    NODE temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Main function for the menu-driven program
int main() {
    int choice, item;
    NODE top = NULL;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push onto the stack: ");
                scanf("%d", &item);
                top = push(top, item);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                display(top);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
