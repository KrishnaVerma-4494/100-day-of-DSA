#include <stdio.h>

int main() {
    int arr[100], n, k, i;
    int comparisons = 0;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++; 

        if(arr[i] == k) {
            printf("Element found at position %d\n", i + 1); 
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Element not found\n");
    }

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}