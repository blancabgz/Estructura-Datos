OBJ=obj
BIN=bin
SRC=src
INC=include
flags= -std=c++11 -Wall -I/usr/include -I$(INC) -g

all: $(BIN)/usoguia

$(BIN)/usoguia: $(SRC)/usoguia.cpp $(SRC)/guiatlf.cpp $(INC)/guiatlf.h
	g++ -o $@ $^ $(flags)


clean:
	echo "Limpieza archivos objeto y biblioteca...."
	rm $(OBJ)/*.o	$(LIB)/*.a
