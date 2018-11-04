CC=gcc
CFLAGS=-I .

all: test

run: test
	./test

test: test.o utermie.o
	$(CC) -o test test.o utermie.o

utermie.o: utermie.c
	$(CC) -c -o utermie.o utermie.c $(CFLAGS)

test.o: test.c
	$(CC) -c -o test.o test.c $(CFLAGS)

.PHONY: clean

clean:
	rm test
	rm -f *.o
