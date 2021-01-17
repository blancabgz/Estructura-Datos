OBJ=obj
BIN=bin
SRC=src
INC=include
flags= -std=c++11 -Wall -I/usr/include -I$(INC) -g
INCLUDE = .

all: $(BIN)/ejercicio

doc:
	doxygen ./doc/Doxygen

$(BIN)/ejercicio: $(SRC)/ejercicio.cpp $(SRC)/utilidades.cpp $(INC)/bintree.h  $(INC)/utilidades.h
	g++ -o $@ $^ $(flags)

clean:
	rm $(OBJ)/* $(BIN)/*
