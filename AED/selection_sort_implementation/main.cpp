#include "selection_puntero.h"
#include "polimorfismo.h"
#include "functor.h"

int main(){
	int longitud;
	cout << "Ingrese su longitud: ";
	cin >> longitud; cout << endl;
	int option;
	int *array_puntero = new int[longitud];
	int *array_functor = new int[longitud];
	for (int i = 0; i < longitud; i++) {
		*(array_puntero + i) = rand() % (longitud - 1);
		*(array_functor + i) = *(array_puntero + i);
	}

	cout << "Ingrese su opcion";
	cin >> option;
	Ordenar<order_asc<int>, int> test_functor;
	order_asc2<int> test_poli;

	test_functor.selection_functor(array_puntero, longitud);
	cout << endl << "termino" << endl;
	
	selection_puntero(array_functor, longitud, &comp_asc_puntero);
	
	cout << endl << "termino" << endl;

	//print_selection(array_puntero, longitud);
	char garbage;
	cin >> garbage;
}