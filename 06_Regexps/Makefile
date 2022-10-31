CFLAGS = -Wall -g
CC = cc
GEN = esub esub?_res sed?_res

all: esub

esub: esub.c
	$(CC) $^ $(CFLAGS) -o $@ 2> /dev/null

test1: esub
	echo 'string' | sed -E 's/regexp/substitution/' > sed1_res
	./esub 'regexp' 'substitution' 'string' > esub1_res
	diff sed1_res esub1_res

test2: esub
	echo 'testing regex data' | sed -E 's/(x)(.*)a/\\+kkk-lll*_*miu\\\1 \2/' > sed2_res
	./esub '(x)(.*)a' '\\\+kkk-lll*_*miu\\\1 \2' 'testing regex data' > esub2_res
	diff sed2_res esub2_res

test: test1 test2

clean: 
	rm -rf $(GEN)
