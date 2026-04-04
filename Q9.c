#include <stdio.h>
#include <string.h>

void reverse(char str[], int index) {
    if (str[index] == '\0')
        return;

    reverse(str, index + 1);
    printf("%c", str[index]);
}

int main() {
    char str[100];

    printf("Enter code name: ");
    scanf("%s", str);

    printf("Mirror code: ");
    reverse(str, 0);

    return 0;
}