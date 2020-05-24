#ifndef _AVATAR_H_
#define _AVATAR_H_
#include <iostream>
using namespace std;

class Avatar 
{
public:
Avatar(int x);
~Avatar();

string opcionesAvatar();
void definirClase(int x); 
void luchador();
void tirador();
void mago();
void vacio();
int getid();

//
float getpoder();
float getmana();
float getvida();
void daño(int y);
//

private:
int id;
float vida;
float poder; 
float mana;
};
#endif