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