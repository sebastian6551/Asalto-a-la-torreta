#include "Tablero.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <string>

Tablero::Tablero()
{
  torre=4;
  muroNorte=true;
  muroSur=true;
  muroOeste=true;
  muroEste=true;
}

Tablero::~Tablero()
{
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
  while(y < 12)
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

//Guarda el campo de una partida anterior
void Tablero::guardar()
{
  remove ("PruebaCargarPartida.txt");
  ofstream salida("PruebaCargarPartida.txt");
  int y = 0;
  while(y < 12)
    {
      for(int x = 0; x < 10; x++)
        {
          salida<<tablero[x][y]<<" ";
        }
        salida<<endl;
      y++;
    }
}

//Se encarga de repartir los turnos y dejar mover a los ejercitos mientras la torre esta entera.
void Tablero::moverse()
{ 
  int i=0;
  while(torre>0)
    {
      if(i%2==0)
        {
          cout<<"Mover Ejército 1:";
          movimiento(1,1);
          imprimirTablero();
          movimiento(8,2);
        }
      i++;  
    }
  cout<<"Se cayó la torre."<<endl;
}

//Busca las coordenadas de un entero en la matriz y lo usa en otro método.
void Tablero::movimiento(int w,int z)
{
  int x1;
  int y1;
  int y=0;
  string direccion;
  while (y < 10)
    {
      for(int x = 0; x < 10; x++)
        {
          if ((obtenerElemento(x,y)) == w)
            {
              x1=x;
              y1=y;
            }
    }
      y++;
    }

  if(z==1)
    {
      pasos(x1,y1,w);
    }
  else if (z==2)
    {
      asedio(x1,y1);
    }
}

//Método que recibe la ubicación y un elemento para moverlo en la matriz tablero .
void Tablero::pasos(int o,int i,int e)
{ 
  string direccion;
  cout<<" ingresar dirección w, a, s, d"<<endl;
  cin>>direccion;

  if((direccion=="w") && (i>0) && (obtenerElemento(o,(i-1)) == 0))//la casilla está vacia?
    {
      modificarElemento(o,i,0);
      modificarElemento(o,(i-1),e); 
    }
  else if ((direccion=="s") && (i<9) && (obtenerElemento(o,(i+1)) == 0))
    {
      modificarElemento(o,i,0);
      modificarElemento(o,(i+1),e); 
    } 
  else if ((direccion=="d") && (o<9) && (obtenerElemento((o+1),i) == 0))
    {
      modificarElemento(o,i,0);
      modificarElemento((o+1),i,e); 
    }
  else if ((direccion=="a") && (o>0) && (obtenerElemento((o-1),i) == 0))
    {
      modificarElemento(o,i,0);
      modificarElemento((o-1),i,e); 
    }
  else 
    {
      pasos(o,i,e);
    }
}

//Recibe las coordenadas de la torre (8) y revisa si el ejército atacante está atacando una de sus murallas.
void Tablero::asedio(int x, int y)
{
 if ((obtenerElemento((x+1),y) == 1) && (muroEste == true))
  { 
    cout<<"muro este destruido"<<endl;
    muroEste = false;
    torre = torre-1;
  }
 if ((obtenerElemento((x-1),y) == 1) && (muroOeste == true))
  { 
    cout<<"muro oeste destruido"<<endl;
    muroOeste = false;
    torre = torre-1;
  }
 if ((obtenerElemento(x,(y+1)) == 1) && (muroSur == true))
  { 
   cout<<"muro sur destruido"<<endl;
   muroSur = false;
   torre = torre-1;
  }
 if((obtenerElemento(x,(y-1)) == 1) && ( muroNorte == true))
  { 
   cout<<"muro norte destruido"<<endl;
   muroNorte = false;
   torre = torre-1;
  }
}

//Método que se encarga de construir los ejércitos con base en los datos en el archivo de inicio.
void Tablero::reclutar()
{
 int i=0;    
 while(obtenerElemento(i,10)!=0)
 {
 Ejercito1.push_back(new Avatar(obtenerElemento(i,10)));
 i++;
 }

 i=0;
 while(obtenerElemento(i,11)!=0)
 {
 Ejercito2.push_back(new Avatar(obtenerElemento(i,11)));
 i++;
 }
}

//Método para verificar las unidades de cada ejécito.
void Tablero::estado()
{
 for (auto i = Ejercito1.begin(); i != Ejercito1.end(); ++i) 
  {
  cout<<(*i)->getid(); 
  } 

  cout<<endl;

for (auto i = Ejercito2.begin(); i != Ejercito2.end(); ++i) 
  {
  cout<<(*i)->getid(); 
  } 

  cout<<endl;
}

//Método para sacar el total de "poder" del ejercito ingresado.
float Tablero::poderEjercito(vector <Avatar*> Ejercito)
{
  float Power;
  for (auto i = Ejercito1.begin(); i != Ejercito1.end(); ++i)
  {
   Power=((*i)->getpoder()) + Power;
  }
  return Power;
}

//Método para sacar el total de "maná" del ejercito ingresado.
float Tablero::manaEjercito(vector <Avatar*> Ejercito)
{
  float magic;
  for (auto i = Ejercito1.begin(); i != Ejercito1.end(); ++i)
  {
   magic=((*i)->getmana()) + magic;
  }
  return magic;
}

//Método que se encarga de aplicar el daño sufrido al miembro mas débil del ejército y sacarlo en caso de que este muerto.
void Tablero::derrota(vector <Avatar*> Ejercito,int y)
{
  auto loser = Ejercito.begin();
  for (auto i = Ejercito1.begin(); i != Ejercito1.end(); ++i)
  {
    if ((*loser)->getvida()>(*i)->getvida())
    {
      loser=i;
    }
  }

  (*loser)->daño(y);

  if ((*loser)->getvida()<=0)
  {
    Ejercito.erase(loser);
  }
}