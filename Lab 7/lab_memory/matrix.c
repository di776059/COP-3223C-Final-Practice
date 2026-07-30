#include <stdio.h>

void print_matrix(int m[][3], int rows, const char *label){
        /* TODO: print label,
        then each row */
        int i, j;

        printf("%s:\n", label);

        for (i=0; i < rows; i++) {
            for (j=0; j < 3; j++) {
                printf("%3d ", m[i][j]);
            }
            printf("\n");
        }
}

int main(void) {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int b[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int c[3][3];

    int i, j;
    /* TODO: compute c = a + b */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    print_matrix(a, 3, "A");
    print_matrix(b, 3, "B");
    print_matrix(c, 3, "A + B");
    return 0;
}