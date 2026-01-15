#include <stdio.h>

int main(void) {
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;

    printf("&a = %p\n", (void*)&a);
    printf("&a[0] = %p\n", (void*)&a[0]);
    printf("p = %p\n", (void*)p);
    printf("sizeof(a) = %zu\n", sizeof(a)); //sizeof returns size_t = unsigned long
    printf("sizeof(p) = %zu\n", sizeof(p));

    printf("a[1] = %d\n", a[1]);
    printf("a[2] = %d\n", a[2]);

    a[1] = 100;
    //pointer arithmetic
    *(p+2) = 110; //If you remove the *, you stop accessing memory and you are left with an address only.

    printf("a[1] = %d\n", a[1]);
    printf("a[2] = %d\n", a[2]);

    return 0;
}

//Phase1
/*int main(void) {
    int x = 10;
    int *p = &x;

    printf("x = %d\n", x);
    printf("&x = %p\n", (void*)&x);
    printf("p = %p\n", (void*)p);
    printf("*p = %d\n", *p);

    *p = 20;
    printf("x after = %d\n", x);
 
    return 0;
}*/

//Phase2
/*int* bad(void) {
    int x = 42;
    return &x;
}
int* good(void) {
    int *x = malloc(sizeof(int));
    *x = 42;
    return x;
}
int main(void) {
    int *a = bad();
    int *b = good();

    printf("bad: %d\n", *a); //undefined behaviour
    printf("good: %d\n", *b);

    free(b);
    return 0;
}*/