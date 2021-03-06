# Makefile for programming challenges
#
# CSCI 21, Spring 2014
#
# Programmer: Tony Rogers
#
# Target for programming challenge 3
# Date completed: 2-3-2014
flags = -Wall -Wextra -pedantic -Werror

all: pc1 pc2 pc3 pc4 pc5 pc6 pc7 pc8 pc10 pc11 pc12 pc14 pc15 pc16 pc17 pc19 pc20 pc21 pc22 pc23 pc25 project1
pc1: pc1.cpp
	mkdir exec
	g++ -o exec/pc1 pc1.cpp $(flags)
pc2: pc2.cpp
	g++ -o exec/pc2 pc2.cpp $(flags)
pc3: pc3.cpp
	g++ -o exec/pc3 pc3.cpp $(flags)
pc4: pc4.cpp
	g++ -o exec/pc4 pc4.cpp $(flags)
pc5: pc5.cpp
	g++ -o exec/pc5 pc5.cpp $(flags)
pc6: pc6.cpp
	g++ -o exec/pc6 pc6.cpp $(flags)
pc7: pc7.cpp
	g++ -o exec/pc7 pc7.cpp $(flags)
pc8: pc8.cpp
	g++ -o exec/pc8 pc8.cpp $(flags)
#pc9: pc9.cpp
#	g++ -o challenge-9 pc9.cpp $(flags)
pc10: pc10.cpp
	g++ -o exec/pc10 pc10.cpp $(flags)
pc11: pc11.cpp
	g++ -o exec/pc11 pc11.cpp $(flags)
pc12: pc12.cpp
	g++ -o exec/pc12 pc12.cpp $(flags)
pc14: pc14.cpp
	g++ -o exec/pc14 pc14.cpp $(flags)
pc15: pc15.cpp
	g++ -o exec/pc15 pc15.cpp $(flags)
pc16: pc16.cpp
	g++ -o exec/pc16 pc16.cpp $(flags)

pc17: SLNode.o pc17.o
	g++ $(flags) SLNode.o pc17.o -o exec/pc17 

project1: project1.cpp
	g++ -o project-1 project1.cpp $(flags)

pc17.o: pc17.cpp
	g++ -c pc17.cpp -o pc17.o

pc19.o: pc19.cpp
	g++ -c pc19.cpp -o pc19.o
	
pc19: pc19.o SList.o SLNode.o
	g++ -o exec/pc19 pc19.o SList.o SLNode.o

pc20.o: pc20.cpp
	g++ -c pc20.cpp -o pc20.o
	
pc20: pc20.o SList.o SLNode.o
	g++ -o exec/pc20 pc20.o SList.o SLNode.o
	
SLNode.o: SLNode.h SLNode.cpp
	g++ -c SLNode.cpp -o SLNode.o
	
SList.o: SList.h SList.cpp
	g++ -c SList.cpp -o SList.o
	
pc21: pc21.cpp
	g++ -o exec/pc21 pc21.cpp

pc22: pc22.cpp
	g++ -o exec/pc22 pc22.cpp
	
pc23: pc23.cpp
	g++ -o exec/pc23 pc23.cpp
	
pc25: pc25.cpp
	g++ -o exec/pc25 pc25.cpp $(flags)