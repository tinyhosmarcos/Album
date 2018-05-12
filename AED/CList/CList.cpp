#include "CList.h"

template <class T>

CList<T>::CList(T _value){
	insert(_value);
};

template <class T>

bool CList<T>::insert(T _value){
	CNode<T>** p;
	if (find(_value, p)) return 0;
	
	(*p)->next = new CNode<T>(T _value);

};


template <class T>
bool CList<T>::find(T _value,CNode<T> **iterator){
	for (iterator = &head; *p && (*p)->get_value() != _value; p = &((*p)->next))
		return *iterator != 0;
};