#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "FUNCIONES_MENU_JUGADAS.h"
#include "juego.h"
using namespace std;

int main()
{
    int op=1,y=0; /// ESTO ES PARA QUE FUNCIONE EL MENU CON RLUTIL USA LAS FLECHAS
string nombre_mejor_jugador=""; // ESTADISTICAS
int puntaje_maximo=0;
    srand (time (0));
    //Dibujar_titulo();

     rlutil::hidecursor();
     system ("cls");
      do {
            cout<<"EL VALOR DE Y ES: "<<y<<endl;
            Dibujar_menu(y);
              int key=rlutil::getkey(); // con esto nos vamos a guardar la tecla que toca. si quiever que tecla es hagan un cout pero el 1 es enter y 15 y 14 son las flechitas.

               switch (key) {

               case 14: //significa que esta tocando flecha para arriba
                Limpiar_menu(); // para dar la sensacion de que esta bajando y subiendo
                y=y-1;

                if (y<0) {
                    y=0;

                }
                break;
               case 15: // significa que mueve hacia abajo
                Limpiar_menu();
                y=y+1;
                if (y>4) {
                    y=4; // lo dejamos que no pase de aca
                }
                break;

               case 1: // ya analizamos donde esta el cursor ahora ponemos que hacer en caso 1 que es el enter y nos damos cuenta donde esta por el valor de y

                if(y==0) { //quiere decir que esta en la primera opcion que es la de modo 1 jugador porque no movio el valor de y

                    system ("cls");

                    rlutil::setColor(10) ;
                     modo_unjugador(nombre_mejor_jugador, puntaje_maximo);
                    //cout<<"HOLA ESTOY EN MODO UN JUGADOR"<<endl;

                    rlutil::anykey();
                }
                else if (y==1) {//quiere decir que esta en el de abajo o sea en 2 jugadores
                    system("cls");
                    rlutil::setColor(11);
                    modo_dosjugadores(nombre_mejor_jugador, puntaje_maximo )  ;
                    //cout <<"estoy en modo dos jugadores"<<endl;
                    rlutil::anykey();
                }

                else if (y==2)
                    { // ya esta en estadisticas
                        system("cls");
                        rlutil::setColor(10);
                        mostrar_estadisticas(nombre_mejor_jugador, puntaje_maximo ) ;
                        rlutil::anykey();
               }
               else if (y==3)
                { // ya esta en salir
                    system("cls");
                    rlutil::setColor(13);
                    creditos();
                    rlutil::anykey();
               }
              else if (y==4)
                { // ya esta en creditos
                    system("cls");
                    rlutil::setColor(13);
                    cout<<"SALE DEL MENU"<<endl;
                    op=0; //para que salga
                          rlutil::anykey();
                          break;
               }

             }

                  } while (op!=0);



                 system ("pause");
                 return 0;
}
