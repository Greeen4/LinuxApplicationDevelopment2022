AM_CFLAGS = -Wall -O0 -g

bin_PROGRAMS=rhasher

rhasher_SOURCES=./rhasher.c

gitclean:
	git clean -df

test: rhasher
	./rash.sh
