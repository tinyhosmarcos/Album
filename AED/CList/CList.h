#pragma once
#include "CNode.h"
#include <iostream>


template <class T>

class CList {
private:
	CNode<T> *Head;
	CNode<T> *Tail;
public:
	CList(T _value);
	bool insert(T _value);
	//bool remove(T _value);
	bool find(T _value, CNode<T>** iterator);

};