#pragma once
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <ctime> 

using namespace std;

template <class T>
class order2 {
public:
	virtual bool comp_f(T first, T second) { return 0; };
	
	void swap_poli(T *value_1, T *value_2) {
		T  temp;
		temp = *value_1;
		*value_1 = *value_2;
		*value_2 = temp;
	}
	void selection_puntero(T *lista_elementos, int longitud) {
		unsigned t0, t1;
		t0 = clock();
		T *temp;
		for (int i = 0; i < longitud - 1; i++) {
			temp = &lista_elementos[i];
			for (int j = i + 1; j < longitud; j++) {
				if (comp_f(*temp, lista_elementos[j]))
					temp = &lista_elementos[j];
			}
			swap_poli(&lista_elementos[i], temp);
		}
		t1 = clock();
		double time = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << "Tiempo de ejecucion: " << time << endl;
		//print_selection(lista_elementos, longitud);
	}
	void print_selection(T *arreglo, int longitud) {
		for (int i = 0; i < longitud; i++) {
			cout << arreglo[i] << ",";
		}
	}
};
template<class T>
class order_asc2 :public order2<T> {
public:
	virtual bool comp_f(T first, T second) {
		if (first>second)
			return true;
		return false;
	}
};

template<class T>
class order_desc2 :public order2<T>{
public:
	virtual bool comp_f(T first, T second) {
		if (first<second)
			return true;
		return false;
	}
};