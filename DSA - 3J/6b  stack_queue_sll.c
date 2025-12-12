#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start_stack = NULL;
struct node *start_queue = NULL;
struct node *rear_queue = NULL;

void push_stack(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->info = value;
    newnode->next = start_stack;
    start_stack = newnode;
    printf("Pushed %d onto stack\n", value);
}

void pop_stack() {
    if (start_stack == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = start_stack;
    int v = temp->info;
    start_stack = start_stack->next;
    free(temp);
    printf("Popped %d from stack\n", v);
}

void display_stack() {
    if (start_stack == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = start_stack;
    printf("Stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->info = value;
    newnode->next = NULL;
    if (start_queue == NULL) {
        start_queue = newnode;
        rear_queue = newnode;
    } else {
        rear_queue->next = newnode;
        rear_queue = newnode;
    }
    printf("Enqueued %d into queue\n", value);
}

void dequeue() {
    if (start_queue == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp = start_queue;
    int v = temp->info;
    start_queue = start_queue->next;
    if (start_queue == NULL)
        rear_queue = NULL;
    free(temp);
    printf("Dequeued %d from queue\n", v);
}

void display_queue() {
    if (start_queue == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = start_queue;
    printf("Queue (front to rear): ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, subchoice, value;

    while (1) {
        printf("\n--- STACK & QUEUE USING SINGLY LINKED LIST ---\n");
        printf("1. Stack operations\n");
        printf("2. Queue operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) return 0;

        if (choice == 1) {
            printf("\n--- STACK MENU ---\n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Display Stack\n");
            printf("4. Back to Main Menu\n");
            printf("Enter your choice: ");
            if (scanf("%d", &subchoice) != 1) return 0;
            switch (subchoice) {
                case 1:
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push_stack(value);
                    break;
                case 2:
                    pop_stack();
                    break;
                case 3:
                    display_stack();
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid choice\n");
            }
        } else if (choice == 2) {
            printf("\n--- QUEUE MENU ---\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Display Queue\n");
            printf("4. Back to Main Menu\n");
            printf("Enter your choice: ");
            if (scanf("%d", &subchoice) != 1) return 0;
            switch (subchoice) {
                case 1:
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    display_queue();
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid choice\n");
            }
        } else if (choice == 3) {
            return 0;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}