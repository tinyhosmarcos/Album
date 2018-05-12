#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;

template <class T>
class order_asc{
public:
	inline bool operator()(int a, int b){
		if (a > b) return true;
		return false;
	}
};

template <class T>
class order_desc {
public:
	inline bool operator()(int a, int b){
		if (a <b) return true;
		return false;
	}
};

template <class Orden, class T>
class Ordenar {
public:
	Orden comp_f;
	void swap_functor(int *value_1, int *value_2) {
		int  temp;
		temp = *value_1;
		*value_1 = *value_2;
		*value_2 = temp;
	}
	void selection_functor(int *lista_elementos, int longitud) {
		unsigned t0, t1;
		t0 = clock();
		T *temp;
		for (int i = 0; i < longitud - 1; i++) {
			temp = &lista_elementos[i];
			for (int j = i + 1; j < longitud; j++) {
				if (*temp > lista_elementos[j])
					temp = &lista_elementos[j];
			}
			swap_functor(&lista_elementos[i], temp);
		}
		t1 = clock();
		double time = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << "Tiempo de ejecucion: " << time << endl;
		//	print_selection(lista_elementos, longitud);
	}

	void print_selection(T *arreglo, int longitud) {
		for (int i = 0; i < longitud; i++) {
			cout << arreglo[i] << ",";
		}
	}
};