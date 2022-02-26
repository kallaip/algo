ifndef CCX
  CCX = g++
endif

all: stack

stack: main.cpp Stack.h
	clear && $(CCX) -o stack -g -std=c++11 -I. -pedantic -Wall main.cpp 

clean:
	rm stack; clear
	
