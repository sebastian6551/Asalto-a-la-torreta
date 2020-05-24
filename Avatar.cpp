#include "Avatar.h"
#include <iostream>
using namespace std;

Avatar::Avatar(int x)
{
definirClase(x);
}

Avatar::~Avatar()
{

}


//metodo para definir el objeto con los atributos de un luchador 
void Avatar::luchador()
{
  id = 1;
  vida = 4;
  poder = 0.7; 
  mana = 0.6; 
}

//metodo para definir el objeto con los atributos de un Tirador
void Avatar::tirador()
{
  id = 3;
  vida = 3;
  poder = 1; 
  mana = 0.3; 
}

//metodo para definir el objeto con los atributos de un Mago
void Avatar::mago()
{
  id = 2;
  vida = 5;
  poder = 0.2; 
  mana = 1; 
}

//Metodo que dependiendo del valor de x definira el objeto con algunos de los tipos de avatar
void Avatar::definirClase(int x)
{
  switch (x)
  {
    case 1:
    luchador();
    break;
    case 2:
    tirador();
    break;
    case 3:
    mago();
    break;
    
  }
}


void Avatar::vacio()
{
  id = 0;
  vida = 0;
  poder = 0; 
  mana = 0; 
}

int Avatar::getid()
{
  return id;
}

float Avatar::getpoder()
{
  return poder;
}

float Avatar::getmana()
{
  return mana;
}

float Avatar::getvida()
{
  return vida;
}


void Avatar::daño(int y)
{
  switch (y)
  {
    case 1:
      {
      vida=(vida-0.5);
      }
    break;
    case 2:
      {
       vida=(vida-0.2);
      }
    break;
    }
}    