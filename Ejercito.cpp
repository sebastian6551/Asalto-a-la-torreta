#include <iostream>
#include "Ejercito.h"
#include "Avatar.h"

Ejercito::Ejercito()
{

}

Ejercito::~Ejercito()
{

}

/*void Ejercito::añadirLuc()
{ 
  Avatar *Luc;
  Luc = new Avatar;
  Luc->definirClase(1);
  composicion.push_back(Luc);
}*/

void Ejercito::estado()
{
cout<<"La cantidad de avatares es: "<< composicion.size()<<endl;
cout<<"Compuesto por:"<<endl;
string aux;
int j;
for (int i=0;i<composicion.size();i++)
{
aux=composicion[i].getid();
cout<<aux<<endl;
}

}