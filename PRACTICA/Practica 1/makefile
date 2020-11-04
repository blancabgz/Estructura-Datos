OBJ=obj
BIN=bin
SRC=src
INC=include

all: $(BIN)/ejercicio1

# Ejecutables
$(BIN)/ejercicio1: $(OBJ)/ejercicio1.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/utilidades.o
	g++ -g -o $(BIN)/ejercicio1 $(OBJ)/ejercicio1.o $(OBJ)/utilidades.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(BIN)/negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o
	g++ -g -o $(BIN)/negativo $(OBJ)/negativo.o $(OBJ)/imagenES.o

# Objetos

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	g++ -g -c -o $(OBJ)/imagen.o $(SRC)/imagen.cpp -I$(INC)

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ -g -c -o $(OBJ)/imagenES.o $(SRC)/imagenES.cpp -I$(INC)

$(OBJ)/ejercicio1.o: $(SRC)/ejercicio1.cpp $(INC)/imagen.h $(INC)/imagenES.h
	g++ -g -c -o $(OBJ)/ejercicio1.o $(SRC)/ejercicio1.cpp -I$(INC)

$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	g++ -g -c -o $(OBJ)/negativo.o -I. $(SRC)/negativo.cpp

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
	g++ -g -c -o $(OBJ)/utilidades.o	-I$(INC) $(SRC)/utilidades.cpp



clean:
	echo "Limpieza archivos objeto y biblioteca...."
	rm $(OBJ)/*.o	$(LIB)/*.a

mrproper:	clean
		rm $(BIN)/main
