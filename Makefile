CC=clang
CFLAGS=-Wall -Wextra -g

all: test

test: main.c count_chars.s
	$(CC) main.c count_chars.s -o test

clean:
	rm -f test
