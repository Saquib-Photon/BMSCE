#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node* insert_end(struct node *start, int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if (start == NULL) {
        t->prev = NULL;
        return t;
    }

    struct node *c = start;
    while (c->next) c = c->next;
    c->next = t;
    t->prev = c;
    return start;
}

struct node* insert_left(struct node *start, int x, int key)
{
    if (start == NULL) return start;

    struct node *t = malloc(sizeof(struct node));
    t->data = x;

    if (start->data == key) {
        t->prev = NULL;
        t->next = start;
        start->prev = t;
        return t;
    }

    struct node *c = start->next;
    while (c && c->data != key) c = c->next;

    if (!c) return start;

    t->next = c;
    t->prev = c->prev;
    c->prev->next = t;
    c->prev = t;

    return start;
}

struct node* delete_val(struct node *start, int key)
{
    if (!start) return start;

    struct node *c = start;

    while (c && c->data != key) c = c->next;
    if (!c) return start;

    if (c->prev) c->prev->next = c->next;
    else start = c->next;

    if (c->next) c->next->prev = c->prev;

    free(c);
    return start;
}

void display(struct node *start)
{
    while (start) {
        printf("%d <-> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *start = NULL;
    int ch, x, key, n;

    while (1) {
        printf("\n1.Create 2.Insert Left 3.Delete 4.Display 5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("No of nodes: ");
                scanf("%d", &n);
                while (n--) {
                    scanf("%d", &x);
                    start = insert_end(start, x);
                }
                break;

            case 2:
                scanf("%d %d", &x, &key);
                start = insert_left(start, x, key);
                break;

            case 3:
                scanf("%d", &key);
                start = delete_val(start, key);
                break;

            case 4:
                display(start);
                break;

            case 5:
                exit(0);
        }
    }
}