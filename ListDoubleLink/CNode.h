#pragma once

template <class T>
class CNode {
private:
	T value;
public:
	CNode(T _value);
	~CNode();
	CNode<T> *m_nodes[2];
	T get_value();
	void set_value(T _value);
};
