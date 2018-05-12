#pragma once
#include <iostream>
using namespace std;

template <class T>
class CNode{
private:
	T value;
public:
	CNode<T> *next;
	CNode<T> (T _value) {
		value = _value;
		next = nullptr;
	};
	T get_value();
	void set_value(T _value);
};
