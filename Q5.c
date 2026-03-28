#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n1, n2, i, j, k;

    printf("Enter number of elements in first log: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements:\n", n1);
    for(i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter number of elements in second log: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements:\n", n2);
    for(i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    i = 0; 
    j = 0; 
    k = 0; 

    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while(i < n1) {
        c[k++] = a[i++];
    }

    while(j < n2) {
        c[k++] = b[j++];
    }

    printf("Merged chronological log:\n");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}