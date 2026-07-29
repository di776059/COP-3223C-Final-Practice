# include <stdio.h>

int clamp(int val, int lo, int hi);
int absolute_value(int x);
double celsius_to_fahrenheit(double c);
int is_even(int n);

int main(void) {
    int val, lo, hi;
    int x;
    double c;
    int n;

    /*Clamp Function*/
    printf("Enter value: ");
    fscanf(stdin, "%d", &val);

    printf("Enter lower bound:");
    fscanf(stdin, "%d", &lo);

    printf("Enter high:");
    fscanf(stdin, "%d", &hi);

    printf("Clamped value: %d\n", clamp(val, lo, hi));

    /*Absolute Value*/
    printf("Enter your number:");
    fscanf(stdin, "%d", &x);

    printf("The absolute value of your number is %d\n", absolute_value(x));

    /*Celsius to Fahrenheit*/
    printf("Enter your temperature in celsius:");
    fscanf(stdin, "%lf", &c);

    printf("Your temperature in fahrenheit is: %.2f\n", celsius_to_fahrenheit(c));

    /*Even Check*/
    printf("Enter your number: ");
    fscanf(stdin, "%d", &n);

    printf("If value is 1, your number is even. If 0 it is not. Your value is: %d\n", is_even(n));
}

int clamp(int val, int lo, int hi) {
    if (val > hi) {
        return hi;
    } else if (val < lo) {
        return lo;
    } else {
        return val;
    }
}

int absolute_value(int x) {
    if (x < 0) {
        x = -1 * x;
        return x;
    } else { 
        return x;
    }
}

double celsius_to_fahrenheit(double c) {
    return c * (9.0 / 5.0) + 32;
}

int is_even(int n) {
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}
