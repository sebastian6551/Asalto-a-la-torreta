#include "Torreta.h"
#include <fstream>
using namespace std;

Torreta::Torreta()
{
  int vidaTorreta = 4;
}

Torreta::~Torreta()
{
}

void Torreta::golpeALaTorreta()
{
  vidaTorreta = vidaTorreta-1;
}

int Torreta::estadoDeLaTorreta()
{
  return vidaTorreta;
}
