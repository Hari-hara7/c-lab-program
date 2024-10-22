#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

typedef struct Node* NODE;

NODE last = NULL;

NODE getNode(int data) {
    struct Node* newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->link = NULL;
    }
    return newNode;
}

void insertFront(NODE AddNode) {
    if (last == NULL) {
        last = AddNode;
        last->link = last;
    } else {
        AddNode->link = last->link;
        last->link = AddNode;
    }
}

void insertRight(int element, NODE newNode) {
    if (!last) return;  // list is empty

    NODE temp = last->link;
    do {
        if (temp->data == element) {
            newNode->link = temp->link;
            temp->link = newNode;
            if (temp == last)  // if the new node is being inserted after the last node
                last = newNode;
            return;
        }
        temp = temp->link;
    } while (temp != last->link);
}

void deleteRight(int element) {
    if (!last) return;  // list is empty

    NODE temp = last->link;
    do {
        if (temp->data == element) {
            NODE delNode = temp->link;

            if (delNode == last->link) {  // for deleting the first node of the list
                if (delNode == last) {     // if the node is the only node in the list
                    last = NULL;
                } else {
                    last->link = delNode->link;
                }
            }

            temp->link = delNode->link;

            if (delNode == last) {  // for deleting the last node
                last = temp;
            }

            free(delNode);
            return;
        }
        temp = temp->link;
    } while (temp != last->link);
}

void insertEnd(NODE newNode) {
    insertFront(newNode);
    last = newNode;
}

void deleteEnd() {
    if (!last) return;

    NODE temp = last->link;

    if (temp == last) {  // only one node in the list
        free(last);
        last = NULL;
    } else {
        while (temp->link != last)
            temp = temp->link;
        temp->link = last->link;
        free(last);
        last = temp;
    }
}

void display() {
    if (!last) {
        printf("List is empty\n");
        return;
    }
    NODE temp = last->link;
    printf("CSLL: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != last->link);
    printf("%d (back to start)\n", temp->data);
}

int countNodes() {
    if (!last) return 0;
    int count = 0;
    NODE temp = last->link;
    do {
        count++;
        temp = temp->link;
    } while (temp != last->link);
    return count;
}

int main() {
    int choice, data, element;

    while (1) {
        printf("\n1.Insert Front\n2.Insert Right\n3.Delete Right\n4.Insert End\n5.Delete End\n6.Display\n7.Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 7) break;

        switch (choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                insertFront(getNode(data));
                break;

            case 2:
                printf("Element: ");
                scanf("%d", &element);
                printf("Data: ");
                scanf("%d", &data);
                insertRight(element, getNode(data));
                break;

            case 3:
                printf("Element: ");
                scanf("%d", &element);
                deleteRight(element);
                break;

            case 4:
                printf("Data: ");
                scanf("%d", &data);
                insertEnd(getNode(data));
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                display();
                printf("Nodes: %d\n", countNodes());
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
