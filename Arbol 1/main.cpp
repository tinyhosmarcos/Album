#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
string int_to_String(int num) {
	stringstream convert;
	convert << num;
	return convert.str();
}
template <class T>
struct CLess{
	inline bool op(T a, T b) {
		return a < b;
	}
};
template <class T>
struct CHigher{
	inline bool op(T a, T b) {
		return a > b;
	}
};

template <class T>
class Node{
private:
	T value;
	int order;
public:
	Node<T>* m_nodes[2];
	Node(T _value,int _order) {
		m_nodes[0] = m_nodes[1] = 0;
		value = _value;
		order = _order;
	}
	void set_order(int _order) { order = _order; }
	T get_value() { return value; }
	int get_order() { return order; }
	void set_value(T _value) { value = _value; }
};


template <class T,class C>
class Btree {
public:
	Node<T> *m_root;
	C m_c;
	int nivel_tree = 0;

	Btree() {
		m_root = nullptr;
	}
	bool Find(T _value, Node<T>**&p) {
		int nivel_temp = 0;
		for (p = &m_root; *p && (*p)->get_value() != _value; p = &((*p)->m_nodes[m_c.op((*p)->get_value(), _value)])){
			nivel_temp++;
		}
		if (nivel_temp > nivel_tree) nivel_tree = nivel_temp;
		return *p != 0; //obligar a la no perdida de datos
	}
	
	bool Insert(T _value){
		Node<T>**p;
		if (Find(_value, p))return 0;
		*p = new Node<T>(_value,nivel_tree);
		return 1;
	}
	bool Rep(Node<T> **&p,Node<T> **&q) {
		int temp_order = (*p)->get_order();
		for (q=&(*p)->m_nodes[0]; (*q)->m_nodes[1] != 0; q = &(*q)->m_nodes[1]);
		cout<<(*p)->get_value()<<endl;
		(*p)->set_value((*q)->get_value());
		cout << (*p)->get_value() << endl;

		return !!(*p);
	}
	bool Remove(T _value) {
		Node<T> **p;
		if (!Find(_value, p))return 0;
		if ((*p)->m_nodes[0] && (*p)->m_nodes[1]) {
			Node<T>**q;
			Rep(p, q);
			p = q;
		}
		Node<T> *temp = *p;
		(*p)=(*p)->m_nodes[(*p)->m_nodes[1] != 0];
		delete temp;
		return 1;
		//incompleto hacer analizis
	}
	void InOrder(Node<T>*p,int _order,vector<int> &a) {
		if (!p || p->get_order()==_order || p->get_order() == _order)return;
		InOrder(p->m_nodes[0],_order,a);
		if(p->get_order()==_order-1)
			a.push_back(p->get_value());
		InOrder(p->m_nodes[1],_order,a);
	}
	void imprimir(Node <T>*p) {
		vector<int> glos;
		int space_blink = pow(2, nivel_tree) - 1;
		for (int i = 1; i <= nivel_tree+1; i++) {
			InOrder(m_root, i, glos);
			cout << string(space_blink, '_');
			
			for (vector<int>::iterator it = glos.begin(); it != glos.end(); ++it) {
				cout << *it;
				cout << string((space_blink * 2)+1, '_');
			}
			cout << '\n';
			glos.clear();
			space_blink = (pow(2, nivel_tree - i) - 1);
		}

	}
};

int main() {
	Btree<int, CLess<int>> A;

	A.Insert(7);
	A.Insert(5);
	A.Insert(10);
	A.Insert(3);
	A.Insert(6);
	A.Insert(8);
	A.Insert(11);
	A.Insert(9);
	A.Insert(2);
	//A.Remove(6);
	A.Remove(7);
	vector<int> glos;
	A.imprimir(A.m_root);
	cout << endl << endl;
	Node<int>**p;
	cout<<A.Find(6,p);
	for (std::vector<int>::iterator it = glos.begin(); it !=glos.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//A.imprimir(A.m_root);
	char x;
	cin >> x;
	return 0;
}