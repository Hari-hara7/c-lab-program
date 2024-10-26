#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node* NODE;

// Function to create a new node
NODE createNode(int item) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->link = newNode;  // Initially points to itself for circularity
    return newNode;
}

// Insert at front
NODE insertFront(NODE last, int item) {
    NODE temp = createNode(item);
    if (last == NULL) {
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    return last;
}

// Insert at end
NODE insertEnd(NODE last, int item) {
    NODE temp = createNode(item);
    if (last == NULL) {
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    return temp;
}

// Delete from front
NODE deleteFront(NODE last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    NODE temp = last->link;
    if (temp == last) { // Only one node
        printf("Deleted data is %d\n", temp->data);
        free(temp);
        return NULL;
    }
    last->link = temp->link;
    printf("Deleted data is %d\n", temp->data);
    free(temp);
    return last;
}

// Delete from end
NODE deleteEnd(NODE last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    NODE temp = last->link;
    if (temp == last) { // Only one node
        printf("Deleted data is %d\n", last->data);
        free(last);
        return NULL;
    }
    while (temp->link != last) {
        temp = temp->link;
    }
    temp->link = last->link;
    printf("Deleted data is %d\n", last->data);
    free(last);
    return temp;
}

// Display list
void display(NODE last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE temp = last->link;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != last->link);
    printf("\n");
}

// Main menu-driven program
int main() {
    int choice, item;
    NODE last = NULL;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert Front\n2. Insert End\n3. Delete Front\n4. Delete End\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert at front: ");
                scanf("%d", &item);
                last = insertFront(last, item);
                break;

            case 2:
                printf("Enter item to insert at end: ");
                scanf("%d", &item);
                last = insertEnd(last, item);
                break;

            case 3:
                last = deleteFront(last);
                break;

            case 4:
                last = deleteEnd(last);
                break;

            case 5:
                display(last);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
