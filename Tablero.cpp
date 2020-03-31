#include "Tablero.h"
#include <fstream>
#include <iostream>
using namespace std;

Tablero::Tablero(){
}

Tablero::~Tablero(){
}

/*Este método guarda el valor de cada posición de la tabla 
que está en un archivo .txt en tablero.
Primero guarda horizontalmente por lo que x va aumentando hasta llegar a 10
y luego lo hace verticalmente hasta que llega a 10 al ser el tablero 10x10.
*/
void Tablero::configurarTablero(std::string rutaArchivo)
{
  ifstream abrir(rutaArchivo.c_str());
  string datos;

  int numero;
  int y = 0;
  while(y < 10)
    {
      for(int x = 0; x < 10; x++)
        {
          abrir>>datos;
          stringstream recibe(datos);
          recibe>>numero;
          tablero[x][y] = numero;
        }
      y++;
    }
}

/*
Muestra el tablero recorriendo todas las posiciones en tablero[x][y]
primero lo hace horizontalmente y salta una linea al llegar a 10 y
así sucesivamente hasta que haya completado 10 saltos de línea que
equivale a las posiciones verticalmente. 
*/
void Tablero::imprimirTablero()
{
  int y = 0;
  while(y < 10)
    {
      for(int x = 0; x < 10; x++)
        {
          cout<<tablero[x][y]<<" ";
        }
        cout<<endl;
      y++;
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

void Tablero::guardar()
{
remove ("PruebaCargarPartida");

ofstream salida("PruebaCargarPartida");

int i=0;
int j=0;

  while(j<10)
  {i=0;
  while(i<10)
  { salida<< tablero[i][j]<<" ";
  i++;}
  salida<<endl;
  j++;
  }
}
 