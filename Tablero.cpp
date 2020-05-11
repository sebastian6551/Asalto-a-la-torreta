#include "Tablero.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <string>

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
  return tablero[x][y];
}

/*Modifica el valor del elemento que este en la coordenada [x][y] del tablero de juego.*/
void Tablero::modificarElemento(int x, int y, int valor) 
{
  tablero[x][y] = valor;
}

//Guarda el campo de una partida anterior
void Tablero::guardar()
{
  remove ("PruebaCargarPartida.txt");
  ofstream salida("PruebaCargarPartida.txt");
  int y = 0;
  while(y < 10)
    {
      for(int x = 0; x < 10; x++)
        {
          salida<<tablero[x][y]<<" ";
        }
        salida<<endl;
      y++;
    }
}

void Tablero::moverse()
{
  for(int i=0;i<5;i++)
  {
  if(i%2==0)
  {cout<<"mover Ejercito 1:";
   movimiento(1);
   imprimirTablero();} 
   if(i%2==1)
  {cout<<"mover Ejercito 2:";
   movimiento(2);
   imprimirTablero();}  
  }
}

void Tablero::movimiento(int w)
{
int x1;
int y1;
int y=0;
string direccion;
while(y < 10)
{
 for(int x = 0; x < 10; x++)
  {
   if((obtenerElemento(x,y))==w)
    {
     x1=x;
     y1=y;
    }
  }
  y++;
 }
 pasos(x1,y1,w);
}

void Tablero::pasos(int o,int i,int e)
{ string direccion;
cout<<" ingresar direccion en minusculas"<<endl;
     cin>>direccion;
     if((direccion=="arriba")&&(i>0))//la casilla esta vacia?
     {
      modificarElemento(o,i,0);
      modificarElemento(o,(i-1),e); 
     }else
     if
     ((direccion=="abajo")&&(i<9))
     {
      modificarElemento(o,i,0);
      modificarElemento(o,(i+1),e); 
     }else
     if
     ((direccion=="derecha")&&(o<9))
     {
      modificarElemento(o,i,0);
      modificarElemento((o+1),i,e); 
     }else
     if
     ((direccion=="izquierda")&&(o>0))
     {
      modificarElemento(o,i,0);
      modificarElemento((o-1),i,e); 
     }else {pasos(o,i,e);}
}

