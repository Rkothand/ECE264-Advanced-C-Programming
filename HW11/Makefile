# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic 
ERROR = -Wvla 
GCC = gcc -ggdb -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE -DDEBUG

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

shuffle: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o shuffle

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 

test1: shuffle
	./shuffle 4 |sort > output4
	diff output4 expected/expected4

test2: shuffle
	./shuffle 8  |sort > output8
	diff output8 expected/expected8

test3: shuffle
	./shuffle 11  |sort > output11
	diff output11 expected/expected11

memory: shuffle
	valgrind ./shuffle 8

clean: # remove all machine generated files
	rm -f shuffle *.o output?


