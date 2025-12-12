#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        top++;
        stack[top] = c;
    }
}

char pop() {
    if (top > -1) {
        return stack[top--];
    }
    return '\0'; 
}

char check() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';  
}

int order(char op) {
    switch (op) {
        
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOp(char c) {
    return (c == '+' || c == '/' || c == '*' || c == '-' );
}

void stuff(char in[], char post[]) {
    int i, k = 0;
    char ch;
    for (i = 0; in[i] != '\0'; i++) {
        ch = in[i];
        if (isalnum(ch)) {  
            post[k++] = ch;
        } else if (ch == '(') {  
            push(ch);
        } else if (ch == ')') {  
            while (top != -1 && check() != '(') {
                post[k++] = pop();
            }
            pop();  
        } else if (isOp(ch)) {  
            while (top != -1 && order(check()) >= order(ch)) {
                post[k++] = pop();
            }
            push(ch);  
        }
    }
    
    while (top != -1) {
        post[k++] = pop();
    }
    post[k] = '\0';
}

int main() {
    char in[MAX], post[MAX];
    printf("Enter infix: \n");
    fgets(in, MAX, stdin);  
    stuff(in, post);
    printf("Postfix expression: %s\n", post);
    return 0;
}
