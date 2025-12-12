#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if ((front == (rear + 1) % MAX)) {
        printf("Queue Overflow\n");
    }
    else if (front == -1) {  
        front = rear = 0;
        queue[rear] = item;
        printf("%d inserted\n", item);
    }
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = item;
        printf("%d inserted\n", item);
    }
}

int dequeue() {
    if (front == -1) {
        printf("Empty Queue\n");
        return -1;
    }

    int item = queue[front];

    if (front == rear) { 
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }

    printf("%d dequeued\n", item);
    return item;
}

void display() {
    if (front == -1) {
        printf("Empty Queue\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
