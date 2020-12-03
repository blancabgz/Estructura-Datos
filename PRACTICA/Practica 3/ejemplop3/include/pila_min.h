#define CUAL_COMPILA 3

#if CUAL_COMPILA==1
#include <pila_min_vd.h>
#elif CUAL_COMPILA==2
#include <pila_min_lista.h>
#else
 #include <pila_min_cola.h>
#endif
