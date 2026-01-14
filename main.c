//#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>

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

void write_int(int x) {
    char buf[12];
    int i = 0;

    if(x == 0) {
        buf[i++] = '0';
    } else {
        while (x > 0) {
            buf[i++] = '0' + (x%10);
            x /= 10;
        }
    }

    for (int j = 0; j < i/2; j++) {
        char tmp = buf[j];
        buf[j] = buf[i-j-1];
        buf[i-j-1] = tmp;
    }

    write(1, buf, i);
}

/*size_t my_strlen_1(const char *s) {
    size_t length = 0;

    const char *p = s;
    while (*p != '\0') {
        p++;
        length++;
    }
    return length;
}*/

size_t my_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

size_t count_chars(const char *buf, size_t len);
/*
    size_t count = 0;
    while (count < len) {
        count++;
    }
    return count;
*/

int main(int argc, char *argv[]) {
    write(1, "miniwc starting\n", 17);
    write(1, "\n", 1);

    for (int i = 0; i < argc; i++) {
        size_t n = count_chars(argv[i], my_strlen(argv[i]));

        write(1, "arg[", 4);
        write_int(i);
        write(1, "] = ", 4);
        write(1, argv[i], n);
        write(1, "\n", 1);
    }

    return 0;
}