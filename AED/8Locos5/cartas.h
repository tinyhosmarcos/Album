#pragma once
#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
using namespace std;

template <class T>
struct Card_Node {
	T id;
	int numero;
	string palo;
	Card_Node<T> *m_next;
	Card_Node(T _id, int _numero, string _palo) {
		id = _id;
		numero = _numero;
		palo = _palo;
		m_next = NULL;
	}
};

template <class T>
class Cards_List {
public:
	Card_Node<T> *m_head;
	Card_Node<T> *tail;
	int NumeroDeCartasEnLaLista=0;
	Cards_List() {
		m_head = NULL;
		tail= NULL;
	}

	bool find(T _id, Card_Node<T>**& p) {
		for (
			p = &m_head;
			(*p) && (*p)->id< _id;
			p = &(*p)->m_next
			);
			return !!((*p) && (*p)->id == _id);
	}

	bool Insert(T _id,int _numero,string _palo) {
		Card_Node<T>**p;
		if (find(_id, p))return 0;
		Card_Node<T>*t = new Card_Node<T>(_id,_numero,_palo);
		t->m_next = *p;
		*p = t;
		NumeroDeCartasEnLaLista++;
		return 1;
	}

	bool Remove(T _id) {
		Card_Node<T>**p;
		if (!find(_id, p))return 0;
		Card_Node<T>*temp = *p;
		*p = temp->m_next;
		delete temp;
		NumeroDeCartasEnLaLista--;
		return 1;
	}

	void Print() {
		Card_Node<T>**p;
		p = &m_head;
		cout << "--> ---IDs---||---Numero---||---Palo---"<<endl;
		cout << " --> ";
		while (*p != nullptr) {
			cout << " ID:(" << (*p)->id << ") ---> ";
			if((*p)->numero==1) cout << 'A' << " ---  " << (*p)->palo << endl;
			else if ((*p)->numero == 11) cout << 'J' << " ---  " << (*p)->palo << endl;
			else if ((*p)->numero == 12) cout << 'Q' << " ---  " << (*p)->palo << endl;
			else if ((*p)->numero == 13) cout << 'K' << " ---  " << (*p)->palo << endl;
			else{ cout << (*p)->numero << " ---  " << (*p)->palo << endl; }
			p = &(*p)->m_next;
			cout << " --> ";
		}
		cout << " // " << endl;
	}
	void Print_palo(string _palo) {
		Card_Node<T>**p;
		p = &m_head;
		while (*p != nullptr) {
			if ((*p)->palo == _palo) {
				cout << (*p)->numero;
				cout << " --> ";
			}
			p = &(*p)->m_next;
			
		}
		cout << " // " << endl;
	
	}
	void CrearCartas() {
		int comp = 0;
		int a = 0;
		for (int i =0; i< 52; i++) {
			if (a == i % 13) comp++;
			if (comp == 1)Insert(i + 1, (i % 13) + 1, "Trebol");
			if (comp == 2)Insert(i + 1, (i % 13) + 1, "Corazon");
			if (comp == 3)Insert(i + 1, (i % 13) + 1, "Espada");
			if (comp == 4)Insert(i + 1, (i % 13) + 1, "Coco");
		}
	}
	void Barajear() {
		Card_Node<T> **p;
		Card_Node<T> **iterador = &m_head;
		string temp_palo;
		int temp_numero;
		srand(time(NULL));
		int num;
		for (int i = 0; i < 52; i++){
			num = 1 + rand() % (53 - 1);
			find(num, p);
			temp_numero = (*iterador)->numero;
			temp_palo = (*iterador)->palo;
			(*iterador)->numero = (*p)->numero;
			(*iterador)->palo = (*p)->palo;
			(*p)->numero = temp_numero;
			(*p)->palo = temp_palo;
		}

	}

	void PrintNumeroDeCartas() {
		cout << "Numero de Cartas : " <<NumeroDeCartasEnLaLista<< endl;
	}

	~Cards_List() {
		Card_Node<T> **p = &m_head;
		Card_Node<T> *temp;
		while (*p) {
			temp = *p;
			*p = (*p)->m_next;
			delete temp;
		}
	}

};
