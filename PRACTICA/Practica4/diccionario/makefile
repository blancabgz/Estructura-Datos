OBJ=obj
BIN=bin
SRC=src
INC=include
CPPFLAGS = -Wall -g  -I$(INC) -std=c++11
INCLUDES = $(INC)/diccionario.h $(INC)/data.h


all: $(BIN)/usodiccionario
doc:
	doxygen ./doc/Doxygen


# Ejecutables
$(BIN)/usodiccionario: $(SRC)/usodiccionario.cpp $(INCLUDES)
	g++ -o $@ $< $(CPPFLAGS)

clean:
	echo "Limpieza archivos objeto y biblioteca...."
	rm 	$(BIN)/*
