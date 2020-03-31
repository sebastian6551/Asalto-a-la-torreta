#ifndef _HEADER_H
#define _HEADER_H
#include <iostream>
using namespace std;

class Header
{
  public:
  Header();
  ~Header();

  void settings();
  void settingsNoTitle();
  void leerArchivo(string rutaArchivo);
  void elegirOpcion(int x);
};

#endif