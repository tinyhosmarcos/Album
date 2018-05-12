#pragma once
#include <iostream>
#include "avl.h"
#include "avl_test.h"
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void insertar_jugadores(lista<int>&Jugador) {
	string numero;
	string apellido;
	string posicion;
	string edad;
	string seleccion;
	int counter = 0;
	char str[] = "datos_jugadores.txt";
	ifstream is(str);
	string temp;
	for (int i = 0; i < 23 * 24; i++) {
		getline(is, numero);
		getline(is, apellido);
		getline(is, posicion);
		getline(is, edad);
		getline(is, seleccion);
		Jugador.insert(counter, stoi(numero), apellido, posicion, stoi(edad), seleccion);
		numero.clear();
		apellido.clear();
		posicion.clear();
		edad.clear();
		seleccion.clear();
		counter++;
	}
	is.close();
}