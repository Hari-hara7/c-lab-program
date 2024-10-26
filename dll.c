#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};
typedef struct Node* NODE;

NODE last = NULL;

NODE getNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = newNode->prev = NULL;
    }
    return newNode;
}

void insertFront(NODE AddNode) {
    if (last == NULL) {
        last = AddNode;
        last->next = last->prev = last;
    } else {
        AddNode->next = last->next;
        AddNode->prev = last;
        last->next->prev = AddNode;
        last->next = AddNode;
    }
}

void insertRight(int element, NODE newNode) {
    if (!last) return;
    NODE temp = last->next;
    do {
        if (temp->data == element) {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            if (temp == last)
                last = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
}

void deleteRight(int element) {
    if (!last) return;
    NODE temp = last->next;
    do {
        if (temp->data == element) {
            NODE delNode = temp->next;
            if (delNode == last->next) {
                if (delNode == last) {
                    last = NULL;
                } else {
                    last->next = delNode->next;
                    delNode->next->prev = last;
                }
            } else {
                temp->next = delNode->next;
                delNode->next->prev = temp;
                if (delNode == last)
                    last = temp;
            }
            free(delNode);
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
}

void insertEnd(NODE newNode) {
    insertFront(newNode);
    last = newNode;
}

void deleteEnd() {
    if (!last) return;
    NODE temp = last->prev;
    if (temp == last) {
        free(last);
        last = NULL;
    } else {
        temp->next = last->next;
        last->next->prev = temp;
        free(last);
        last = temp;
    }
}

void display() {
    if (!last) {
        printf("List is empty\n");
        return;
    }
    NODE temp = last->next;
    printf("CDLL: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to start)\n");
}

int countNodes() {
    if (!last) return 0;
    int count = 0;
    NODE temp = last->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);
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
