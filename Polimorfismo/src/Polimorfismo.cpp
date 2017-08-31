//============================================================================
// Name        : Polimorfismo.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class A {
public:
	virtual void do_something() = 0;
	virtual ~A() {}
};

class A1: public A {
public:
	void do_something(){
		cout << "A1 is doing something!" << endl;
	}
};

class A2: public A {
public:
	void do_something(){
		cout << "A2 is doing something!" << endl;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl;

	//A obj0;
	A1 obj1;
	A2 obj2;

	//obj0.do_something();
	obj1.do_something();
	obj2.do_something();

	A * ptr;
	//ptr -> &obj0;
	//ptr->do_something();
	ptr = &obj1;
	ptr->do_something();
	ptr = &obj2;
	ptr->do_something();

	return 0;
}
