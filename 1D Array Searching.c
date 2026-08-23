#include <stdio.h>
int main() {
    int a[5], key;
    for (int i=0; i<5; i++) {
        printf("Enter element %d:", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (int i=0; i<5; i++) {
        if (a[i] == key) {
            printf("Element found at position %d", i+1);
            return 0;
        }
    }
    printf("Element not found");
    return 0;
}
