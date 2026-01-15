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
