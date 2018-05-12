#pragma once

template <class T>
class CNode{
public:
	CNode(T _value);
	CNode<T> *next;
	T get_value();
	//~CNode();

private:
	T value;
};
template <class T>
CNode<T>::CNode(T _value){
	value = _value;
	next = nullptr;
};

template <class T>
T CNode<T>::get_value(){
	return value;
};

