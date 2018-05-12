#pragma once

#include "CNode.h"
#include <iostream>
using namespace std;
template <class T>
class CList {
public:
	CNode<T> *head;
	CNode<T> *tail;
	CList();
	bool find(T value, CNode<T> *&next_nodo);
	bool insert(T value);
	bool deleted(T value);
	T imprimir(T value);
};

