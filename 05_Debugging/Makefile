CFLAGS = -Wall -Werror -g -o0
GEN = prog prog-a* prog-so *.a *.o *.so *_output *_error
COMPILER = cc

range:	range.c
	$(COMPILER) $(CFLAGS) $^ -o $@

test%.gdb:	scrt%.gdb range
	gdb -x scrt1.gdb ./range | grep @@@ | tr -d '@' > test1.gdb
	gdb -x scrt2.gdb ./range | grep @@@ | tr -d '@' > test2.gdb

test1:	test1.gdb answer1.gdb
	diff $^

test2:	test2.gdb answer2.gdb
	diff $^

test:	test1 test2

clean:
	rm -f $(GEN)
