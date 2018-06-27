.PHONY:	clean

default: program

program: main.o tictactoe.o
	g++ main.o tictactoe.o -o h

main.o: main.cpp tictactoe.h
	g++ -c main.cpp

tictactoe.o: tictactoe.cpp tictactoe.h
	g++ -c tictactoe.cpp

clean:
	-@rm -f *.o
	-@rm -f h