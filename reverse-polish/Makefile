ifndef CCX
  CCX = g++
endif

all: reverse-polish

reverse-polish: main.cpp ../stack/Stack.h Tokenizer.cpp Tokenizer.h ReversePolish.cpp ReversePolish.h
	clear && $(CCX) -o reverse-polish -g -std=c++11 -I. -I../stack -pedantic -Wall main.cpp Tokenizer.cpp ReversePolish.cpp

clean:
	rm reverse-polish; clear
