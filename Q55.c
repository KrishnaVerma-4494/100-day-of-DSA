#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[1000];
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

void rightView(struct Node* root) {
    if(root == NULL) return;

    struct Node* queue[1000];
    int f = 0, r = 0;

    queue[r++] = root;

    while(f < r) {
        int size = r - f;

        for(int i = 0; i < size; i++) {
            struct Node* curr = queue[f++];

            if(i == size - 1) {
                printf("%d ", curr->data);
            }

            if(curr->left) queue[r++] = curr->left;
            if(curr->right) queue[r++] = curr->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}