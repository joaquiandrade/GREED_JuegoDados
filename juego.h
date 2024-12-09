#pragma once

#include <string>

/// CALCULAR PUNTAJE DE LA RONDA
int calcular_puntaje_ronda(std:: string &nombre);

/// CONTROLAR LA RONDA COMPLETA
void controlador_ronda (int &dados_para_jugar, int bloqueador1, int bloqueador2 , int &puntaje_ronda );

///        M O D  O   2     J U G A D O R E S
void modo_dosjugadores(string &nombre_mejor_jugador, int &puntaje_maximo ) ;

///        M O D  O   1     J U G A D O R
 void modo_unjugador (string &nombre_mejor_jugador, int &puntaje_maximo);

 /// SON IGUALES
 bool soniguales (int dados[], int cantidad, int bloqueador1, int bloqueador2) ;

