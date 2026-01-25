#include <stddef.h>
#include <unistd.h>

struct wc_state {
    int in_word;
    size_t words;
};

static int is_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

void process_buffer(struct wc_state *st, const char *buf, size_t len) {
    for (size_t i = 0; i < len; i++) {
        char c = buf[i];

        if (is_whitespace(c)) {
            st->in_word = 0;
        } else {
            if (st->in_word == 0) {
                st->words++;
                st->in_word = 1;
            }
        }
    }
}

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

    struct wc_state st;
    st.in_word = 0;
    st.words = 0;

    while ( (n = read(fd, buf, sizeof(buf))) > 0 ) {
        process_buffer(&st, buf, (size_t)n);
    }

    if (n < 0) {
        write(2, "read error\n", 11);
        return 1;
    }

    write_int(st.words);
    write(1, "\n", 1);


    return 0;
}
