#include <iostream>
#include "funciones.h"
using namespace std;



int main() {
	int menu = 0;
	int value=552;
	lista<int> Jugador;
	Avl<int> avl_camiseta;
	insertar_jugadores(Jugador);
	//jugador.insert(0, 9, "ollachica", "Defensa", 19, "Peru");
	Jugador.index = Jugador.head;
	nodo<int> *&index = Jugador.index;
	while (index != nullptr){
		avl_camiseta.add(index->numero_camiseta, index);
		index = index->next;
	}
	Node<int> **funciona;
	avl_camiseta.find(9, funciona);
	string buscar;
	Jugador.index = Jugador.head;
	cout << "   Ingrese 0. si quiere ingresar un jugador manualmente" << endl;
	cout << "   Ingrese 1. si quiere borrar algun jugador" << endl;
	cout << "   Ingrese 2. si quiere imprimir todos los jugadores" << endl;
	cout << "   Ingrese 3. si quiere buscar una seleccion" << endl;
	cout << "   Ingrese 4. si quiere buscar por posicion" << endl;
	cout << "   Ingrese 5. si quiere buscar por rango de edad" << endl;
	cout << "Ingrese su opcion: ";
	cin >> menu;
	while (menu>=0){
		
		if (menu == 0) {
			
			int numero_camiseta;
			string apellido;
			string posicion;
			int edad;
			string seleccion;
			cout << "Ingrese los datos del jugador:" << endl;
			cout << "Numero de camiseta : "; cin >> numero_camiseta;
			cout << "Nombre             : "; cin >> apellido;
			cout << "Posicion           : "; cin >> posicion;
			cout << "Edad               : "; cin >> edad;
			cout << "Seleccion          : "; cin >> seleccion;
			Jugador.insert(++value, numero_camiseta, apellido, posicion, edad, seleccion);
			avl_camiseta.add(Jugador.end->numero_camiseta,Jugador.end);
			apellido.clear();
			posicion.clear();
			seleccion.clear();
		}
		if (menu == 1) {
			cout << "Ingrese el nombre del jugador a borrar: "; cin >> buscar;
			nodo<int>**buscare;
			Jugador.find(buscar, buscare);
			Node<int>**borrara;
			if ((*buscare) != nullptr) {
			avl_camiseta.find((*buscare)->numero_camiseta, borrara);
			cout << (*borrara)->repetidos.head->apellido << endl;
				(*borrara)->repetidos.delete_node(buscar);
				cout << (*borrara)->repetidos.head->apellido << endl;
				Jugador.delete_node(buscar);
				Jugador.index = Jugador.head;
				(*borrara)->repetidos.index = (*borrara)->repetidos.head;
			}
			else{ cout << "valor no existe" << endl; }
			}
		if (menu == 2) {
			while (Jugador.index != nullptr) {
				Jugador.index->imprimir_nodo();
				Jugador.index = Jugador.index->next;
			}
		}
		if (menu == 3) {
			cout << endl << "ingrese la seleccion a buscar: ";
			cin >> buscar;
			avl_camiseta.InSeleccion(avl_camiseta.root, buscar);
			buscar.clear();
		}
		if (menu == 4) {
			cout << endl << "ingrese la posicion a buscar: ";
			cin >> buscar;
			avl_camiseta.InPosicion(avl_camiseta.root,buscar);
			buscar.clear();
		}
		if (menu == 5) {
			int primer_rango, segundo_rango;
			cout << endl << "Ingrese el primer rango de edad: "; 
			cin >> primer_rango;
			cout << endl << "Ingrese el segundo rando de edad: ";
			cin >> segundo_rango;
			avl_camiseta.InRange(avl_camiseta.root, primer_rango, segundo_rango);
		}
		cout << "desea seguir? " << endl;
		cout << "   Ingrese 0. si quiere ingresar un jugador manualmente" << endl;
		cout << "   Ingrese 1. si quiere borrar algun jugador" << endl;
		cout << "   Ingrese 2. si quiere imprimir todos los jugadores" << endl;
		cout << "   Ingrese 3. si quiere buscar una seleccion" << endl;
		cout << "   Ingrese 4. si quiere buscar por posicion" << endl;
		cout << "   Ingrese 5. si quiere buscar por rango de edad" << endl;
		cin >> menu;

	}
	
	//system("PAUSE");
	//Jugador.print();
	char basura;
	cin >> basura;
}