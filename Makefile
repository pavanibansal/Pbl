CC = clang
CFLAGS = -std=c17 -Wall -Wextra

SOURCES = main.c issues.c developers.c assignment.c \
          persistence.c reports.c sorting_searching.c \
          graph.c dynamic_programming.c benchmark.c

all:
	$(CC) $(CFLAGS) $(SOURCES) -o issue_triage

run: all
	./issue_triage

clean:
	rm -f issue_triage