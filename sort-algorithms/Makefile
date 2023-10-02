CC = gcc
override CFLAGS += -Wall -Wextra -g
MAIN = main.c

SORT_ALGORITHMS = selection insertion bubble shaker shell merge quick

MACRO ?= DEFAULT_VALUE

all: $(SORT_ALGORITHMS)

%: %_sort.c
	$(CC) $(CFLAGS) -o $@ $^ $(MAIN) -D$(MACRO)

clean:
	rm -f $(SORT_ALGORITHMS)
