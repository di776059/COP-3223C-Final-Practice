#include <stdio.h> 

int main(int argc, char *argv[]) { 
    if (argc != 2) { 
        fprintf(stderr, "Usage: %s grades.csv\n", argv[0]); 
        return 1; 
    }
    FILE *fp = fopen(argv[1], "r"); 
    if (!fp) { 
        perror(argv[1]); 
        return 1; 
    }
    char line[128]; 
    char name[64]; 
    int  score; 
    int  total = 0, count = 0; 

    while (fgets(line, sizeof(line), fp) != NULL) {

        int parsed = sscanf(line, " %63[^,],%d", name, &score);


        if (parsed == 2) {
            printf("%-10s %3d\n", name, score);

            total += score;
            count++;
            }
    }
    fclose(fp); 

    if (count > 0) 
        printf("Average: %.1f\n", 
               (double)total / count); 
    return 0; 
} 
