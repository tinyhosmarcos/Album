#pragma once
#include <string>
#include <iostream>

using namespace std;

template<class T>
class nodo {
public:
	T value;
	int numero_camiseta;
	string apellido;
	string posicion;
	int edad;
	string seleccion;
	nodo *next;
	nodo() {
		next = nullptr;
	}
	nodo(T _value, int _numero, string _apellido, string _posicion,int _edad, string _seleccion) {
		numero_camiseta = _numero;
		apellido += _apellido;
		posicion += _posicion;
		edad = _edad;
		seleccion += _seleccion;
		this->value = _value;
		next = nullptr;
	}

	nodo(nodo <T>&copia) {
		value = *copia->get_value();
		next = *copia->next;
	}

	void imprimir_nodo() {
		cout << endl;
		cout <<"Numero de Camiseta: "<<numero_camiseta<<endl;
		cout <<"Nombre            : "<<apellido << endl;
		cout <<"Posicion          : "<< posicion << endl;
		cout <<"Edad              : "<< edad << endl;
		cout <<"Seleccion         : "<<seleccion <<endl<<" - "<< endl;
	}

	T get_value() { return value; }
	void set_value(T _value) { value = _value; }


};

template<class T>
class lista {
public:
	nodo<T>*head;
	nodo<T>*end;
	nodo<T>*index;
	lista() {
		index = end = nullptr;
	}
	lista(T value) {
		head = new nodo<T>(value);
		index = end = head;
	}
	void get_head(nodo<T> **&copy) { copy = &head; }
	bool insert(T value, int _numero, string _apellido, string _posicion, int _edad, string _seleccion) {
		nodo<T> **p;
		if (find(_apellido, p)) return 0;
		nodo<T> *temp = new nodo<T>(value, _numero, _apellido, _posicion, _edad, _seleccion);
		temp->next = *p;
		*p = &(*temp);
		index = head;
		end = *p;
		return 1;

	}
	bool delete_node(string _nombre) {
		nodo<T> **p;
		if (!find(_nombre, p))return 0;
		*p = (**p).next;
		return 1;
	}

	bool find(string nombre, nodo<T> **&next_nodo) {
		next_nodo = &head;
		while ((*next_nodo) && ((**next_nodo).apellido!=nombre)) {
			next_nodo = &(**next_nodo).next;
		}

		return(*next_nodo && ((**next_nodo).apellido == nombre));/*
																   for (next_nodo = &head; *next_nodo && *(next_nodo).get_value() < value; *next_nodo = *next_nodo->next);
																   return *next_nodo && (*next_nodo)->get_value() = value;
																   */
	}
	void print() {
		index = head;
		while ((index)!=nullptr) {
			cout << index->value <<"-";
			cout << index->numero_camiseta <<"-";
			cout << index->apellido<<"-";
			cout << index->edad << "-";
			cout << index->posicion<< "-";
			cout << index->seleccion<<"-";
			index=index->next;
			cout << endl;
		}
		std::cout << std::endl;
	}

};
