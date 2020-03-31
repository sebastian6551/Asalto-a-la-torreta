#ifndef _AVATAR_H_
#define _AVATAR_H_
#include <iostream>
using namespace std;

class Avatar 
{
public:
Avatar();
~Avatar();

string opcionesAvatar();
void definirClase(int x); 
void luchador();
void tirador();
void mago();
string getid();

private:
string id;
float vida;
float poder; 
float mana;
};
#endif 