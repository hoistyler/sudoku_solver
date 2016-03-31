RM=rm -r
Q=@

all: sudoku_solver.cpp
	g++ -o sudoku_solver sudoku_solver.cpp -I.

clean:
	$(RM) sudoku_solver
