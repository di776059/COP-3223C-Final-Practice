#include <stdio.h> 

int main(int argc, char *argv[]) { 
    /* TODO: check argc */ 
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp; 
    char line[512]; 

    /* TODO: open argv[1] */ 
    fp = fopen(argv[1], "r");
    
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }
    /* TODO: read and print lines */ 
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    /* TODO: close file */ 
    fclose(fp);
    return 0; 
} 