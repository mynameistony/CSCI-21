#
# Grader comments 2014.02.05
#
# You need to update your makefile such that it
# can actually be used for building your source
# code.
#
# Grader comments 2014.02.10
#
# Still makefile issues. I'll ask Boyd to go
# over makefiles again in class on Wednesday. --Rob
#
# Makefile for programming challenges
#
# CSCI 21, Spring 2014
#
# Programmer: Tony Rogers
#

# Target for programming challenge 3
# Date completed: 2-3-2014
all: project1.cpp pc1.cpp pc2.cpp pc3.cpp pc4.cpp pc5.cpp pc6.cpp
	g++ -o project-1 project1.cpp
	g++ -o challenge-1 pc1.cpp
	g++ -o challenge-2 pc2.cpp
	g++ -o challenge-3 pc3.cpp
	g++ -o challenge-4 pc4.cpp
	g++ -o challenge-5 pc5.cpp
	g++ -o challenge-6 pc6.cpp
