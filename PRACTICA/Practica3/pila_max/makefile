OBJ = obj
BIN = bin
SRC = src
INC = include
CPPFLAGS = -Wall -g  -I$(INC) -std=c++11
INCLUDES = $(INC)/cola.h  $(INC)/elemento.h $(INC)/pila_max_cola.h $(INC)/Pila_max.h $(INC)/pila_max_vd.h

all: $(BIN)/uso_pila_max

doc:
	doxygen ./doc/Doxygen

$(BIN)/uso_pila_max: $(SRC)/uso_pila_max.cpp $(INCLUDES)
	g++ -o $@ $< $(CPPFLAGS)
