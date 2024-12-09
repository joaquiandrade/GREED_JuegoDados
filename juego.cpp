#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include <fstream>
# include <string>
#include "FUNCIONES_MENU_JUGADAS.h"
#include "juego.h"
using namespace std;



/// CONTROLAR LA RONDA COMPLETA
void controlador_ronda (int &dados_para_jugar, int bloqueador_jugador1_1, int bloqueador_jugador1_2 , int &puntaje_ronda ) {
     int dados[5] = {0}; // Arreglo para los valores de los dados
    int contador_de_bloqueados = 0; // Dados bloqueados por los bloqueadores
    int sumar_tirada = 0; // Puntaje acumulado en la tirada actual
    bool seguir_jugando = true; // Indica si el jugador quiere seguir tirando
    int respuesta = 1; // Respuesta del jugador para seguir jugando
    int tirada_actual = 0; // Número de tiradas realizadas en la ronda

    while (dados_para_jugar > 0 && seguir_jugando) {


        contador_de_bloqueados = 0; // Reiniciamos el contador de bloqueados
        sumar_tirada = 0; // Puntaje acumulado en la tirada actual
        rlutil::locate(15,5);
        rlutil::setColor(10);
        cout << "TIRADA " << tirada_actual + 1 <<endl;
        rlutil::locate(15,6);
        cout << "BLOQUEADORES: " << bloqueador_jugador1_1<< " y " << bloqueador_jugador1_2  <<endl;
        rlutil::locate(25,8);
        cout << "VAS A TIRAR CON: " << dados_para_jugar << " DADOS"<<endl;

        // Lanzamos los dados
        for (int i = 0; i < dados_para_jugar; i++) {
            dados[i] = tirar_dados(); // Función para simular el lanzamiento del dado
            rlutil::locate(25,9+i);
            rlutil::setColor(10);
            cout << "DADO " << i + 1 << ": " << dados[i];

            if (dados[i] == bloqueador_jugador1_1 || dados[i] == bloqueador_jugador1_2 ) {
                    rlutil::setColor(12);
                cout << " BLOQUEADO :("<<endl;
                    rlutil::setColor(10);
                contador_de_bloqueados++;
            } else {
                cout << " VALIDO :)"<<endl;
                sumar_tirada += dados[i];
            }
        }

        /// Verificamos si todos los dados son iguales
        if  (soniguales (dados,dados_para_jugar,bloqueador_jugador1_1,bloqueador_jugador1_2)  ) {
               rlutil::locate(15,17);
            rlutil::setColor(14);
            cout<<"SON TODOS IGUALES! DUPLICAS!!!! "<<endl;
            sumar_tirada=sumar_tirada*2;
}
             else {
                rlutil::locate(15,17);
                cout<<"NO HUBO IGUALES :("<<endl;
             }


        dados_para_jugar -= contador_de_bloqueados; // Restamos los dados bloqueados
        puntaje_ronda += sumar_tirada; // Sumamos el puntaje de la tirada al total

        rlutil::locate(15,16);
        cout << "PUNTAJE DE LA TIRADA: " << sumar_tirada <<endl;
        rlutil::locate(15,19);
        cout << "PUNTAJE TOTAL DE LA RONDA: " << puntaje_ronda <<endl;
        rlutil::locate(15,18);
        cout << "DADOS RESTANTES: " << dados_para_jugar << "\n";

        if (dados_para_jugar > 0) {
                rlutil::locate(25,25);
                rlutil::setColor(14);
            cout << "QUERES SEGUIR JUGANDO? (1 = SI, 2 = NO): ";
            cin >> respuesta;
            rlutil::cls();

            if (respuesta != 1) {
                seguir_jugando = false;
                rlutil::cls();
                rlutil::locate(25,15);
                rlutil::setColor(14);
                cout << "BUENA DECISION! TERMINASTE LA RONDA CON UN PUNTAJE DE: " << puntaje_ronda <<endl;
            }
        } else {
            rlutil::cls();
            rlutil::locate(25,17);
            rlutil::setColor(14);
            cout << "¡TE QUEDASTE SIN DADOS! FIN DE LA RONDA."<<endl;
            puntaje_ronda=0;
        }

        tirada_actual++;
    }

}

/// CALCULAR PUNTAJE DE LA RONDA
int calcular_puntaje_ronda(std::string &nombre ) {
                 int bloqueador_jugador1_1=tirar_dados();
                 int bloqueador_jugador1_2=tirar_dados();
                 int dados_para_jugar = 5; // Dados disponibles para jugar
                int puntaje_ronda = 0; // Acumula el puntaje de la ronda

    controlador_ronda (dados_para_jugar, bloqueador_jugador1_1, bloqueador_jugador1_2 , puntaje_ronda );

                return puntaje_ronda;

}

/// FUNCION M O D O UN JUGADOR

void modo_unjugador (string &nombre_mejor_jugador, int &puntaje_maximo)
 {
    //system ("cls");
    /// PIDO EL NOMBRE
rlutil::locate(39,10);
string nombre_1;
nombre_1=pedir_nombre();
system ("cls");
///INICIAMOS LA VARIABLE EN CERO DONDE  GUARDAMOS EL PUNTAJE
int puntaje_total_1=0;
rlutil::locate(39,12);
///EMPEZAMOS LAS RONDAS EN EL FOR
int i=0;
for (i=0;i<3;i++) {
/// ARRANCO LA RONDA
     rlutil::locate(15,3);
     rlutil::setColor(14);
     cout<<"===RONDA ===> "<<i+1<<endl;


     rlutil::locate(15,4);///UBICO EN PANTALLA
     rlutil::setColor(14); /// PARA DARLE EL COLOR AL NOMBRE DEL JUGADOR
     cout<<"===JUGADOR : "<<nombre_1<<endl;///MUESTRO EL NOMBRE DEL 1

     rlutil::locate(1,3);///UBICO EN PANTALLA
     rlutil::setColor(10); /// PARA DARLE EL COLOR AL NOMBRE DEL JUGADOR

     /// CALCULO EL PUNTAJE JUGADOR 1
     int puntaje_ronda_1=0;
      rlutil::locate(30,14);///UBICO EN PANTALLA
      puntaje_ronda_1=calcular_puntaje_ronda (nombre_1);
      puntaje_total_1=puntaje_total_1+puntaje_ronda_1;
       rlutil::locate(25,16);
      cout<<"RONDA NUMERO===> "<<i+1<<endl;
      rlutil::locate(25,17);
     cout<<"JUGADOR: "<<nombre_1<<endl;
     rlutil::locate(25,18);
     cout<<"PUNTAJE ACUMULADO : "<<puntaje_total_1<<endl;


      rlutil::locate(30,35);///UBICO EN PANTALLA
      system ("pause");
      system("cls");
}  /// SALGO DEL FOR
     system("cls");
      rlutil::locate(30,10);///UBICO EN PANTALLA
     cout<<"EL PUNTAJE FINAL DE: "<<nombre_1<<" ES: "<<puntaje_total_1<<endl;
        rlutil::locate(1,38);///UBICO EN PANTALLA
         /// actualizo para estadisticas

     if (puntaje_total_1>puntaje_maximo) {
        puntaje_maximo=puntaje_total_1;
        nombre_mejor_jugador=nombre_1;
     }
     agradecimiento();
     system ("pause");
     system("cls");
}


///        M O D  O   2     J U G A D O R E S
void modo_dosjugadores(string &nombre_mejor_jugador, int &puntaje_maximo ) {
    rlutil::locate(38,10);


    system ("cls");
    /// PEDIMOS LOS NOMBRES
rlutil::locate(39,10);
string nombre_1;

//PIDE NOMBRE JUGADOR 1
nombre_1=pedir_nombre();

rlutil::locate(39,11);
string nombre_2;

//PIDENOMBRE JUGADOR 2
nombre_2=pedir_nombre();
rlutil::cls();  /// BORRO  PANTALLA


///INICIAMOS LA VARIABLE EN CERO DONDE NOS VAMOS A GUARDAR LOS PUNTAJES  TOTALES DE LOS DOS
int puntaje_total_1=0;
int puntaje_total_2=0;


///EMPEZAMOS LAS RONDAS EN EL FOR METO A LOS DOS JUGADORES
int i=0;
for (i=0;i<3;i++) {
/// ARRANCO LA RONDA PARA EL JUGADOR 1
     rlutil::locate(15,3);
     rlutil::setColor(14);

     cout<<"===RONDA ===> "<<i+1<<endl;


     rlutil::locate(15,4);///UBICO EN PANTALLA
     rlutil::setColor(14); /// PARA DARLE EL COLOR AL NOMBRE DEL JUGADOR

     cout<<"===JUGADOR 1: "<<nombre_1<<endl;///MUESTRO EL NOMBRE DEL 1

     rlutil::locate(1,3);///UBICO EN PANTALLA
     rlutil::setColor(10); /// PARA DARLE EL COLOR AL NOMBRE DEL JUGADOR

     /// CALCULO EL PUNTAJE JUGADOR 1
     int puntaje_ronda_1= 0;

      rlutil::locate(30,14);///UBICO EN PANTALLA

      puntaje_ronda_1=calcular_puntaje_ronda (nombre_1);
      puntaje_total_1=puntaje_total_1+puntaje_ronda_1;


       rlutil::locate(25,16);
      cout<<"RONDA NUMERO===> "<<i+1<<endl;
      rlutil::locate(25,17);
     cout<<"JUGADOR: "<<nombre_1<<endl;
     rlutil::locate(25,18);
     cout<<"PUNTAJE ACUMULADO : "<<puntaje_total_1<<endl;


      rlutil::locate(30,35);///UBICO EN PANTALLA
      system ("pause");
      system("cls");

      /// CALCULO EL PUNTAJE JUGADOR 2
       rlutil::locate(15,3);
     rlutil::setColor(14);

     cout<<"= = = RONDA ===> "<<i+1<<endl;

     rlutil::locate(15,4);///UBICO EN PANTALLA
     rlutil::setColor(14); /// PARA DARLE EL COLOR AL NOMBRE DEL JUGADOR

     cout<<"= = =JUGADOR 2: "<<nombre_2<<endl;
     rlutil::locate(30,23);///UBICO EN PANTALLA

      int puntaje_ronda_2=0;
      rlutil::locate(30,14);///UBICO EN PANTALLA

     puntaje_ronda_2=calcular_puntaje_ronda (nombre_2);
     puntaje_total_2=puntaje_total_2+puntaje_ronda_2;


      rlutil::locate(25,16);
      cout<<"RONDA NUMERO===> "<<i+1<<endl;
      rlutil::locate(25,17);
     cout<<"JUGADOR: "<<nombre_2<<endl;
     rlutil::locate(25,18);
     cout<<"PUNTAJE ACUMULADO : "<<puntaje_total_2<<endl;

      rlutil::locate(30,35);///UBICO EN PANTALLA
      system ("pause");
      system("cls");

}  /// SALGO DEL FOR
     system("cls");
     rlutil::locate(30,10);///UBICO EN PANTALLA
     cout<<"EL PUNTAJE FINAL DE: "<<nombre_1<<" ES: "<<puntaje_total_1<<endl;
     rlutil::locate(30,11);///UBICO EN PANTALLA
     cout<<"EL PUNTAJE FINAL DE: "<<nombre_2<<" ES: "<<puntaje_total_2<<endl;


     /// BUSCO EL MAYOR PARA VER QUIEN GANO
     rlutil::locate(30,13);///UBICO EN PANTALLA

     if (puntaje_total_1 > puntaje_total_2) {
        cout<<"EL GANADOR ES: "<<nombre_1<<endl;
     }
     else if (puntaje_total_2 > puntaje_total_1) {
        cout<<"EL GANADOR ES: "<<nombre_2;
     }
     else {
        cout<<" E M P A T A R O N  :( "<<endl;
     }

     /// actualizo para estadisticas

     if (puntaje_total_1>puntaje_maximo) {
        puntaje_maximo=puntaje_total_1;
        nombre_mejor_jugador=nombre_1;
     }
     if (puntaje_total_2>puntaje_maximo) {
        puntaje_maximo=puntaje_total_2;
        nombre_mejor_jugador=nombre_2;
     }

     rlutil::locate(1,38); ///UBICO EN PANTALLA
     system ("pause");
     system("cls");

}
/// AGRADECIMIENTO TITILA EL GRACIAS
 void agradecimiento ()
      {
      for (int i=0;i<8;i++) {
         rlutil::cls();

        if (i%2==0)
        {
             rlutil::locate(30,13);///UBICO EN PANTALLA
                rlutil::setColor(11);
            cout<<"GRACIAS POR JUGAR CON NUESTRO JUEGO :)"<<endl;

        }
        rlutil::msleep(800); // la pausa final
      }

     rlutil::anykey();
      }

      /// FUNCION SON IGUALES

      bool soniguales ( int dados[], int cantidad, int bloqueador1, int bloqueador2)
      {
            int primer_dado_valido= -1;
           for ( int i=0;i<cantidad;i++) {
                ///busco el primer dado que no este bloqueado
           if (dados[i] == bloqueador1  ||  dados[i]  == bloqueador2)
                {
            continue ;
           }
           if ( (primer_dado_valido==-1) && (cantidad>1) ){
            primer_dado_valido=dados[i] ;
           }
           if  (dados[i]  != primer_dado_valido) {
                return false ;
                }
              }

                return true;
              }

