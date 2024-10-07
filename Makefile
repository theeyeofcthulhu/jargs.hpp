CC=g++
CFLAGS=-Wall -Wextra -std=c++23 -ggdb

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXE=$(OBJ:.o=)

JARGS_HPP=jargs.hpp

PREFIX=/usr/local

all: $(EXE)

clean:
	rm -f $(OBJ) $(EXE)

$(OBJ): %.o: %.cpp $(JARGS_HPP)
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXE): %: %.o
	$(CC) -o $@ $<

install: $(DBG_H)
	install -m755 $(DBG_H) $(PREFIX)/include
