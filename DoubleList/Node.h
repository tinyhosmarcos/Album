#pragma once
template <class T>
class CNode
{
private:
	T value;
public:
	CNode<T> *m_nodes[2];
	CNode(T _value);
	T get_value();
	void set_value(T _value);
	
	~CNode();
};

