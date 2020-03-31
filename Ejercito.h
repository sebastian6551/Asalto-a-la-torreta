#ifndef _EJERCITO_H_
#define _EJERCITO_H_
#include <iostream>
#include <vector>
#include "Avatar.h"
using namespace std;

class Ejercito
{
public:
Ejercito();
~Ejercito();  
vector<Avatar> composicion;
void añadirLuc();
void estado();
};
#endif 