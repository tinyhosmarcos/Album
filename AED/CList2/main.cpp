#include <iostream>
#include "CList.h"
using namespace std;

int main(){
	
	CList<int> test(5);
	cout << test.Head->get_value() << endl;

	cout << ".." << endl;
	test.insert(8);
	cout << test.Head->get_value() << endl;
	cout << test.Head->next->get_value() << endl;

	cout << ".." << endl;
	test.insert(3);
	cout << test.Head->get_value() << endl;
	cout << test.Head->next->get_value() << endl;
	cout << test.Head->next->next->get_value() << endl;

	cout << ".." << endl;
	test.insert(4);
	cout << test.Head->get_value() << endl;
	cout << test.Head->next->get_value() << endl;
	cout << test.Head->next->next->get_value() << endl;
	cout << test.Head->next->next->next->get_value() << endl;

	cout << ".." << endl;
	test.insert(7);
	cout << test.Head->get_value() << endl;
	cout << test.Head->next->get_value() << endl;
	cout << test.Head->next->next->get_value() << endl;
	cout << test.Head->next->next->next->get_value() << endl;
	cout << test.Head->next->next->next->next->get_value() << endl;

	cout << ".." << endl;
	test.remove(3);
	test.remove(5);
	test.remove(8);
	
	cout << test.Head->get_value() << endl;
	cout << test.Head->next->get_value() << endl;

	
	cout << "Hello World"<<endl;
	char asd;
	cin >> asd;
	
	return 0;

}