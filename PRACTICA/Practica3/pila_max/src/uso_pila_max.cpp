#include <iostream>
#include <Pila_max.h>
#include <elemento.h>

using namespace std;

int main(){
	Pila_max<int> p;

	for(int i=10; i>=0; i--){
		p.poner(i);
	}

	// TEST 2
		// p.poner(2);
		// p.poner(7);
		// p.poner(2);
		// p.poner(2);
		// p.poner(9);


	//TEST 3
		// for(int i=0; i<10; i++){
		// 	p.poner(i);
		// }
		//

	while(!p.vacia()){
		elemento<int> x = p.tope();
		cout << x << endl;
		p.quitar();
	}

	return 0;
}
