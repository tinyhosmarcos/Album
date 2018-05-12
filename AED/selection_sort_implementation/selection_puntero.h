#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;

template <class T>
void swap_puntero(T *value_1, T *value_2) {
	T  temp;
	temp = *value_1;
	*value_1 = *value_2;
	*value_2 = temp;
}
template <class T>
bool comp_asc_puntero(T first, T second){
	return (first > second);
}
template <class T>
bool comp_desc_puntero(T first, T second) {
	return (first < second);
}
template <class T>
void print_selection(T *arreglo, int longitud) {
	for (int i = 0; i < longitud; i++) {
		cout << arreglo[i] << ",";
	}
}
template <class T>
void selection_puntero(T *lista_elementos, int longitud, bool(*comp_f)(T, T)) {
	unsigned t0, t1;
	t0 = clock();
	T *temp;
	for (int i = 0; i < longitud-1; i++) {
		temp = &lista_elementos[i];
		for (int j = i+1; j < longitud; j++) {
			if (comp_f(*temp, lista_elementos[j]))
				temp = &lista_elementos[j];
		}
		swap_puntero(&lista_elementos[i], temp);
	}
	t1 = clock();
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "Tiempo de ejecucion: " << time << endl;
//	print_selection(lista_elementos, longitud);
}
