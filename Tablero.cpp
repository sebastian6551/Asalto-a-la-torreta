#include "Tablero.h"
#include <fstream>
using namespace std;

Tablero::Tablero(){
}

Tablero::~Tablero(){
}

//Métodos de la clase Tablero...

/*Otiene el elemento que este en la coordenada [x][y] del tablero de juego. 
Sirve para conocer la ubicación de los jugadores y la torreta.*/
int Tablero::obtenerElemento(int x, int y)
{
  return tablero[x][y];
}

/*Modifica el valor del elemento que este en la coordenada [x][y] del tablero de juego.*/
void Tablero::modificarElemento(int x, int y, int valor) 
{
  tablero[x][y] = valor;
}
