#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]) {
    printf("miniwc starting\n");
    printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}