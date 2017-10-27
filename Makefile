CFLAGS=-Wall

.PHONY: test

all: test
	@bin/test

test: bowling_test.c bowling.c
	@mkdir -p bin
	gcc $(CFLAGS) -o bin/$@ $^
