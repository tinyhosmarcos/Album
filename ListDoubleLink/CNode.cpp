#include "CNode.h"

template<class T>
CNode<T>::CNode(T _value){
	this->value = _value;
}

template<class T>
CNode<T>::~CNode()
{
	m_nodes[0] = m_nodes[1] = 0;
	value = -1;
}

template<class T>
T CNode<T>::get_value(){
	return value;
};
template<class T>
void CNode<T>::set_value(T _value){
	value = _value;
};
