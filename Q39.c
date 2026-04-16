#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int i) {
    while(2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;

        if(right < size && heap[right] < heap[left]) {
            smallest = right;
        }

        if(heap[i] > heap[smallest]) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

void insert(int x) {
    if(size == MAX) return;

    heap[size] = x;
    heapifyUp(size);
    size++;
}

int peek() {
    if(size == 0) return -1;
    return heap[0];
}

int extractMin() {
    if(size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

int main() {
    int N;
    scanf("%d", &N);

    while(N--) {
        char op[20];
        scanf("%s", op);

        if(op[0] == 'i') { 
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'p') {
            printf("%d\n", peek());
        }
        else if(op[0] == 'e') { 
            printf("%d\n", extractMin());
        }
    }

    return 0;
}