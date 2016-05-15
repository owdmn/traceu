CFLAGS = -std=gnu99 -Wall -Wextra -c -g

all: tracker

tracker: tracker.o simplex.o
	$(CC) -o $@ $^ -lm

tracker.o: tracker.c
	$(CC) $(CFLAGS) -o $@ $<

simplex.o: simplex.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -f *.o tracker

.PHONY: clean all
