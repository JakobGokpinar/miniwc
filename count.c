#include <stddef.h>

size_t count_chars_c(const char *buf, size_t len) {
    size_t count = 0;
    for (size_t i = 0; i < len; i++) {
        count++;
    }
    return count;
}