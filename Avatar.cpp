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

string Avatar::opcionesAvatar()
{
  cout
  <<"Escoja un avatar de los siguientes:"<<endl
  <<"1. Luchador."<<endl
  <<"2. Tirador."<<endl
  <<"3. Mago."<<endl;
  int x;
  cin >>x;
  definirClase(x);
  return "";
}

//Método para definir el objeto con los atributos de un luchador.
void Avatar::luchador()
{
  id = 1;
  vida = 4;
  poder = 0.7; 
  mana = 0.6; 
}

//Método para definir el objeto con los atributos de un Tirador.
void Avatar::tirador()
{
  id = 3;
  vida = 3;
  poder = 1; 
  mana = 0.3; 
}

//Método para definir el objeto con los atributos de un Mago.
void Avatar::mago()
{
  id = 2;
  vida = 5;
  poder = 0.2; 
  mana = 1; 
}

//Método que dependiendo del valor de x definira el objeto con algunos de los tipos de avatar.
void Avatar::definirClase(int x)
{
  switch (x)
  {
    case 1:
    cout
    <<"Has seleccionado luchador."<<endl;
    luchador();
    break;
    case 2:
    cout
    <<"Has seleccionado tirador."<<endl;
    tirador();
    break;
    case 3:
    cout
    <<"Has seleccionado mago."<<endl;
    mago();
    break;
    default:
    cout
    <<"Intente de nuevo:"<<endl
    <<opcionesAvatar();
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