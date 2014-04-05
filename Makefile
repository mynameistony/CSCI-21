FLAGS = -Wall -Wextra -Werror -pedantic

project2: prize.o box.o main.o 
	g++ $(FLAGS) prize.o box.o main.o -o project-2
	rm -f *.o

unittest: prize.o box.o unit.o 
	g++ $(FLAGS) prize.o box.o unit.o -o unittest
	rm -f *.o

test: prize.o box.o test.o 
	g++ $(FLAGS) prize.o box.o test.o -o box
	rm -f *.o

unit.o: unittest.cpp
	g++ $(FLAGS) -c unittest.cpp -o unit.o

main.o: maintest.cpp
	g++ $(FLAGS) -c maintest.cpp -o main.o

test.o: newMain.cpp
	g++ $(FLAGS) -c newMain.cpp -o test.o

cin.o: CinReader.h CinReader.cpp
	g++ -c CinReader.cpp -o cin.o

box.o: box.h box.cpp
	g++ $(FLAGS) -c box.cpp -o box.o

prize.o: prize.h prize.cpp
	g++ $(FLAGS) -c prize.cpp -o prize.o

cleanall: clean
	rm -f project-2

clean: 
	rm -f *.o
