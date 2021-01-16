// Usando el TDA list <int>, construir una funcion void agrupar_elemento (list <int> & entrada, int k) que
// agrupe de forma consecutiva en la lista de entrada todas las apariciones del elemento k en la lista, a partir
// de la primera ocurrencia.
// entrada = {1,3,4,1,4,4} con k = 1 tiene que salir entrada = {1,1,3,4,4,4}


// SOLUCION
// lo primero que tengo que hacer es buscar la primera ocurrencia de k y almacenar su posición
// recorrer entrada buscando k y cuando encuentre una, inserto en la posicion y borraar elemento

void agrupar_elemento(list <int> & entrada, int k){
  list<int>::iterator p,q;
  p = entrada.find(entrada.begin(),entrada.end(), k);
  q = ++p;

  // mientras no llegues al final de la lista
  while(q!= entrada.end()){
    if(*q == k){
      entrada.insert(p,k);
      q = entrada.erase(q);
    }else{
      ++q;
    }
  }
}
