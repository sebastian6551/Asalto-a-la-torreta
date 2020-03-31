/*


*/
//Librerias
#include <iostream>
#include <fstream>
using namespace std;
//Clases
#include "Avatar.h"
#include "Header.h"
#include "Tablero.h"
#include "Torreta.h"
#include "Ejercito.h"


int main()
{

/*
Se llama el menú de configuración que se encuetra en la clase Header.
*/

/*Header titulo;
titulo.settings();*/

Avatar Avatar1,Avatar2,Avatar3;
  Avatar1.definirClase(1);
  Avatar2.definirClase(2);
  Avatar3.definirClase(3);

  Ejercito armada;
  armada.composicion.push_back(Avatar1);
  armada.composicion.push_back(Avatar2);
  armada.composicion.push_back(Avatar3);

  armada.estado();

}
