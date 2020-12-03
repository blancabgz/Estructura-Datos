SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usopilas $(BIN)/usocolas $(BIN)/usopilas_min
all2: $(BIN)usovd
all3: $(BIN)/usolista
$(BIN)/usopilas: $(OBJ)/usopilas.o
	$(CXX) -o $(BIN)/usopilas $(OBJ)/usopilas.o 
$(OBJ)/usopilas.o: $(INC)/pila.h $(SRC)/usopilas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usopilas.cpp  -o $(OBJ)/usopilas.o -I$(INC)
    

$(BIN)/usocolas: $(OBJ)/usocolas.o
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o 
$(OBJ)/usocolas.o: $(INC)/cola.h $(SRC)/usocolas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o -I$(INC)

$(BIN)usovd: $(OBJ)/usovd.o
	$(CXX) -o $(BIN)/usovd $(OBJ)/usovd.o 
	
$(OBJ)/usovd.o: $(INC)/vd.h $(SRC)/usovd.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usovd.cpp  -o $(OBJ)/usovd.o -I$(INC)

$(BIN)/usolista: $(OBJ)/usolista.o
	$(CXX) -o $(BIN)/usolista $(OBJ)/usolista.o 

	
$(OBJ)/usolista.o: $(INC)/lista.h $(SRC)/usolista.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usolista.cpp  -o $(OBJ)/usolista.o -I$(INC)	
	
$(BIN)/usopilas_min: $(OBJ)/usopilas_min.o 
	$(CXX) -o $(BIN)/usopilas_min $(OBJ)/usopilas_min.o 
	
#pila_min con vd
#$(OBJ)/usopilas_min.o:$(SRC)/usopilas_min.cpp $(INC)/pila_min_vd.h
#	$(CXX) $(CPPFLAGS)  $(SRC)/usopilas_min.cpp  -o $(OBJ)/usopilas_min.o -I$(INC)
	
#pila_min con listas	
#$(OBJ)/usopilas_min.o:$(SRC)/usopilas_min.cpp $(INC)/pila_min_lista.h
#	$(CXX) $(CPPFLAGS)  $(SRC)/usopilas_min.cpp  -o $(OBJ)/usopilas_min.o -I$(INC)	
	
#pila_min: escogiendo la representacion de pila_min segun CUAL_COMPILA en pila_min.h
$(OBJ)/usopilas_min.o:$(SRC)/usopilas_min.cpp $(INC)/pila_min.h
	$(CXX) $(CPPFLAGS)  $(SRC)/usopilas_min.cpp  -o $(OBJ)/usopilas_min.o -I$(INC)	

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
