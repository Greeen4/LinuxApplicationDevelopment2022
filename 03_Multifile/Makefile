CFLAGS = -Wall -Werror -g
GENER = prog prog-a* prog-so *.a *.o *.so *_output *_error
COMPILER = cc
ST = -fPIC
LIB_PATH = $(PWD)

all: prog liboutput_static.a prog-a liboutput.so prog-so

fun.o: fun.c outlib.h
	$(COMPILER) $(CFLAGS) $(ST) -o $@ -c $<

const.o: const.c
	$(COMPILER) $(CFLAGS) $(ST) -o $@ -c $<

prog.o: prog.c outlib.h
	$(COMPILER) $(CFLAGS) -o $@ -c $<

prog: fun.o const.o prog.o
	$(COMPILER) $(CFLAGS)  $^ -o $@

liboutput_static.a: fun.o const.o
	ar -rcs liboutput_static.a $^

prog-a: prog.o liboutput_static.a
	$(COMPILER) $(CFLAGS)  $^ -o $@

liboutput.so: fun.o const.o
	$(COMPILER) $(CFLAGS) $(ST) -shared $^ -o $@

prog-so: prog.o liboutput.so
	$(COMPILER) $(CFLAGS)  $^ -o $@

test: cmp_tests

run_tests: prog prog-a prog-so
	./prog 1> prog1_output 2> prog1_error
	./prog abra 1> prog2_output 2> prog2_error
	./prog abra ka dabra 1> prog3_output 2> prog3_error
	./prog-a 1> prog-a_1_output 2> prog-a_1_error
	./prog-a abra 1> prog-a_2_output 2> prog-a_2_error
	./prog-a abra ka dabra 1> prog-a_3_output 2> prog-a_3_error
	LD_LIBRARY_PATH=$(LIB_PATH) ./prog-so 1> prog-so_1_output 2> prog-so_1_error
	LD_LIBRARY_PATH=$(LIB_PATH) ./prog-so abra 1> prog-so_2_output 2> prog-so_2_error
	LD_LIBRARY_PATH=$(LIB_PATH) ./prog-so abra ka dabra 1> prog-so_3_output 2> prog-so_3_error

cmp_tests: run_tests
	cmp prog1_output prog-a_1_output
	cmp prog1_output prog-so_1_output
	cmp prog2_output prog-a_2_output
	cmp prog2_output prog-so_2_output
	cmp prog3_output prog-a_3_output
	cmp prog3_output prog-so_3_output
	cmp prog1_error prog-a_1_error
	cmp prog1_error prog-so_1_error
	cmp prog2_error prog-a_2_error
	cmp prog2_error prog-so_2_error
	cmp prog3_error prog-a_3_error
	cmp prog3_error prog-so_3_error

clean:
	rm -f $(GENER)
