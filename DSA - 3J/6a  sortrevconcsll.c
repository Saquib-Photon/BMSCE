#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList() {
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return;
    }

    printf("Enter value for node 1: ");
    scanf("%d", &value);

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = NULL;

    struct Node* temp = head;

    for (i = 2; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    printf("List created successfully!\n");
}

void sortList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List sorted successfully!\n");
}

void reverseList() {
    struct Node *prev = NULL, *curr = head, *nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    head = prev;
    printf("List reversed successfully!\n");
}

void concatenateLists() {
    struct Node *head2 = NULL, *temp, *newNode;
    int n, value, i;

    printf("Enter number of nodes for 2nd list: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return;
    }

    printf("Enter value for node 1: ");
    scanf("%d", &value);

    head2 = (struct Node*)malloc(sizeof(struct Node));
    head2->data = value;
    head2->next = NULL;
    temp = head2;

    for (i = 2; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    if (head == NULL) {
        head = head2;
        printf("Concatenation complete (first list was empty)\n");
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    printf("Lists concatenated successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Create Linked List\n");
        printf("2. Sort Linked List\n");
        printf("3. Reverse Linked List\n");
        printf("4. Concatenate Two Linked Lists\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;

            case 2:
                sortList();
                break;

            case 3:
                reverseList();
                break;

            case 4:
                concatenateLists();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;

}
