#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <sstream> // string stream
#include <time.h> 
using namespace std;

class Tablero 
{
  public:
 
  static const int SIZE = 10;
  
  Tablero();
  ~Tablero();

  void configurarTablero(string rutaArchivo);
  void imprimirTablero();
  int obtenerElemento(int x, int y);
  void modificarElemento(int x, int y, int valor);

  private:
  int tablero[SIZE][SIZE];
};
#endif 
