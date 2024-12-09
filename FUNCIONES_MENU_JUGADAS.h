#pragma once

#include <string>
using namespace std;
string pedir_nombre_1();
string pedir_nombre_2();

// funcion para mostrar el menu
int menu_greed (int opcion ) ;

///PEDIR NOMBRE
string pedir_nombre();

///TIRAR DADOS
 int tirar_dados ();

///FUNCION PARA ELIJA OPCIONES
// void seleccion_Opcion ( );

/// MOSTRAR ESTADISTICAS
void mostrar_estadisticas( string &nombre_mejor_jugador, int &puntaje_maximo ) ;

///FUNCIONES CON RLUTIL
 void Limpiar_menu();
 void Dibujar_menu(int y);
 void Dibujar_titulo();

 /// MOSTRAR  CREDITOS
 void creditos();

  /// AGRADECIMIENTO
 void agradecimiento () ;
