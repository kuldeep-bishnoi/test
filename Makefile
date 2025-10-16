CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror
TARGETS = problem1 problem2 problem3

all: $(TARGETS)

problem1: problem1.c
	$(CC) $(CFLAGS) -o problem1 problem1.c

problem2: problem2.c
	$(CC) $(CFLAGS) -o problem2 problem2.c

problem3: problem3.c
	$(CC) $(CFLAGS) -o problem3 problem3.c

clean:
	rm -f $(TARGETS)

test: all
	@echo "Running all test cases..."
	@chmod +x test_all.sh
	@./test_all.sh

.PHONY: all clean test
