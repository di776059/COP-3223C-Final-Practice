#include <stdio.h>

int main(void) {
    int  a = 10;
    int  b = 20;
    int *p = &a;
    printf("a        = %d\n",  a);        /* predict: ___10__ */     
    printf("b        = %d\n",  b);        /* predict: ___20__ */    
    printf("*p       = %d\n",  *p);       /* predict: __10___ */   
    printf("p == &a? = %d\n",  p == &a);  /* predict: __True___ */
   
    *p = 99;
    printf("\nAfter *p = 99:\n");
    printf("a        = %d\n",  a);      /* predict: __99___ */  
    printf("*p       = %d\n",  *p);     /* predict: ___99__ */  
    
    p = &b;

    printf("\nAfter p = &b:\n");
    printf("*p       = %d\n",  *p);    /* predict: __20___ */   
    printf("a        = %d\n",  a);     /* predict: __99___ */   

    *p = *p + 5;
    printf("\nAfter *p = *p + 5:\n");   
    printf("b        = %d\n",  b);      /* predict: _25____ */   
    return 0;
}
