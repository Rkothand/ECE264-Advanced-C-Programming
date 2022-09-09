# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_EXx

SRCS = list(2).c
OBJS = $(SRCS:%.c=%.o)

list(2): $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o list(2)

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: list(2)
	$(VAL) ./list(2)
#testing only input3 and output3


clean: # remove all machine generated files
	rm -f list(2) *.o output?.bin
