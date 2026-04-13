
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if(top == -1) {
        return; 
    }
    top--;
}

void display() {
    if(top == -1) {
        return;
    }
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(val);
    }

    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}