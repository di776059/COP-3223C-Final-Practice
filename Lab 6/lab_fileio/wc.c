#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int lines = 0, words = 0; 
    int chars = 0, in_word = 0; 
    int c; 
    
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }
    while ((c = fgetc(fp)) != EOF) { 
        chars++; 
        if (c == '\n') lines++; 
        /* TODO: track words using 
       isspace() and in_word flag */ 
        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            words++;
            in_word = 1;
        }
    }

    fclose(fp);

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Chars: %d\n", chars);

    return 0;
}