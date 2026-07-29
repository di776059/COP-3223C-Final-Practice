# include <stdio.h>

void swap(int *a, int *b);
void stats(int arr[], int len, int *out_min, int *out_max, double *out_avg);

int main(void) {
    int x = 10;
    int y = 5;
    int data[] = {34, 12, 78, 56, 23};
    int min;
    int max;
    double avg;
    swap(&x, &y);
    stats(data, 5, &min, &max, &avg);

    printf("x= %d, y = %d\n", x, y);
    
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Average: %.2f\n", avg);
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void stats(int arr[], int len, int *out_min, int *out_max, double *out_avg) {
    *out_min = arr[0];
    *out_max = arr[0];
    int total = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (arr[i] < *out_min) {
            *out_min = arr[i];
        }
        if (arr[i] > *out_max) {
            *out_max = arr[i];
        }
        total += arr[i];
    }
    *out_avg = (double) total / len;
}