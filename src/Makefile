CFLAGS = -std=gnu99 -Wall -Wextra -c -g

all: strace

strace: strace.o simplex.o
	$(CC) -o $@ $^ -lm

strace.o: strace.c
	$(CC) $(CFLAGS) -o $@ $<

simplex.o: simplex.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -f *.o tracker

.PHONY: clean all
