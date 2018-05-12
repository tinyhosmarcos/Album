#include <iostream>
#include "CNode.cpp"
#include "CList.cpp"

using namespace std;

void josephus(int n, int k) {
	CList<int> Soldiers;
	int counter_die;
	for (int i = 1; i <= n; i++)
		Soldiers.insert(i);
	CNode<int> *Die = Soldiers.head;
	while (Soldiers.head != Soldiers.tail) {
		
		for (int i = 1; i < k; i++) {
			Die=Die->m_nodes[1];
		}
		counter_die = Die->get_value();
		cout << counter_die<<"<-Counter_die" << endl;
		Die = Die->m_nodes[1];
		Soldiers.deleted(counter_die);
	}
	cout << endl << "El salvado es: " << endl;
	cout << Soldiers.head->get_value() << endl;
}

int main() {
	int n,k;
	n = k = 0;
	while (n != -1) {
		cout << "Ingrese el numero de soldados: ";
		cin >> n;
		cout << endl << "Ingrese el numero de saltos de muerte: ";
		cin >> k;
		cout << endl;
		josephus(n, k);
	}

	josephus(21, 3);


	char asd;
	cin >> asd;
	return 0;

}
