OBJ=obj
BIN=bin
SRC=src
INC=include

all: $(BIN)/main

# Ejecutables
$(BIN)/main: $(OBJ)/main.o $(OBJ)/imagen.o
	g++ -o $(BIN)/main $(OBJ)/main.o $(OBJ)/imagen.o

# Objetos

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	g++ -c -o $(OBJ)/imagen.o $(SRC)/imagen.cpp -I$(INC)

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/imagen.h
	g++ -c -o $(OBJ)/main.o $(SRC)/main.cpp -I$(INC)


clean:
	echo "Limpieza archivos objeto y biblioteca...."
	rm $(OBJ)/*.o	$(LIB)/*.a

mrproper:	clean
		rm $(BIN)/principal
