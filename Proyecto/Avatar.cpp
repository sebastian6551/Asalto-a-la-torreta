#include "Avatar.h"
#include <iostream>
using namespace std;

Avatar::Avatar()
{

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
  id = 2;
  vida = 3;
  poder = 1; 
  mana = 0.3; 
}

//metodo para definir el objeto con los atributos de un Mago
void Avatar::mago()
{
  id = 3;
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
    cout
    <<"Has seleccionado luchador.";
    luchador();
    break;
    case 2:
    cout
    <<"Has seleccionado tirador.";
    tirador();
    break;
    case 3:
    cout
    <<"Has seleccionado mago.";
    mago();
    break;
    default:
    cout
    <<"Intente de nuevo:"<<endl
    <<opcionesAvatar();
  }
}