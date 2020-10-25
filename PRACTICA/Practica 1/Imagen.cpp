 /**
  * @file Imagen.cpp
  * @brief Fichero con definiciones para la E/S de imágenes
  *
  * Permite la E/S de archivos de tipo PGM,PPM
  *
  */

#include <fstream>
#include <string>

#include <Imagen.h>

using namespace std;

Imagen::Imagen(){
    filas=0;
    cols=0;
    img=nullptr;
}
      
Imagen::Imagen(const Imagen &J){
    filas = J.filas;
    cols = J.cols;
    img = new byte *[filas];
    for(int i = 0; i < filas; i++){
        img[i] = new byte [cols];
    }
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
            img[i][j] = J.img[i][j];
        }
    }
}

// [???] operator =

Imagen::Imagen(int filas, int cols){
    this->filas = filas;
    this->cols = cols;
    img = new byte *[filas];
    for(int i = 0; i < filas; i++){
        img[i] = new byte [cols];
    }
}

Imagen::~Imagen(){
    for(int i = 0; i < filas; i++){
        delete [] img[i];
    }
    delete [] img;
    this->filas = 0;
    this->cols = 0;
    this->img = nullptr;
}

int Imagen::num_filas() const{
    return this->filas;
}

int Imagen::num_columnas() const{
    return this->cols;
}

void Imagen::asigna_pixel(int fila, int col, byte valor){
    if(fila >= 0 && fila < num_filas() && 
       col >= 0 && col < num_columnas() &&
       valor >= 0 && valor <= 255){
        img[fila][col] = valor;
    }
}

byte Imagen::valor_pixel (int fila, int col){
    byte valor;
    if(fila >= 0 && fila < num_filas() && 
       col >= 0 && col < num_columnas()){
        return img[fila][col];
    }
}

Imagen::TipoImagen Imagen::LeerTipo(ifstream& f){
  char c1,c2;
  Imagen::TipoImagen res= IMG_DESCONOCIDO;

  if (f){
    c1=f.get();
    c2=f.get();
    if (f && c1=='P')
      switch (c2) {
        case '5': res= IMG_PGM; break;
        case '6': res= IMG_PPM; break;
        default: res= IMG_DESCONOCIDO;
      }
  }
  return res;
}

// _____________________________________________________________________________

Imagen::TipoImagen Imagen::LeerTipoImagen(const char *nombre){
  ifstream f(nombre);
  return LeerTipo(f);
}


// _____________________________________________________________________________

char Imagen::SaltarSeparadores (ifstream& f){
  char c;
  do{
    c= f.get();
  } while (isspace(c));
  f.putback(c);
  return c;
}

// _____________________________________________________________________________

bool Imagen::LeerCabecera (ifstream& f, int& fils, int& cols){
    int maxvalor;
    string linea;
    while (SaltarSeparadores(f)=='#')
      getline(f,linea);
    f >> cols >> fils >> maxvalor;
    
    if (/*str &&*/ f && fils>0 && fils<5000 && cols>0 && cols<5000){
        f.get(); // Saltamos separador
        return true;
    }
    else 
      return false;
}



// _____________________________________________________________________________

unsigned char Imagen::*LeerImagenPPM (const char *nombre, int& fils, int& cols){
  unsigned char *res=0;
  fils=0;
  cols=0;
  ifstream f(nombre);
  
  if (LeerTipo(f)==IMG_PPM){
    if (LeerCabecera (f, fils, cols)){
        res= new unsigned char[fils*cols*3];
        f.read(reinterpret_cast<char *>(res),fils*cols*3);
        if (!f){
          delete[] res;
          res= 0;
        }
    }
  }
  return res;
}

// _____________________________________________________________________________

unsigned char Imagen::*LeerImagenPGM (const char *nombre, int& fils, int& cols){
  unsigned char *res=0;
  fils=0;
  cols=0;
  ifstream f(nombre);
  
  if (LeerTipo(f)==IMG_PGM){
    if (LeerCabecera (f, fils, cols)){
      res= new unsigned char[fils*cols];
      f.read(reinterpret_cast<char *>(res),fils*cols);
      if (!f){
        delete[] res;
        res= 0;
      }
    }
  }
  return res;
}

// _____________________________________________________________________________

bool Imagen::EscribirImagenPPM (const char *nombre, const unsigned char *datos, 
                        const int fils, const int cols){
  ofstream f(nombre);
  bool res= true;
  
  if (f){
    f << "P6" << endl;
    f << cols << ' ' << fils << endl;
    f << 255 << endl;
    f.write(reinterpret_cast<const char *>(datos),fils*cols*3);
    if (!f)
      res=false;
  }
  return res;
}
// _____________________________________________________________________________

bool Imagen::EscribirImagenPGM (const char *nombre, const unsigned char *datos, 
                        const int fils, const int cols){
  ofstream f(nombre);
  bool res= true;
  
  if (f){
    f << "P5" << endl;
    f << cols << ' ' << fils << endl;
    f << 255 << endl;
    f.write(reinterpret_cast<const char *>(datos),fils*cols);
    if (!f)
      res=false;
  }
  return res;
}


/* Fin Fichero: Imagen.cpp */
