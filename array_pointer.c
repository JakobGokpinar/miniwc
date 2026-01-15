#include <stdio.h>
#include <stdlib.h>

/* Phase 1: Pointer Basics */
void phase1_basic_pointer(void) {
    int x = 10;
    int *p = &x;

    printf("x = %d\n", x);
    printf("&x = %p\n", (void*)&x);
    printf("p = %p\n", (void*)p);
    printf("*p = %d\n", *p);

    *p = 20;
    printf("x after = %d\n", x);
}

/* Phase 2: Stack vs Heap */
int* bad(void) {
    int x = 42;
    return &x;   // dangling pointer
}

int* good(void) {
    int *x = malloc(sizeof(int));
    *x = 42;
    return x;
}

void phase2_stack_vs_heap(void) {
    int *a = bad();
    int *b = good();

    printf("bad (UB): %d\n", *a);
    printf("good: %d\n", *b);

    free(b);
}

/* Phase 3: Arrays & Pointer Arithmetic */
void phase3_arrays_and_pointers(void) {
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;

    printf("&a      = %p\n", (void*)&a);
    printf("&a[0]   = %p\n", (void*)&a[0]);
    printf("p       = %p\n", (void*)p);

    printf("sizeof(a) = %zu\n", sizeof(a));
    printf("sizeof(p) = %zu\n", sizeof(p));

    a[1] = 100;
    *(p + 2) = 110;

    printf("a[1] = %d\n", a[1]);
    printf("a[2] = %d\n", a[2]);
}


int main(void) {
    printf("=== Phase 1 ===\n");
    phase1_basic_pointer();

    printf("\n=== Phase 2 ===\n");
    phase2_stack_vs_heap();

    printf("\n=== Phase 3 ===\n");
    phase3_arrays_and_pointers();

    return 0;
}
