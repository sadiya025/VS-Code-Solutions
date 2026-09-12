#include <stdio.h>
int main () {
    int a[10][10], b[10][10];
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter matrix:\n");
    for (i=0; i<r; i++) {
        for (j=0; j<c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i=0; i<r; i++) {
        for (j=0; j<c; j++) {
            b[j][i] = a[i][j];
        }
    }
    printf("Transpose:\n");
    for (i=0; i<c; i++) {
        for (j=0; j<r; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}