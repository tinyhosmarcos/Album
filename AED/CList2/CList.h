#pragma once
#include "CNode.h"


template <class T>

class CList {
public:
	CNode<T> *Head=nullptr;
	CNode<T> *Tail=nullptr;
	CList(T _value);
	bool insert(T _value);
	bool remove(T _value);
	bool find(T _value, CNode<T>**& iterator);

};

template <class T>
CList<T>::CList(T _value) {
	insert(_value);
};

template <class T>
bool CList<T>::insert(T _value) {
	CNode<T> **p= &Head;
	if (find(_value, p))return 0;
	CNode<T> *temp = new CNode<T>(_value);
	temp->next = *p;
	*p = temp;

		
};
template <class T>
bool CList<T>::remove(T _value) {
	CNode<T> **p;
	if (!find(_value, p)) return 0;
		*p = (*p)->next;
		return true;
};

template <class T>
bool CList<T>::find(T _value, CNode<T>**&iterator) {
	for (iterator = &Head; *iterator && _value > (*iterator)->get_value(); iterator = &(*iterator)->next) {}
		return ((*iterator) && (*iterator)->get_value()==_value);
};
