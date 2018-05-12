#include "CList.h"
template<class T>
CList<T>::CList(){
	head = tail = nullptr;
};

template<class T>
bool CList<T>::find(T value, CNode<T>*& next_nodo) {
	bool condition = true;
	next_nodo = head;
	while (next_nodo && (next_nodo->get_value()<value)){
		if (next_nodo == tail) {
			break;
		}
		next_nodo = next_nodo->m_nodes[1];
	}
	if(next_nodo && next_nodo->get_value()>value)  next_nodo = next_nodo->m_nodes[0];
	return next_nodo && (next_nodo->get_value() == value);

};
template<class T>
bool CList<T>::insert(T value) {
	CNode<T> *p;
	if (find(value, p))return 0;
	CNode<T>*temp = new CNode<T>(value);
	temp->m_nodes[0] = p;
	if (p) {
		temp->m_nodes[1] = p->m_nodes[1];
		p->m_nodes[1]->m_nodes[0] = temp;
		p->m_nodes[1] = temp;
		if (temp->m_nodes[1] == head) tail = temp;
	}
	else {
		head = temp;
		tail = temp;
		head->m_nodes[0] = temp;
		head->m_nodes[1] = temp;
	}
	return 1;
};

template <class T>
bool CList<T>::deleted(T value){
	CNode<T> *p;
	if(!find(value, p)) return 0;
	
	if (p == head) {
		head = p->m_nodes[1];
		head->m_nodes[0] = tail;
		tail->m_nodes[1] = head;
	}
	if(p==tail){
		tail = p->m_nodes[0];
		tail->m_nodes[1] = head;
		head->m_nodes[0] = tail;
	}
	p->m_nodes[0]->m_nodes[1] = p->m_nodes[1];
	p->m_nodes[1]->m_nodes[0] = p->m_nodes[0];
	delete p;
	return 1;
}
template <class T>
T CList<T>::imprimir(T value) {
	CNode<T> *p;
	if (!find(value, p)) return 0;
	return p->get_value();
}