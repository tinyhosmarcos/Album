#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <ctime> 

using namespace std;

template <typename T>
void swap(T *first, T *second) {
	T temp;
	temp = *first;
	*first = *second;
	*second = temp;
}
template <typename T>
bool comp_asc(T *first, T *second){
	if(*first>*second)
		return true;
	return false;
}
template<typename T>
bool comp_desc(T *first, T *second){
	if(*first<*second)
		return true;
	return false;
}
template <typename T>
void print_selection(T *arreglo,int longitud) {
	for (int i = 0; i < longitud; i++) {
		cout << arreglo[i] << ",";
	}
}
template <typename T>
void selection(T *arreglo, int longitud,bool (*comp_f)(T*,T*) ){
	unsigned t0, t1;
	t0=clock();
	T *temp;
		for (int i = 0; i < longitud - 1; i++) {
			temp = &arreglo[i];
			for (int j = i + 1; j < longitud; j++) {
				//if (*temp > arreglo[j]) {
				if(comp_f(temp,&arreglo[j])){
				temp = &arreglo[j];
				}
			}
			swap(&arreglo[i], temp);
		}
	t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Execution Time: " << time << endl;
	//print_selection(arreglo,longitud);

}

template <typename T>
class order2{
public:
	T *b;
	int longitud;
	virtual bool comp_f(T *first, T *second){return 0;};
	void swap(T *first, T *second) {
		T temp;
		temp = *first;
		*first = *second;
		*second = temp;
	}
	void selection(T *arreglo, int longitud){
		T *temp;
		unsigned t0, t1;
		t0=clock();
		for (int i = 0; i < longitud - 1; i++) {
			temp = &arreglo[i];
			for (int j = i + 1; j < longitud; j++) {
				//if (*temp > arreglo[j]) {
				if(comp_f(temp,&arreglo[j])){
					temp = &arreglo[j];
				}
			}
			swap(&arreglo[i], temp);
		}
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Execution Time: " << time << endl;
	}
	void print_selection(T *arreglo,int longitud) {
		for (int i = 0; i < longitud; i++) {
			cout << arreglo[i] << ",";
		}
	}
};
template<typename T>
class order_asc2:public order2<T>{
public:
	virtual bool comp_f(T *first, T *second){
		if(*first>*second)
			return true;
		return false;
	}
};

template<typename T>
class order_desc2:public order2<T>{
public:
	virtual bool comp_f(T *first, T *second){
		if(*first<*second)
			return true;
		return false;
	}
};

template <class T>
class order_asc3{
public:
	inline bool operator()(T a, T b){
		return a>b;
	}
};
template <class T>
class order_desc3{
	inline bool operator()(T a,T b){
		return a<b;
	}
};

template <template<class> class Fabrizio,class T>

class ordenar{
public:
	Fabrizio<T> la_wea;
	void swap(T *first, T *second) {
		T temp;
		temp = *first;
		*first = *second;
		*second = temp;
	}
	void selection(T *arreglo, int longitud){
		T *temp;
		unsigned t0, t1;
		t0=clock();
		for (int i = 0; i < longitud - 1; i++) {
			temp = &arreglo[i];
			for (int j = i + 1; j < longitud; j++) {
				//if (*temp > arreglo[j]) {
				if(la_wea(*temp,arreglo[j])){
					temp = &arreglo[j];
				}
			}
			swap(&arreglo[i], temp);
		}
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Execution Time: " << time << endl;
		//print_selection(arreglo,longitud);
		char asd;
		cin>>asd;
	}
	void print_selection(T *arreglo,int longitud) {
		for (int i = 0; i < longitud; i++) {
			cout << arreglo[i] << ",";
		}
	}
	
};
int main() {
	int b[] = { 7,8,6,4,3,2,1 };
	int *c,*d,*f;
	int longitud=100000
		;
	srand(time(NULL));
	c=new int[longitud];
	d=new int[longitud];
	f=new int[longitud];
	for(int i=0;i<longitud;i++){
		c[i]=rand()%longitud-1;
		d[i]=c[i];
		f[i]=c[i];
	}
	//c[longitud]=d[longitud]=f[longitud]='\0';
	selection(c, longitud,&comp_asc);
	//selection(b,7,&comp_asc);
	//print_selection(c, longitud);
	
	cout<<endl;
	
	order_asc2<int> A;
	A.b=d;
	A.selection(d,longitud);
	//A.print_selection(d,longitud);
	
	cout<<endl;
	ordenar<order_asc3,int>  B;
	B.selection(f,longitud);
	int ds;
	cin >> ds;
	return 0;
}
