# include <stdio.h>

void triple(int x);
int triple_return(int x);
void add_ten(int a, int b);

int main(void) {
   int num = 3;
   int a = 5;
   int b = 4;

    /*Part A*/
    printf("Part A:\n");
    printf("Before triple: %d\n", num);
    triple(num);    
    printf("After triple: %d\n", num);

    /*Part B*/
    printf("Part B:\n");
    printf("Before triple_return: %d\n", num);
    num = triple_return(num);
    printf("After the triple_return: %d\n\n", num);

   /*Part C*/
   printf("Part C:\n");
   printf("Before add_ten: a = %d, b = %d\n", a, b);
   add_ten(a, b);
   printf("After add_ten: a = %d, b = %d\n", a, b);
   
   /*Part D*/
   printf("Part D\n");
   int n = 7;
   triple(n);
   printf("n after triple(n): %d\n", n);
   int result = triple_return(n);
   printf("result: %d, n: %d\n", result, n);
   return 0;
}

/*Part A*/
 void triple(int x) {
    x *= 3;
    printf("Inside triple: %d\n", x);
 }

 /*Part B*/
 int triple_return(int x) {
    x *= 3;
    return x;
 }

 /*Part C*/
 void add_ten(int a, int b) {
   a += 10;
   b += 10;

   printf("Inside add ten: a = %d, b = %d\n", a , b);
 }