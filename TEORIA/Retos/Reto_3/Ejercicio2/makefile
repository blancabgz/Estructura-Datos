OBJ=obj
BIN=bin
SRC=src
INC=include

all: $(BIN)/ejercicio

doc:
	doxygen ./doc/Doxygen

# Ejecutables
$(BIN)/ejercicio: $(OBJ)/ejercicio.o $(OBJ)/utilidades.o
	g++ -g -o $(BIN)/ejercicio $(OBJ)/ejercicio.o $(OBJ)/utilidades.o

$(OBJ)/ejercicio.o: $(SRC)/ejercicio.cpp
	g++ -g -c -o $(OBJ)/ejercicio.o $(SRC)/ejercicio.cpp -I$(INC)

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
	g++ -g -c -o $(OBJ)/utilidades.o	-I$(INC) $(SRC)/utilidades.cpp -I$(INC)

.PHONY: all doc

clean:
	rm $(OBJ)/* $(BIN)/*
