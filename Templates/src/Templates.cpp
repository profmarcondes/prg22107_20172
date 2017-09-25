//============================================================================
// Name        : Templates.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
using namespace std;

template <int N>
struct Fatorial {
	enum { value = N * Fatorial<N - 1>::value };
};
template <>
struct Fatorial<0>
{
	enum { value = 1 };
};

unsigned int fatorial(unsigned int n){
	if(n == 0){
		return 1;
	} else {
		return n* fatorial(n-1);
	}
}

int main() {
	clock_t a, b;

	a = clock();
	cout << "Fatorial de 5 é " << fatorial(5) << endl;
	a = clock() - a;
	cout << "Executado em " << a << " ciclos (" << ((double)a)/CLOCKS_PER_SEC << " segundos)." << endl;

	b = clock();
	cout << "Fatorial de 5 é " << Fatorial<5>::value << endl;
	b = clock() - b;
	cout << "Executado em " << b << " ciclos (" << ((double)b)/CLOCKS_PER_SEC << " segundos)." << endl;

	cout << "Fatorial metaprogramado é " << a/b << " vezes mais rápido!" << endl;

	return 0;
}
