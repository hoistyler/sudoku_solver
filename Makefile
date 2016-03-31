RM=rm -r
Q=@
CFLAGS=-ggdb

all: sudoku_solver.cpp
	g++ $(CFLAGS) -o sudoku_solver sudoku_solver.cpp -I.

clean:
	$(RM) sudoku_solver
