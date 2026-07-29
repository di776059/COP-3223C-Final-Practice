#include <stdio.h>
#include <string.h>

typedef struct {
    char title[64];
    char author[48];
    int year;
    double rating;   /* 0.0 to 5.0 */
} Book;

void print_library(const Book books[], int count);
Book *find_by_author(Book books[], int count, const char *author);
void sort_by_year(Book books[], int count);

int main(void) {
    Book library[5] = {
        {.title = "The C Programming Language",
         .author = "Kernighan & Ritchie",
         .year = 1988,
         .rating = 4.90},

        {.title = "C Programming: A Modern Approach",
         .author = "K.N. King",
         .year = 2008,
         .rating = 4.80},

        {.title = "Modern C",
         .author = "Jens Gustedt",
         .year = 2019,
         .rating = 4.50},

        {.title = "Expert C Programming",
         .author = "Peter van der Linden",
         .year = 1994,
         .rating = 4.60},

        {.title = "Head First C",
         .author = "David Griffiths",
         .year = 2012,
         .rating = 4.30}
    };

    Book *found;

    printf("Unsorted library:\n");
    print_library(library, 5);

    found = find_by_author(library, 5, "K.N. King");

    if (found != NULL) {
        printf("\nFound book:\n");
        printf("\"%s\" by %s (%d) ★ %.2f\n",
               found->title,
               found->author,
               found->year,
               found->rating);
    } else {
        printf("\nAuthor not found\n");
    }

    sort_by_year(library, 5);

    printf("\nSorted library:\n");
    print_library(library, 5);

    return 0;
}

void print_library(const Book books[], int count) {
    int i;
    for (i=0; i < count; i++) {
        printf("%d. \"%s\" by %s (%d) ★ %.2f\n" , i+1, books[i].title, books[i].author, books[i].year, books[i].rating);
    }
}

Book *find_by_author(Book books[], int count, const char *author) {
    int i;
    for (i=0; i < count; i++) {
        if (strcmp(books[i].author, author) == 0) {
            return &books[i];
        }
    }
    return NULL;
}

void sort_by_year(Book books[], int count) {
    int i;
    int j;
    Book temp;

    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1 -i; j++) {
            if (books[j].year > books[j + 1].year) {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}