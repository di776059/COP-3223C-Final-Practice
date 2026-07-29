#include <stdio.h>
#include <string.h>

typedef struct {
    char title[64];
    char author[48];
    int year;
    double rating;   /* 0.0 to 5.0 */
} Book;

void print_book(const Book *b);
void update_rating(Book *b, double new_rating);
Book create_book(const char *title, const char *author, int year, double rating);

int main(void) {
    Book book1 = create_book("The C Programming Language", "Kernighan & Ritchie", 1988, 4.90);
    Book book2 = create_book("C Programming: A Modern Approach","K.N. King", 2008, 4.80);
    Book book3 = create_book("Modern C", "Jens Gustedt", 2019, 4.50);
    
    print_book(&book1);
    print_book(&book2);
    print_book(&book3);
    
    update_rating(&book2, 4.95);
    printf("After updating\n");
    print_book(&book2);
    return 0;
}

void print_book(const Book *b) {
    printf("%s by %s (%d) ★ %.2f\n", b->title, b->author, b->year, b->rating);
}

void update_rating(Book *b, double new_rating) {
    if (new_rating < 0.0) {
        b->rating = 0.0;
    } else if(new_rating > 5.0) {
        b->rating = 5.0;
    } else {
        b->rating = new_rating;
    }
}

Book create_book(const char *title, const char *author, int year, double rating) {
    Book b;
    strcpy(b.title, title);
    strcpy(b.author, author);
    b.year = year;
    update_rating(&b, rating);
    return b;
}