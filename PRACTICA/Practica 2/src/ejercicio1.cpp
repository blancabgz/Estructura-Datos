#include <iostream>
#include <cmath>
#include <cstring>
#include "imagen.h"
#include "imagenES.h"
#include "utilidades.h"
using namespace std;

int main() {
  // decision del usuario
  int seleccion;



  cout << "--------------------------------------------------------" << endl;
  cout << "Elige una opcion" << endl;
  cout << "Marca 1 para umbralizar una imagen usando una escala de grises" << endl;
  cout << "Marca 2 para crear un icono a partir de una imagen" << endl;
  cout << "Marca 3 para convertir una imagen RGB a niveles de gris"  << endl;

  cout << "Seleccion: ";
  cin >> seleccion;
  switch (seleccion){
    case 1:{
      //case 1 variables
      unsigned char *img, *imgfinal_eg;
      bool escribe_imagen;
      string seleccion_imagen;
      int fila, columna, t_1, t_2;

      cout << "Introduce la direccion de la imagen sin comillas: ";
      cin >> seleccion_imagen;
      cout << "Introduce el umbral 1: ";
      cin >> t_1;
      cout << "Introduce el umbral 2: ";
      cin >> t_2;

      // leemos la imagen
      img = LeerImagenPGM(seleccion_imagen.c_str(), fila, columna);

      Imagen imagen(fila, columna, img);

      // compara pixeles usando escala de grises
      imgfinal_eg = compararPixeles(imagen, fila, columna, t_1, t_2);


      //Sacas la imagen con el umbral hecho
      escribe_imagen = EscribirImagenPGM("./imagenespgmppm/umbralizada.pgm", imgfinal_eg, fila, columna);

      if(!escribe_imagen){
        cout << "Ha fallado al escribir la imagen" << endl;
      }else{
        cout << "La umbralizacion se ha completado" << endl;
      }

      }break;

    case 2:{
      string seleccion_imagen;
      unsigned char *imagen_icono, *icono;
      bool escribe_icono;
      int filaicono, columnaicono, filas, columnas;

      cout << "Introduce la direccion de la imagen sin comillas: ";
      cin >> seleccion_imagen;
      cout << "Introduce el numero de filas del icono: ";
      cin >> filaicono;
      cout << "Introduce el numero de columnas del icono: ";
      cin >> columnaicono;

      // Leemos la imagen que nos han pasado por parámetro
      imagen_icono = LeerImagenPGM(seleccion_imagen.c_str(),filas, columnas);

      // Creo la imagen para hacer el icono
      Imagen img_icono(filas, columnas,imagen_icono);

      // Creación del icono
      icono = creaIcono(img_icono, filaicono, columnaicono);

      // Escribimos la imagen iconizada
      escribe_icono = EscribirImagenPGM("./imagenespgmppm/icono.pgm", icono, filaicono, columnaicono);

    }break;

    case 3:{
      }break;

    default:
      cout << "No has introducido un numero valido";

  }
}
