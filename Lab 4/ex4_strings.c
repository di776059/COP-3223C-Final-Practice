# include <stdio.h>
# include <string.h>

int main(void) {
    char first[32];
    char last [32];
    char full [72];
    
    printf("First name: ");
    fscanf(stdin, "%31s", first);
    printf("Last name: ");
    fscanf(stdin, "%31s", last);

    strncpy(full, last, sizeof(full));
    strncat(full, ", ", 1);
    strncat(full, first, sizeof(full) - 1);
    printf("Full name: %s\n", full);
    printf("Length: %zu\n", strlen(full));
    
    if (strcmp(last, "Smith") < 0) {
        printf("%s comes before Smith alphabetically.\n", last);
    } else {
        printf("%s does not come before Smith alphabetically.\n", last);
    }
    
    if (first[0] >= 'a' && first[0] <= 'z') {
        first[0] -= 32;
    }
    printf("Capitalized first: %s\n", first);
}