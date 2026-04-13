#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if(*top == NULL) {
        return 0;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;
    int i = 0;

    while(expr[i] != '\0') {

        // Skip spaces
        if(expr[i] == ' ') {
            i++;
            continue;
        }

        // If number
        if(isdigit(expr[i])) {
            int num = 0;
            while(isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            push(&stack, num);
        }
        else {
            // Operator
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;

            switch(expr[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            push(&stack, result);
            i++;
        }
    }

    return pop(&stack);
}

int main() {
    char expr[1000];

    // Read full line input
    fgets(expr, sizeof(expr), stdin);

    int result = evaluatePostfix(expr);

    printf("%d", result);

    return 0;
}