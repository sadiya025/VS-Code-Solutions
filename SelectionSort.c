# include <stdio.h>
int main () {
    int a[100], n, min, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i=0; i<n; i++) 
        scanf("%d", &a[i]);
    for (int i=0; i<n-1; i++) {
        min=1;
        for (int j=i+1; j<n; j++) {
            if (a[j] < a[min])
            min=j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("Sorted array: ");
    for (int i=0; i<n; i++) 
        printf("%d ", a[i]);
        return 0;
}