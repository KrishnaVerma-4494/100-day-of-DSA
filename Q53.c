#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct QNode {
    struct Node* node;
    int hd;
    struct QNode* next;
};

struct QNode *front = NULL, *rear = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void enqueue(struct Node* node, int hd) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;

    if(rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

struct QNode* dequeue() {
    if(front == NULL) return NULL;

    struct QNode* temp = front;
    front = front->next;
    if(front == NULL) rear = NULL;

    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[100];
    int f = 0, r = 0;

    queue[r++] = root;

    int i = 1;

    while(i < n) {
        struct Node* curr = queue[f++];

        if(i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[r++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[r++] = curr->right;
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    int min = 0, max = 0;

    int result[200][200], count[200] = {0};

    enqueue(root, 100); 

    while(front != NULL) {
        struct QNode* temp = dequeue();
        struct Node* curr = temp->node;
        int hd = temp->hd;

        result[hd][count[hd]++] = curr->data;

        if(hd < min) min = hd;
        if(hd > max) max = hd;

        if(curr->left)
            enqueue(curr->left, hd - 1);
        if(curr->right)
            enqueue(curr->right, hd + 1);

        free(temp);
    }

    for(int i = min; i <= max; i++) {
        for(int j = 0; j < count[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}