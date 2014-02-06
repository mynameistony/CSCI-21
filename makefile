#
# Grader comments 2014.02.05
#
# You need to update your makefile such that it
# can actually be used for building your source
# code.
#
# Makefile for programming challenges
#
# CSCI 21, Spring 2014
#
# Programmer: Tony Rogers
#

# Target for programming challenge 3
# Date completed: 2-3-2014
all: pc1.cpp pc2.cpp pc3.cpp

challenge-3: pc3.cpp
	g++ -o challenge-3 pc3.cpp
challenge-2: pc2.cpp
	g++ -o challenge-2 pc2.cpp
challenge-1: pc1.cpp
	g++ -o challenge-1 pc1.cpp
