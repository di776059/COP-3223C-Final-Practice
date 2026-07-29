# include <stdio.h>

void show_sizeof(int param[]);

int main(void) {
    int arr[5] = {1,2,3,4,5};
    int *ptr = arr;

    printf("=== sizeof experiments ===\n");
    printf("sizeof(arr) = %zu  (5 ints x 4 bytes)\n", sizeof(arr));
    printf("sizeof(arr[0]) = %zu\n", sizeof(arr[0]));

    size_t count = sizeof(arr) / sizeof(arr[0]);
    printf("element count = %zu\n", count);
    printf("sizeof(ptr) = %zu\n", sizeof(ptr));
    printf("sizeof(*ptr) = %zu\n", sizeof(*ptr));

    show_sizeof(arr);
    return 0;
}

void show_sizeof(int *param) {
    printf("Inside function, sizeof(param) = %zu\n", sizeof(param));
}