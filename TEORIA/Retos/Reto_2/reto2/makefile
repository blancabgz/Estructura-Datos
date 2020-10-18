OBJ=obj
BIN=bin
SRC=src
INC=include

all: $(BIN)/reto2

# Ejecutables
$(BIN)/reto2: $(OBJ)/reto2.o $(OBJ)/colaPieza.o $(OBJ)/imagen.o $(OBJ)/pieza.o $(OBJ)/tablero.o
	g++ -o $(BIN)/reto2 $(OBJ)/reto2.o $(OBJ)/colaPieza.o $(OBJ)/imagen.o $(OBJ)/pieza.o $(OBJ)/tablero.o

#Objetos

$(OBJ)/reto2.o: $(SRC)/reto2.cpp $(INC)/colaPieza.h $(INC)/imagen.h	$(INC)/pieza.h	$(INC)/tablero.h
	g++ -c -o $(OBJ)/reto2.o -I$(INC) $(SRC)/reto2.cpp

$(OBJ)/pieza.o:$(SRC)/pieza.cpp $(INC)/pieza.h	$(INC)/matriz.h
	g++ -c -o $(OBJ)/pieza.o -I$(INC) $(SRC)/pieza.cpp

$(OBJ)/colaPieza.o:$(SRC)/colaPieza.cpp $(INC)/colaPieza.h	$(INC)/pieza.h
	g++ -c -o $(OBJ)/colaPieza.o -I$(INC) $(SRC)/colaPieza.cpp

$(OBJ)/tablero.o:$(SRC)/tablero.cpp $(INC)/tablero.h $(INC)/pieza.h $(INC)/matriz.h
	g++ -c -o $(OBJ)/tablero.o -I$(INC) $(SRC)/tablero.cpp

$(OBJ)/imagen.o:$(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/tablero.h $(INC)/colaPieza.h
	g++ -c -o $(OBJ)/imagen.o -I$(INC) $(SRC)/imagen.cpp

clean:
	rm $(OBJ)/* $(BIN)/*
