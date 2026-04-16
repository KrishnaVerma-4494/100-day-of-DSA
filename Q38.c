#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (front == 0 && rear == MAX - 1);
}

void push_front(int x) {
    if(isFull()) return;

    if(front == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        // shift right
        for(int i = rear; i >= front; i--) {
            deque[i + 1] = deque[i];
        }
        rear++;
    }
    else {
        front--;
    }

    deque[front] = x;
}

void push_back(int x) {
    if(isFull()) return;

    if(front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
}

void pop_front() {
    if(isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    front++;

    if(front > rear) {
        front = rear = -1;
    }
}

void pop_back() {
    if(isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    rear--;

    if(front > rear) {
        front = rear = -1;
    }
}

int getFront() {
    if(isEmpty()) return -1;
    return deque[front];
}

int getBack() {
    if(isEmpty()) return -1;
    return deque[rear];
}

int size() {
    if(isEmpty()) return 0;
    return rear - front + 1;
}

void display() {
    if(isEmpty()) return;

    for(int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        char op[20];
        scanf("%s", op);

        if(op[0] == 'p' && op[5] == 'f') { 
            int x;
            scanf("%d", &x);
            push_front(x);
        }
        else if(op[0] == 'p' && op[5] == 'b') { 
            int x;
            scanf("%d", &x);
            push_back(x);
        }
        else if(op[0] == 'p' && op[4] == 'f') {
            pop_front();
        }
        else if(op[0] == 'p' && op[4] == 'b') { 
            pop_back();
        }
        else if(op[0] == 'f') { 
            printf("%d\n", getFront());
        }
        else if(op[0] == 'b') { 
            printf("%d\n", getBack());
        }
        else if(op[0] == 's') {
            printf("%d\n", size());
        }
        else if(op[0] == 'e') {
            printf("%d\n", isEmpty());
        }
        else if(op[0] == 'd') { 
            display();
        }
    }

    return 0;
}