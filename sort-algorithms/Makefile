CC = gcc
override CFLAGS += -Wall -Wextra -g
MAIN = main.c

SORT_ALGORITHMS = selection insertion bubble shaker quick

all: $(SORT_ALGORITHMS)

%: %_sort.c
	$(CC) $(CFLAGS) -o $@ $^ $(MAIN)

clean:
	rm -f $(SORT_ALGORITHMS)
