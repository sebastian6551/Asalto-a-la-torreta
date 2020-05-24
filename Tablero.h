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
#include "Avatar.h"
using namespace std;

class Tablero 
{
  public:
 
  static const int SIZE = 10;
  
  Tablero();
  ~Tablero();

  //
  int torre;
  bool muroNorte;
  bool muroSur;
  bool muroOeste;
  bool muroEste;

  static const int SIZE1 = 12;

  vector <Avatar*> Ejercito1;
  vector <Avatar*> Ejercito2;

  void movimiento(int w,int z);
  void moverse();
  void pasos(int o,int i,int e);

  void asedio(int x, int y);

  void reclutar();
  void estado();

  float poderEjercito(vector <Avatar*> Ejercito);
  float manaEjercito(vector <Avatar*> Ejercito);
  void derrota(vector <Avatar*> Ejercito,int y);
  //

  void configurarTablero(string rutaArchivo);
  void imprimirTablero();
  int obtenerElemento(int x, int y);
  void modificarElemento(int x, int y, int valor);
  void guardar();
  
  private:
  int tablero[SIZE][SIZE1];
};
#endif