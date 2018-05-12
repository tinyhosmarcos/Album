#include "CNode.h"
template <class T>
T CNode<T>::get_value() {
	return value;
};

template <class T>
void CNode<T>::set_value(T _value){
	value = _value;
}
