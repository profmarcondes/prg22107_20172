//============================================================================
// Name        : FirstTemplate.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<typename T>
class MyClass {
	T _attribute;

public:
	void setAttribute(T param) { _attribute = param; }
	T getAttribute() { return _attribute; }
};

int main() {
	MyClass<int> obj;

	obj.setAttribute(10);
	cout << "Valor = " << obj.getAttribute() << endl; // prints !!!Hello World!!!
	return 0;
}
