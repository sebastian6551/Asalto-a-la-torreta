#include "Tablero.h"
#include <fstream>
#include <iostream>
using namespace std;

Tablero::Tablero(){
}

Tablero::~Tablero(){
}

/*Este método guarda el valor de cada posición de la tabla 
que está en un archivo .txt en tablero*/
void Tablero::configurarTablero(std::string rutaArchivo)
{
  ifstream abrir(rutaArchivo.c_str());
  string datos;

  int numero;
  int espaciosVerticales = 0;
  int y = 0;
  while(espaciosVerticales < 10)
    {
          for(int x = 0; x < 10; x++)
          {
          abrir>>datos;
          stringstream recibe(datos);
          recibe>>numero;
          tablero[x][y] = numero;
          }
          y++;
          espaciosVerticales++;
    }
}

/*
Muestra el tablero.
*/
void Tablero::imprimirTablero()
{
  int espaciosVerticales = 0;
  int y = 0;
  while(espaciosVerticales < 10)
    {
          for(int x = 0; x < 10; x++)
          {
          cout<<tablero[x][y]<<" ";
          }
          cout<<endl;
          y++;
          espaciosVerticales++;
    }
}

/*Otiene el elemento que este en la coordenada [x][y] del tablero de juego. 
Sirve para conocer la ubicación de los jugadores y la torreta.*/
int Tablero::obtenerElemento(int x, int y)
{
  return tablero[x-1][y-1];
}

/*Modifica el valor del elemento que este en la coordenada [x][y] del tablero de juego.*/
void Tablero::modificarElemento(int x, int y, int valor) 
{
  tablero[x-1][y-1] = valor;
}
