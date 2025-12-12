#include <stdio.h>
#define max 5
#include <stdlib.h>
int queue[max];
int top = -1;
int rear = -1;
int num;
void ins(int num)
{
    if (rear == max - 1)
    {
        printf("Can't insert - Queue Overflow\n");
    }
    else if (top == -1)
    {
        top++;
        queue[++rear] = num;
        printf("Inserted %d t0 queue\n", num);
    }
    else{
        queue[++rear]=num;
    }
}
void del()
{
    if (top == -1)
    {
        printf("Empty Queue\n");
    }
    else if (top == rear)
    {
        num = queue[rear];
        rear = -1;
        top = -1;
        printf("%d was deleted\n", num);
    }
    else
    {
        num = queue[top++];
        printf("%d was deleted\n", num);
    }
}
void dis()
{
    if (top == -1)
    {
        printf("Empty queue\n");
        printf("[]");
    }
    else
    {
        printf("[");
        for (int i = top; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("]\n");
    }
}
void main()
{
    int insnum;
    int n;
    while (1)
    {
        printf("Select your operation : \n");
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display \n");
        printf("4. Exit \n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the number to insert : ");
            scanf("%d", &insnum);
            ins(insnum);
            break;
        case 2:
            del();
            break;
        case 3:
            dis();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid\n");
            break;
        }
    }

}