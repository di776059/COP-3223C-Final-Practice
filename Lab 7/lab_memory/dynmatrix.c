#include <stdio.h>
#include <stdlib.h>

int **alloc_grid(int rows, int cols);
void fill_grid(int **g, int rows, int cols);
void print_grid(int **g, int rows, int cols);
void free_grid(int **g, int rows);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s rows cols\n", argv[0]);
    return 1;
    }
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int **grid = alloc_grid(rows, cols);
    
    if (!grid) return 1;
        fill_grid(grid, rows, cols);
        print_grid(grid, rows, cols);
    free_grid(grid, rows);
    return 0;
}

int **alloc_grid(int rows, int cols) {
    /* TODO */
    int **g;
    int i;

    g = malloc(rows *sizeof(int *));

    for (i=0; i < rows; i++) {
        g[i] = malloc(cols *sizeof(int));
      
    }
    return g;
}

void fill_grid(int **g, int rows, int cols) {
    /* TODO */
    int r;
    int c;

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            g[r][c] = r * cols + c;
        }
    }
}

void print_grid(int **g, int rows, int cols) {
    /* TODO */
    int r;
    int c;

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            printf("%3d ", g[r][c]);
        }
        printf("\n");
    }
}

void free_grid(int **g, int rows) {
    /* TODO */
    int r;

    for (r = 0; r < rows; r++) {
        free(g[r]);
    }
    free(g);
}
