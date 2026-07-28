# include <stdio.h>

int main(void) {
    int age;
    char initial;
    double number;
    do {
        printf("Enter your age (1-120):\n");
        fscanf(stdin, "%d", &age);
        if (age < 1 || age > 120) {
            printf("Invalid input. Try again.\n");
        }
    } while ( age < 1 || age > 120);
    
    do {
        printf("Enter your initial (A-Z)\n");
        fscanf(stdin, " %c", &initial);
        if (!((initial >= 'A' && initial <= 'Z') || 
        (initial >= 'a' && initial <= 'z'))) {
            printf("Invalid input. Try again.\n");
        }
    } while (!((initial >= 'A' && initial <= 'Z') || 
        (initial >= 'a' && initial <= 'z')));
    
    do {
        printf("Enter a positive decimal:\n");
        fscanf(stdin, "%lf", &number);
        if (number <= 0 ) {
            printf("Invalid input. Try again.\n");
        }
    } while (number <= 0);

    printf("Hello, %c. You are %d years old. Your number: %lf", initial, age, number);
    
    return 0;
}
