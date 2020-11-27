OBJ=obj
BIN=bin
SRC=src
INC=include

all: $(BIN)/main_pilamax $(BIN)/main_pilamaxcola $(BIN)/main_pilamaxvd

# Ejecutables

$(BIN)/main_pilamax: $(OBJ)/main_pilamax.o $(OBJ)/Pila_max.o
	g++ -g -o $(BIN)/main_pilamax $(OBJ)/main_pilamax.o $(OBJ)/Pila_max.o

$(BIN)/main_pilamaxcola: $(OBJ)/main_pilamaxcola.o $(OBJ)/Pila_max_Cola.o
	g++ -g -o $(BIN)/main_pilamaxcola $(OBJ)/main_pilamaxcola.o $(OBJ)/Pila_max_Cola.o

$(BIN)/main_pilamaxvd: $(OBJ)/main_pilamaxvd.o $(OBJ)/Pila_max_VD.o
	g++ -g -o $(BIN)/main_pilamaxvd $(OBJ)/main_pilamaxvd.o $(OBJ)/Pila_max_VD.o

#Objetos

$(OBJ)/Pila_max.o: $(SRC)/Pila_max.cpp $(INC)/Pila_max.h
	g++ -g -c -o $(OBJ)/Pila_max.o $(SRC)/Pila_max.cpp -I$(INC)

$(OBJ)/main_pilamax.o: $(SRC)/main_pilamax.cpp $(INC)/Pila_max.h
	g++ -g -c -o $(OBJ)/main_pilamax.o $(SRC)/main_pilamax.cpp -I$(INC)


$(OBJ)/Pila_max_Cola.o: $(SRC)/Pila_max_Cola.cpp $(INC)/Pila_max_Cola.h
	g++ -g -c -o $(OBJ)/Pila_max_Cola.o $(SRC)/Pila_max_Cola.cpp -I$(INC)

$(OBJ)/main_pilamaxcola.o: $(SRC)/main_pilamaxcola.cpp $(INC)/Pila_max_Cola.h
	g++ -g -c -o $(OBJ)/main_pilamaxcola.o $(SRC)/main_pilamaxcola.cpp -I$(INC)

$(OBJ)/Pila_max_VD.o: $(SRC)/Pila_max_VD.cpp $(INC)/Pila_max_VD.h
	g++ -g -c -o $(OBJ)/Pila_max_VD.o $(SRC)/Pila_max_VD.cpp -I$(INC)

$(OBJ)/main_pilamaxvd.o: $(SRC)/main_pilamaxvd.cpp $(INC)/Pila_max_VD.h
	g++ -g -c -o $(OBJ)/main_pilamaxvd.o $(SRC)/main_pilamaxvd.cpp -I$(INC)
