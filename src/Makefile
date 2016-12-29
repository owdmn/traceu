CFLAGS = -std=gnu99 -Wall -Wextra -c -g

all: strace

strace: main.o trace.o simplex.o
	$(CC) -o $@ $^ -lm

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $<

trace.o: trace.c
	$(CC) $(CFLAGS) -o $@ $<

simplex.o: simplex.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -f *.o traceu 

.PHONY: clean all
