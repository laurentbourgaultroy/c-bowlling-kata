CFLAGS=-g -Wall

.PHONY: test clean

all: bin/test
	@valgrind $^

clean:
	rm -rf bin/*

bin/test: bowling_test.c bowling.c
	@mkdir -p bin
	@gcc $(CFLAGS) -o $@ $^
