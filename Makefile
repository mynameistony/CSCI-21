# Makefile for programming challenges
#
# CSCI 21, Spring 2014
#
# Programmer: Tony Rogers
#
# Target for programming challenge 3
# Date completed: 2-3-2014
flags = -Wall -Wextra -pedantic -Werror

all: pc1 pc2 pc3 pc4 pc5 pc6 pc7 pc8 project1
pc1: pc1.cpp
	g++ -o challenge-1 pc1.cpp $(flags)
pc2: pc2.cpp
	g++ -o challenge-2 pc2.cpp $(flags)
pc3: pc3.cpp
	g++ -o challenge-3 pc3.cpp $(flags)
pc4: pc4.cpp
	g++ -o challenge-4 pc4.cpp $(flags)
pc5: pc5.cpp
	g++ -o challenge-5 pc5.cpp $(flags)
pc6: pc6.cpp
	g++ -o challenge-6 pc6.cpp $(flags)
pc7: pc7.cpp
	g++ -o challenge-7 pc7.cpp $(flags)
pc8: pc8.cpp
	g++ -o challenge-8 pc8.cpp $(flags)
project1: project1.cpp
	g++ -o project-1 project1.cpp $(flags)
