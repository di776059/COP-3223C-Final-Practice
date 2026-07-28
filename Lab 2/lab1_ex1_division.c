# include <stdio.h>

int main(void) {
    printf("7 / 2 is, %d\n", 7 / 2);
    printf("7.0 / 2 is, %.6f\n", 7.0 / 2);
    printf("7 / 2.0 is, %.6f\n", 7 / 2.0);
    printf("(double)7 / 2 is , %.6f\n", (double) 7 / 2);
    printf("(double)(7 / 2) is, %.6f\n", (double)(7 / 2));
    printf("7 %% 2 is, %d\n", 7 % 2);
    printf("-7 / 2 is, %d\n", -7 / 2);
    printf("-7 %% 2 is, %d\n", -7 % 2);
    return 0;
}

