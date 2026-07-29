# include <stdio.h>

int main(void) {
    /* Will print 3*/
    printf("7 / 2 is, %d\n", 7 / 2);
    /*Will print 3.5*/
    printf("7.0 / 2 is, %.6f\n", 7.0 / 2);
    /*Will print 3.5*/
    printf("7 / 2.0 is, %.6f\n", 7 / 2.0);
    /*Will print 3.5*/
    printf("(double)7 / 2 is , %.6f\n", (double) 7 / 2);
    /*Will print 3.5*/
    printf("(double)(7 / 2) is, %.6f\n", (double)(7 / 2));
    /*Will print 1*/
    printf("7 %% 2 is, %d\n", 7 % 2);
    /*Will print -3*/
    printf("-7 / 2 is, %d\n", -7 / 2);
    /*Will print -1*/
    printf("-7 %% 2 is, %d\n", -7 % 2);
    return 0;
}

