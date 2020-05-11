#ifndef _HEADER_H
#define _HEADER_H
#include <iostream>
using namespace std;

class Header
{
  public:
  Header();
  ~Header();

  //
  //Ejercito EjercitoAtacante;
  //Ejercito EjercitoDefensor;
  //

  void settings();
  void settingsNoTitle();
  void leerArchivo(string rutaArchivo);
  void elegirOpcion(int x);
};

#endif