#include <stdio.h> 
#include <ctype.h> 

int main(int argc, char *argv[]) { 
    /* TODO: validate argc (need 3) */ 

    if (argc != 3) {
        printf("Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    FILE *in, *out; 
    char line[512]; 
    int i;
    /* TODO: open in for reading, 
             out for writing */ 
    in = fopen(argv[1], "r");
    if (in == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    out = fopen(argv[2], "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        fclose(in);
        return 1;
    }
    
    while (fgets(line, sizeof(line), in) != NULL) { 
        /* TODO: convert to uppercase */ 
        /* TODO: write to out */ 
        for (i=0; line[i] != '\0'; i++) {
            line[i] = toupper((unsigned char)line[i]);
        }
        fputs(line, out);
    }
    /* TODO: close both files */ 
    fclose(in);
    fclose(out);

    printf("Done.\n"); 
    return 0; 
}