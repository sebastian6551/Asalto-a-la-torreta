#ifndef _AVATAR_H_
#define _AVATAR_H_

class Avatar 
{
public:
Avatar();
~Avatar();
void Definirclase(int x); 
void Luchador();
void Tirador();
void Mago();

private:
char id;
float vida;
float poder; 
float mana ;
};
#endif 
