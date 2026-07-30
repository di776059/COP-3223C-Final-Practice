#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_str(const void *a,const void *b) {
    return strcmp(*(const char **)a,*(const char **)b);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return 1;
    }  

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        perror(argv[1]);
        return 1;
    }

    int cap = 4, count = 0;

    char **words = malloc(cap * sizeof(char *));

    if (!words) return 1;

    char buf[256];

    while (fgets(buf, sizeof(buf), fp)) {
        buf[strcspn(buf,"\n")] = 0;
        if (count == cap) {
            cap *= 2;
            char **t = realloc(words, cap * sizeof(char*));
            if (!t) {
                /* free what we have */
                int i;
                for (i=0;i<count;i++)
                free(words[i]);
                free(words);
                fclose(fp);
                return 1;
            }
            words = t;
        }

        words[count] = strdup(buf);

        if (!words[count]) break;
        count++;
    }

    fclose(fp);

    qsort(words, count, sizeof(char *), cmp_str);

    int i;

    for (i = 0; i < count; i++) {
        puts(words[i]);
        free(words[i]);
    }


    free(words);
    return 0;
}