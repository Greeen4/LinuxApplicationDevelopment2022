LIBFLAGS = -shared -fPIC 
CFLAGS = -Wall -g
CC = cc

all: protect.so move tests

protect.so: protect.c
	$(CC) $^ $(LIBFLAGS) -o $@ -ldl

move: move.c
	$(CC) $^ $(CFLAGS) -o $@

tests: tests.sh
	/bin/bash ./tests.sh

clean:
	rm -rf move *.txt *.so 
