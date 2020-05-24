#include "Header.h"
#include "Avatar.h"
#include "Tablero.h"
#include "Torreta.h"
#include "Ejercito.h"
using namespace std;

Header::Header()
{
}
Header::~Header()
{

}
/*Creo objetos de las clases Tablero y Avatar para usar métodos de esas clases en el menú.*/
Avatar menuAvatar(1);
Tablero tabla; 
Ejercito armada;

  
void Header::settings()
{
//aquí se van añadiendo las opciones del menú
    cout 
    <<endl<<"¡Bienvenido a Code Legends!"<<endl
    << "Por favor escoja una opción:"<<endl
    << "1. Nueva partida." <<endl
    << "2. Cargar partida." <<endl
    << "3. Elegir avatar." <<endl
    << "4. Mostrar estado del ejército."<<endl
    << "5. Salir."<<endl
    << "6. Instrucciones"<<endl;
    int x; 
    cin >>x;
    if (x== 7 || x == 8)
      { 
        cout
        <<"Intente de nuevo:"<<endl;
        settings();
      }
    else 
      {
        elegirOpcion(x);
      }
}

void Header::settingsNoTitle()
{
    cout 
    <<endl<<"Aplicado exitosamente:"<<endl
    << "Por favor escoja una opción:"<<endl
    << "1. Nueva partida." <<endl
    << "2. Cargar partida." <<endl
    << "3. Elegir avatar." <<endl
    << "4. Mostrar estado del ejército."<<endl
    << "5. Salir."<<endl
    << "6. Instrucciones."<<endl
    << "7. Jugar."<<endl
    << "8. Guardar partida."<<endl;
    int x; 
    cin >>x;
    if (x==7)
    {
      x = 1;
    }
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

string Header::instrucciones()
{
  cout
  <<"Un ejército se moverá por todo el campo de juego para evadir o enfrentar una batalla;"<<endl
  <<"cuando no pueda evadir la batalla, deberá enfrentarla haciendo uso de su ataque (poder) y defensa (maná)."<<endl 
  <<"Cuando el ejército de ataque llegue a la Torreta, deberá destruirla golpeando cada uno de sus lados, así ganara el juego."<<endl<<endl
  <<"El ejército se mueve con las letras:"<<endl<<endl
  <<"                  | w = Arriba |"<<endl
  <<"| a = Izquierda  ||  s = Abajo || d = Derecha |"<<endl<<endl;

  cout
  <<"¿Volver al menú?"<<endl
  <<"1. Sí"<<endl
  <<"2. No"<<endl;
  int x;
  cin>>x;
    {
     if (x == 1)
      {
        settingsNoTitle();
      }
     else if (x == 2)
      {
        cout<<" ";
      }
    }
    return "";
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
      tabla.reclutar();
      tabla.estado();
      tabla.moverse();
      cout
      <<"¿Volver al menú?"<<endl
      <<"1. Sí"<<endl
      <<"2. No"<<endl;
      int x;
      cin>>x;
      {
      if (x == 1)
        {
          settingsNoTitle();
        }
      else if (x == 2)
        {
          cout<<" ";
        }
      }
      }
    break;
    case 2:
      {
        tabla.configurarTablero("PruebaCargarPartida.txt");
        cout<<endl;
        tabla.imprimirTablero();
        cout
        <<"¿Volver al menú?"<<endl
        <<"1. Sí"<<endl
        <<"2. No"<<endl;
        int x;
        cin>>x;
        {
        if (x == 1)
          {
            settingsNoTitle();
          }
        else if (x == 2)
          {
            cout<<" ";
          }
        }
      }
    break;
    case 3:
      {
        cout
        <<menuAvatar.opcionesAvatar()<<endl;
        armada.composicion.push_back(menuAvatar);
        settingsNoTitle();
      }
    break;
    case 4:
      {
        cout
        <<"El estado del ejército es:"<<endl;
        armada.estado();
        settingsNoTitle();
      }
    break;
    case 5:
      {
        cout<<"Gracias por jugar";
      }
    break;
    case 6:
      {
        instrucciones();
      }
    break;
    case 7:
      {
    cout<<"";
      }
    break;
    case 8:
      {
        tabla.guardar();
      }
    break;
    default:
      cout
      <<"Intente de nuevo:";
      settings();
  }
}


