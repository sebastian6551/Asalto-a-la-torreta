#ifndef _TORRETA_H_
#define _TORRETA_H_
#include <iostream>

using namespace std;

class Torreta
{
  public:
  
  Torreta();
  ~Torreta();

  void golpeALaTorreta();
  int estadoDeLaTorreta();

  private:
  int vidaTorreta;
};
#endif 
