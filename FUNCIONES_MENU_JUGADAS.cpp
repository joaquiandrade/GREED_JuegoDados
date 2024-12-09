#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include <fstream>
# include <string>
#include "FUNCIONES_MENU_JUGADAS.h"
#include "juego.h"
using namespace std;



/// FUNCION TIRAR DADOS

int tirar_dados ( ) {

    return rand()  %6 +1 ;
}

/// FUNCION PEDIR NOMBRES
string pedir_nombre() {
string nombre;

cout<<"DIGITE SU NOMBRE: ";
cin>>nombre;
return nombre;
}

/// MOSTRAR ESTADISTICAS
void mostrar_estadisticas ( string &nombre_mejor_jugador, int &puntaje_maximo )
 {


if (puntaje_maximo==0 )
    {
        rlutil::locate(10,15);
        rlutil::setColor(10);
    cout<<"NO SE HAN JUGADO PARTIDAS POR EL MOMENTO"<<endl;
}
else {
        rlutil::locate(15,10);
        rlutil::setColor(10);
        cout<<"======= ESTADISTICAS ======= "<<endl;
         rlutil::locate(15,11);
        rlutil::setColor(10);
        cout<<"==== JUGADOR CON PUNTAJE MAS ALTO ===== "<<endl;
         rlutil::locate(15,12);
        rlutil::setColor(10);
        cout<<"Nombre: "<<nombre_mejor_jugador<<" ||| Puntaje: "<<puntaje_maximo<<endl;
}
}


//// MENU GREED CON RLUTIL
        void Limpiar_menu()
         {
    for (int i = 10; i <= 15; i++) {
        rlutil::locate(38, i);
        cout << " "; // Borra el cursor
        rlutil::locate(39, i);
        cout << "           "; // Borra el texto del menú
    }
}

///// DIBUJAR MENU
//Funcion para Dibujar el menu
 void Dibujar_menu (int y)
 {
rlutil::cls();
        rlutil::setColor(10);
        rlutil::locate(39,10);
        cout<<"MODO 1  JUGADOR"<<endl;

        rlutil::locate(39,11);
        cout<<"MODO 2  JUGADORES"<<endl;

        rlutil::locate(39,12);
        cout<<"ESTADISTICAS"<<endl;

        rlutil::locate(39,13);
        cout<<"CREDITOS"<<endl;

        rlutil::locate(39,14);
        cout<<"SALIR"<<endl;
         rlutil::locate(37,10 + y); //para mostrar el cursor
        cout<<char(175)<<endl;

        }

/////////////////////// PARA DIBUJAR EL TITULO
//Funcion para dibujar el titulo principal
void Dibujar_titulo ()
{
        int xcolumna;
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(1,2);
    cout<<char(201);
    rlutil::locate(1,3);
    cout<<char(186);
    rlutil::locate(1,4);
    cout<<char(200);

    for(xcolumna=2;xcolumna<=100;xcolumna++)
    {
        rlutil::locate(xcolumna,2);
        cout<<char(205);
        rlutil::locate(xcolumna,4);
        cout<<char(205);
        rlutil::msleep(15); /// con este modificamos la velocidad del trazado del borde

    }

    rlutil::locate(100,2);
    cout<<char(187);
    rlutil::locate(100,3);
    cout<<char(186);
    rlutil::locate(100,4);
    cout<<char(188);

    char vtitulo[]="* * * G R E E D  *  * ";
    int vlongitud;
    vlongitud = strlen(vtitulo);
    int vcentro=(((100-vlongitud)/2)+1);


    for(xcolumna=2;xcolumna<=vcentro;xcolumna++)
    {
        rlutil::setColor(rand()%16);
        rlutil::locate(xcolumna,3);
        if(xcolumna-1!=1)
        {
            rlutil::locate(xcolumna-1,3);
            cout<<" ";
        }
        cout<<(vtitulo);
        rlutil::msleep(10); // velocidad con la que desplazo el texto

    }

    rlutil::locate(12,12);
    rlutil::msleep(1000); // la pausa final
}

 // CREDITOS
void creditos ()
{
      rlutil::locate(30,13);///UBICO EN PANTALLA
      rlutil::setColor(14);
      cout <<" Carla Joaquina Andrade LEG: 29676"<<endl;
      rlutil::locate(30,14);///UBICO EN PANTALLA
      cout <<" Emmanuel Sansberro LEG: 31704 "<<endl;
      rlutil::locate(30,15);///UBICO EN PANTALLA
      cout <<" Gustavo Ruiz LEG: 26112 "<<endl;
      rlutil::locate(30,16);///UBICO EN PANTALLA
      cout <<" Lucas Flores LEG: 31626 "<<endl;
      rlutil::locate(30,19);///UBICO EN PANTALLA
      system("pause") ;

      agradecimiento () ;


}

