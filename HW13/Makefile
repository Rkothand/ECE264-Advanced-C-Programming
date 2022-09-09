# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_MAIN -DDEBUG -DTEST_READLIST -DTEST_CALCULATE -DTEST_DELETELIST -DTEST_ADDNODE -DTEST_DELETENODE

SRCS = main.c calculate.c list.c
OBJS = $(SRCS:%.c=%.o)

hw13: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw13

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw13
	$(VAL) ./hw13 inputs/test1 > expected1
#testing only input3 and expected3

testall: test1 test2 test3 test4 test5

test1: hw13
	./hw13 inputs/test1 >expected1
	diff expected1 expected/expected1

test2: hw13
	./hw13 inputs/test2 >expected2
	diff expected2 expected/expected2

test3: hw13
	./hw13 inputs/test3 >expected3
	diff expected3 expected/expected3

test4: hw13
	./hw13 inputs/test4 >expected4
	diff expected4 expected/expected4

test5: hw13
	./hw13 inputs/test5 >expected5
	diff expected5 expected/expected5


clean: # remove all machine generated files
	rm -f hw13 *.o expected?
