#include "Avatar.h"
#include <iostream>

Avatar::Avatar()
{

}

Avatar::~Avatar()
{

}

//metodo para definir el objeto con los atributos de un luchador 
void Avatar::Luchador()
{
id='1';
vida=4;
poder=0.7; 
mana=0.6; 
}

//metodo para definir el objeto con los atributos de un Tirador
void Avatar::Tirador()
{
id='2';
vida=3;
poder=1; 
mana=0.3; 
}

//metodo para definir el objeto con los atributos de un Mago
void Avatar::Mago()
{
id='3';
vida=5;
poder=0.2; 
mana=1; 
}

//Metodo que dependiendo del valor de x definira el objeto con algunos de los tipos de avatar
void Avatar::Definirclase(int x)
{
if (x==1)//Luchador
{
 Avatar::Luchador();
}else if (x==2)//Tirador
 {
  Avatar::Tirador();
 }else if (x==3)//Mago
  {
   Avatar::Mago();
  } 
}
