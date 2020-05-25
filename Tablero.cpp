#include "Tablero.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <string>

Tablero::Tablero()
{
  Torre=4;
  MuroNorte=true;
  MuroSur=true;
  MuroOeste=true;
  MuroEste=true;
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

//Se encarga de repartir los turnos y dejar mover a los ejercitos mientras la torre esta entera
void Tablero::moverse()
{ int i=0;
  while(Torre>0)
  {
  if(i%2==0)
  {cout<<"mover Ejercito 1:";
   movimiento(1,1);
   imprimirTablero();
   movimiento(1,3);
   movimiento(8,2);}

  if(i%2==1)
  {cout<<"mover Ejercito 2:";
   movimiento(2,1);
   imprimirTablero();
   movimiento(1,4);
   movimiento(8,2);}
  
   i++;  
  }
  cout<<"se cayo la torre"<<endl;
}

//busca las coordenadas de un entero en la matriz y lo usa en otro metodo
void Tablero::movimiento(int w,int z)
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
 if(z==1)
 {
 pasos(x1,y1,w);
 }else if (z==2)
 {
   asedio(x1,y1);
 }else if (z==3)
 {
   conflicto(x1,y1,1);
 }else if (z==4)
 {
   conflicto(x1,y1,2);
 }
}

//metodo que recibe la ubicacion y un elemento para moverlo en la matriz tablero 
void Tablero::pasos(int o,int i,int e)
{ string direccion;
cout<<" ingresar direccion w,a,s,d"<<endl;
     cin>>direccion;
     if((direccion=="w")&&(i>0)&&(obtenerElemento(o,(i-1))==0))//la casilla esta vacia?
     {
      modificarElemento(o,i,0);
      modificarElemento(o,(i-1),e); 
     }else
     if
     ((direccion=="s")&&(i<9)&&(obtenerElemento(o,(i+1))==0))
     {
      modificarElemento(o,i,0);
      modificarElemento(o,(i+1),e); 
     }else
     if
     ((direccion=="d")&&(o<9)&&(obtenerElemento((o+1),i)==0))
     {
      modificarElemento(o,i,0);
      modificarElemento((o+1),i,e); 
     }else
     if
     ((direccion=="a")&&(o>0)&&(obtenerElemento((o-1),i)==0))
     {
      modificarElemento(o,i,0);
      modificarElemento((o-1),i,e); 
     }else {pasos(o,i,e);}
}

//recibe las coordenadas de la torre (8) y revisa si el ejercito atacante esta atacando una de sus murallas
void Tablero::asedio(int x, int y)
{
 if((obtenerElemento((x+1),y)==1) && (MuroEste==true))
 { 
  cout<<"muro este destruido"<<endl;
  MuroEste=false;
  Torre=Torre-1;
 }
 if((obtenerElemento((x-1),y)==1) && (MuroOeste==true))
 { 
  cout<<"muro oeste destruido"<<endl;
  MuroOeste=false;
  Torre=Torre-1;
 }
 if((obtenerElemento(x,(y+1))==1) && (MuroSur==true))
 { 
  cout<<"muro sur destruido"<<endl;
  MuroSur=false;
  Torre=Torre-1;
 }
 if((obtenerElemento(x,(y-1))==1) && (MuroNorte==true))
 { 
  cout<<"muro norte destruido"<<endl;
  MuroNorte=false;
  Torre=Torre-1;
 }
}

//metodo que se encarga de construir los ejercitos en base de los datos en el archivo de inicio
void Tablero::reclutar()
{
 int i=0;    
 while(obtenerElemento(i,10)!=0)
 {
 Ejercito1.push_back(new Avatar(obtenerElemento(i,10)));
 modificarElemento(i,10,0);
 i++;
 }

 i=0;
 while(obtenerElemento(i,11)!=0)
 {
 Ejercito2.push_back(new Avatar(obtenerElemento(i,11)));
 modificarElemento(i,11,0);
 i++;
 }
}

//metodo para verificar las unidades de cada ejercito 
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

//metodo para sacar el total de "poder" del ejercito ingresado
float Tablero::poderEjercito(vector <Avatar*> Ejercito)
{
  float Power;
  for (auto i = Ejercito.begin(); i != Ejercito.end(); ++i)
  {
   Power=((*i)->getpoder()) + Power;
  }
  return Power;
}

//metodo para sacar el total de "mana" del ejercito ingresado
float Tablero::manaEjercito(vector <Avatar*> Ejercito)
{
  float magic;
  for (auto i = Ejercito.begin(); i != Ejercito.end(); ++i)
  {
   magic=((*i)->getmana()) + magic;
  }
  return magic;
}

//metodo que se encarga de aplicar el daño sufrido al miembro mas debil del ejercito y sacarlo en caso de que este muerto
void Tablero::Derrota(vector <Avatar*> Ejercito,int y)
{ 
  int n=0;
  auto loser = Ejercito.begin();
  for (auto i = Ejercito.begin(); i != Ejercito.end(); ++i)
  {
    if ((*loser)->getvida()>(*i)->getvida())
    {
      loser=i;
      n++;
    }
  }
  
  //cout<<(*loser)->getvida()<<endl;

  (*loser)->daño(y);

  //cout<<(*loser)->getvida()<<endl;

  if ((*loser)->getvida()<=0)
  { 
    cout<<"Ha muerto un soldado"<<endl;
    Ejercito.erase(Ejercito.begin()+n);
  }
}

void Tablero::conflicto(int x,int y,int w)
{
if(obtenerElemento(x,(y-1))==2 ||
   obtenerElemento(x,(y+1))==2 ||
   obtenerElemento((x-1),y)==2 ||
   obtenerElemento((x+1),y)==2)
   {
    cout<<"BATALLA!!!"<<endl;

    switch (w)
  {
    case 1:

    cout<<"Ejercito 1 ataca"<<endl;

    if(poderEjercito(Ejercito1)>manaEjercito(Ejercito2))
    { 
      cout<<"Victoria!!"<<endl;
      Derrota(Ejercito2,1);
      cout<<"Un turno mas"<<endl;
      movimiento(1,1);
      imprimirTablero();
    }else
    if(poderEjercito(Ejercito1)<manaEjercito(Ejercito2))
    {
      cout<<"Derrota..."<<endl;
      Derrota(Ejercito1,1);
    }else
    { 
      cout<<"empate!?"<<endl;
      Derrota(Ejercito1,2);
      Derrota(Ejercito2,2);
    }
    break;

    case 2:

    cout<<"Ejercito 2 ataca"<<endl;
      
    if(poderEjercito(Ejercito2)>manaEjercito(Ejercito1))
    {
      cout<<"Victoria!!"<<endl;
      Derrota(Ejercito1,1);
      cout<<"Un turno mas"<<endl;
      movimiento(2,1);
      imprimirTablero();
    }else
    if(poderEjercito(Ejercito2)<manaEjercito(Ejercito1))
    { 
      cout<<"Derrota..."<<endl;
      Derrota(Ejercito2,1);
    }else
    { 
      cout<<"empate!?"<<endl;
      Derrota(Ejercito1,2);
      Derrota(Ejercito2,2);
    }
    break;
  }
 }    
}