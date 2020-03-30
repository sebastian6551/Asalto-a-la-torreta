#include "Header.h"
#include "Avatar.h"
#include "Tablero.h"
#include "Torreta.h"
using namespace std;

Header::Header()
{
}
Header::~Header()
{

}
/*Creo objetos de las clases Tablero y Avatar para usar métodos de esas clases en el menú.*/
Avatar menuAvatar;
Tablero tabla; 

void Header::settings()
{
//aquí se van añadiendo las opciones del menú
    leerArchivo("Titulo.txt");
    cout 
    <<endl<<"¡Bienvenido a Code Legends!"<<endl
    << "Por favor escoja una opción:"<<endl
    << "1. Nueva partida." <<endl
    << "2. Cargar partida." <<endl
    << "3. Elegir avatar." <<endl
    << "4. Mostrar estado del ejército."<<endl;
    int x; 
    cin >>x;
    elegirOpcion(x);
}

//Lee el archivo Titulo.txt que es el que muestra el titulo.
void Header::leerArchivo(string rutaArchivo)
{
  char Mensaje[200];
  ifstream abrir(rutaArchivo.c_str());

  while (abrir.getline(Mensaje, 200))
    {
    cout<<Mensaje<<endl;
    }
}

/*Este método es llamado en settings() y permite realizar las 
opciones que muestra el menú.*/
void Header::elegirOpcion(int x)
{
  switch (x)
  {
    case 1:
      {
      tabla.configurarTablero("Tablero.txt");
      tabla.imprimirTablero();
      }
    break;
    case 2:
      {
        cout
        <<"Escriba el archivo .txt donde está la partida:"<<endl;
        string rutaArchivo;
        cin>>rutaArchivo;
        tabla.configurarTablero(rutaArchivo);
        cout<<endl;
        tabla.imprimirTablero();
      }
    break;
    case 3:
      cout
      <<menuAvatar.opcionesAvatar()<<endl;
    break;
    case 4:
      cout
      <<"El estado del ejército es:"<<endl;
      //Falta implementar la clase ejercito
    break;
    default:
      cout
      <<"Intente de nuevo";
      settings();
  }
}


