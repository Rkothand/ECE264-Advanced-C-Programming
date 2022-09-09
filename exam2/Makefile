WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
TESTFLAGS = -Dexam
SRCS = q11.c

OBJS = $(SRCS:%.c=%.o)
q11: $(OBJS) 
	$(GCC) $(TESTFLAGS) $(OBJS) -o q11

.c.o: 
	$(GCC) $(TESTFLAGS) -c $*.c 

test1: q11
	./q11 
clean: # remove all machine generated files
	rm -f q11 *.o *.out *gcda *gcno *gcov

