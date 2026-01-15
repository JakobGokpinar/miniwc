#include <unistd.h>

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

size_t my_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

size_t count_chars(const char *buf, size_t len);

int main(int argc, char *argv[]) {
   
    char buf[4096]; 
    ssize_t n;
    size_t total = 0;
    int fd = 0;
    while ( (n = read(fd, buf, sizeof(buf)) ) > 0) {
        total += count_chars(buf, n);
    }

    if (n < 0) {
        write(2, "read error\n", 11);
    }

    write_int(total);

    return 0;
}

 /*write(1, "miniwc starting\n", 17);
    write(1, "\n", 1);
    for (int i = 0; i < argc; i++) {
        write(1, "arg[", 4);
        write_int(i);
        write(1, "] = ", 4);
        write(1, argv[i], n);
        write(1, "\n", 1);
}*/